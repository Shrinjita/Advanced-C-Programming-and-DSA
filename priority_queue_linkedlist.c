#include <stdio.h>
#include <stdlib.h>

// Define a structure for a node in the linked list
struct Node {
    int data;
    int priority;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data, int priority) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->priority = priority;
    node->next = NULL;
    return node;
}

// Function to insert a node with a given priority into the priority queue
void enqueue(struct Node** front, int data, int priority) {
    struct Node* newNode = createNode(data, priority);

    if (*front == NULL || priority < (*front)->priority) {
        newNode->next = *front;
        *front = newNode;
    } else {
        struct Node* current = *front;
        while (current->next != NULL && current->next->priority <= priority) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

// Function to remove and return the highest priority element from the priority queue
int dequeue(struct Node** front) {
    if (*front == NULL) {
        printf("Priority queue is empty.\n");
        return -1; // Return sentinel value instead of exiting
    }
    struct Node* temp = *front;
    int data = temp->data;
    *front = temp->next;
    free(temp);
    return data;
}

// Function to check if the priority queue is empty
int isEmpty(struct Node* front) {
    return (front == NULL);
}

// Function to display the contents of the priority queue
void display(struct Node* front) {
    if (front == NULL) {
        printf("Priority queue is empty.\n");
        return;
    }

    printf("Priority Queue Contents:\n");
    while (front != NULL) {
        printf("Data: %d, Priority: %d\n", front->data, front->priority);
        front = front->next;
    }
}

// Function to free all nodes before exiting
void freeQueue(struct Node** front) {
    while (!isEmpty(*front)) {
        dequeue(front);
    }
}

int main() {
    struct Node* front = NULL;
    int choice;

    while (1) {
        printf("\nPriority Queue Menu:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                int data, priority;
                printf("Enter data: ");
                scanf("%d", &data);
                printf("Enter priority: ");
                scanf("%d", &priority);
                enqueue(&front, data, priority);
                break;
            }
            case 2: {
                int data = dequeue(&front);
                if (data != -1) {
                    printf("Dequeued element with data %d\n", data);
                }
                break;
            }
            case 3: {
                display(front);
                break;
            }
            case 4: {
                freeQueue(&front);
                exit(0);
            }
            default: {
                printf("Invalid choice. Please try again.\n");
                break;
            }
        }
    }

    return 0;
}
/**
Priority Queue Menu:
1. Enqueue
2. Dequeue
3. Display
4. Exit
Enter your choice: 1
Enter data: 2
Enter priority: 1

Priority Queue Menu:
1. Enqueue
2. Dequeue
3. Display
4. Exit
Enter your choice: 1
Enter data: 3
Enter priority: 1

Priority Queue Menu:
1. Enqueue
2. Dequeue
3. Display
4. Exit
Enter your choice: 1
Enter data: 5
Enter priority: 1

Priority Queue Menu:
1. Enqueue
2. Dequeue
3. Display
4. Exit
Enter your choice: 1
Enter data: 7
Enter priority: 2

Priority Queue Menu:
1. Enqueue
2. Dequeue
3. Display
4. Exit
Enter your choice: 3
Priority Queue Contents:
Data: 2, Priority: 1
Data: 3, Priority: 1
Data: 5, Priority: 1
Data: 7, Priority: 2

Priority Queue Menu:
1. Enqueue
2. Dequeue
3. Display
4. Exit
Enter your choice: 4*/
