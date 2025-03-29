#include <stdio.h>
#include <stdlib.h>

// Define the structure for a linked list node
struct Node {
    int data;
    struct Node *next;
};

// Function to display the els of the linked list
void display(struct Node *head) {
    struct Node *current = head;
    printf("Linked List els: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Function to insert an el at the beginning of the linked list
struct Node* insertBeg(struct Node *head, int el) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = el;
    newNode->next = head;
    return newNode;
}

// Function to insert an el at the end of the linked list
struct Node* insertEnd(struct Node *head, int el) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = el;
    newNode->next = NULL;

    if (head == NULL) {
        return newNode;
    }

    struct Node *current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
    return head;
}

// Function to delete an el from the linked list
struct Node* deleteEL(struct Node *head, int el) {
    if (head == NULL) {
        printf("List is empty. Cannot delete.\n");
        return NULL;
    }

    if (head->data == el) {
        struct Node *temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    struct Node *current = head;
    while (current->next != NULL && current->next->data != el) {
        current = current->next;
    }

    if (current->next == NULL) {
        printf("el %d not found in the list.\n", el);
    } else {
        struct Node *temp = current->next;
        current->next = current->next->next;
        free(temp);
    }
    return head;
}

int main() {
    struct Node *head = NULL; // Pointer to the first node of the linked list
    int choice, el;

    do {
        // Display menu
        printf("\nLinked List Operations :\n1. Display Linked List\n2. Insert at Beginning\n3. Insert at End\n4. Delete element\n5. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                display(head);
                break;
            case 2:
                printf("Insert element at the beginning: ");
                scanf("%d", &el);
                head = insertBeg(head, el);
                break;
            case 3:
                printf("Enter the el to insert at the end: ");
                scanf("%d", &el);
                head = insertEnd(head, el);
                break;
            case 4:
                printf("Enter the el to delete: ");
                scanf("%d", &el);
                head = deleteEL(head, el);
                break;
            case 5:
                printf("Exiting the program.\n");
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
