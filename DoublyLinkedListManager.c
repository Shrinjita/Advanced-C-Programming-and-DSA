#include <stdio.h>
#include <stdlib.h>

// Define the structure for a doubly linked list node
struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};

// Function to display the elements of the doubly linked list
void displayList(struct Node *head) {
    struct Node *current = head;
    printf("Doubly Linked List Elements: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Function to insert an el at the beginning of the doubly linked list
struct Node* insertBeginning(struct Node *head, int el) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = el;
    newNode->prev = NULL;
    newNode->next = head;

    if (head != NULL) {
        head->prev = newNode;
    }

    return newNode;
}

// Function to insert an el at the end of the doubly linked list
struct Node* insertEnd(struct Node *head, int el) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = el;
    newNode->next = NULL;

    if (head == NULL) {
        newNode->prev = NULL;
        return newNode;
    }

    struct Node *current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
    newNode->prev = current;

    return head;
}

// Function to delete an el from the doubly linked list
struct Node* deleteElement(struct Node *head, int el) {
    struct Node *current = head;
    while (current != NULL && current->data != el) {
        current = current->next;
    }

    if (current == NULL) {
        printf("Element %d not found in the list.\n", el);
        return head;
    }

    if (current->prev != NULL) {
        current->prev->next = current->next;
    } else {
        head = current->next;
    }

    if (current->next != NULL) {
        current->next->prev = current->prev;
    }

    free(current);
    return head;
}
// Function to insert an el at a specified position in the doubly linked list
struct Node* insertMiddle(struct Node *head, int el, int position) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = el;
    
    // Check if the list is empty or if the position is 0 (insert at the beginning)
    if (head == NULL || position <= 0) {
        newNode->prev = NULL;
        newNode->next = head;

        if (head != NULL) {
            head->prev = newNode;
        }

        return newNode;
    }

    // Traverse to the node at the specified position
    struct Node *current = head;
    int currentPosition = 0;
    
    while (currentPosition < position - 1 && current != NULL) {
        current = current->next;
        currentPosition++;
    }

    if (current == NULL) {
        printf("Position %d is out of bounds. Element not inserted.\n", position);
        free(newNode);
        return head;
    }

    // Insert the new node at the specified position
    newNode->prev = current;
    newNode->next = current->next;

    if (current->next != NULL) {
        current->next->prev = newNode;
    }

    current->next = newNode;
    
    return head;
}

int main() {
    struct Node *head = NULL; // Pointer to the first node of the doubly linked list
    int choice, el, position;

    do {
        // Display menu
        printf("\n--- Doubly Linked List Operations ---\n");
        printf("1. Display Doubly Linked List\n");
        printf("2. Insert at Beginning\n");
        printf("3. Insert at End\n");
        printf("4. Delete Element\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayList(head);
                break;
            case 2:
                printf("Enter the el to insert at the beginning: ");
                scanf("%d", &el);
                head = insertBeginning(head, el);
                break;
            case 3:
                printf("Enter the el to insert at the end: ");
                scanf("%d", &el);
                head = insertEnd(head, el);
                break;
            case 4:
                printf("Enter the el to delete: ");
                scanf("%d", &el);
                head = deleteElement(head, el);
                break;
            case 5:
                printf("Exiting the program.\n");
                break;
            case 6:
                printf("Enter the el to insert: ");
                scanf("%d", &el);
                printf("Enter the position to insert at: ");
                scanf("%d", &position);
                head = insertMiddle(head, el, position);
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }

    } while (choice != 5);

    // Free allocated memory
    struct Node *current = head;
    while (current != NULL) {
        struct Node *temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}
