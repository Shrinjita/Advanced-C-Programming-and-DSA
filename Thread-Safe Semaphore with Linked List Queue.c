#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Define a structure for a node in the linked list
struct Node {
    pthread_t thread;
    struct Node* next;
};

// Define a structure for the semaphore
struct Semaphore {
    int value;
    struct Node* queue;
};

// Function to create a new node
struct Node* createNode(pthread_t thread) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->thread = thread;
    node->next = NULL;
    return node;
}

// Initialize a semaphore with an initial value
struct Semaphore* createSemaphore(int initial_value) {
    struct Semaphore* sem = (struct Semaphore*)malloc(sizeof(struct Semaphore));
    sem->value = initial_value;
    sem->queue = NULL;
    return sem;
}

// Semaphore wait operation
void wait(struct Semaphore* sem) {
    pthread_t self = pthread_self();
    pthread_mutex_lock(&mutex);

    if (sem->value > 0) {
        sem->value--;
    } else {
        // Block the current thread
        struct Node* newNode = createNode(self);
        if (sem->queue == NULL) {
            sem->queue = newNode;
        } else {
            struct Node* current = sem->queue;
            while (current->next != NULL) {
                current = current->next;
            }
            current->next = newNode;
        }
        pthread_cond_wait(&condition, &mutex); // Wait until signaled
    }

    pthread_mutex_unlock(&mutex);
}

// Semaphore signal operation
void signal(struct Semaphore* sem) {
    pthread_mutex_lock(&mutex);

    if (sem->queue == NULL) {
        sem->value++;
    } else {
        struct Node* front = sem->queue;
        sem->queue = front->next;
        pthread_cond_signal(&condition); // Signal the waiting thread
        free(front);
    }

    pthread_mutex_unlock(&mutex);
}

// Global variables for mutex and condition variable
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t condition = PTHREAD_COND_INITIALIZER;

// Sample thread function
void* threadFunction(void* arg) {
    struct Semaphore* sem = (struct Semaphore*)arg;
    wait(sem);
    printf("Thread %lu acquired the semaphore.\n", pthread_self());
    // Perform some work
    // ...
    signal(sem);
    printf("Thread %lu released the semaphore.\n", pthread_self());
    return NULL;
}

int main() {
    struct Semaphore* semaphore = createSemaphore(2); // Initialize semaphore with a value of 2

    pthread_t threads[5];
    for (int i = 0; i < 5; i++) {
        pthread_create(&threads[i], NULL, threadFunction, semaphore);
    }

    for (int i = 0; i < 5; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}
