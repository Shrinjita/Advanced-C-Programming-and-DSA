#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

void insert(int x, struct node* P) {
    struct node* Temp;
    Temp = (struct node*)malloc(sizeof(struct node));
    if (Temp == NULL)
        printf("fatal error");
    else {
        Temp->data = x;
        Temp->next = P->next;
        P->next = Temp;
    }
}

struct node* FindPrevious(int x, struct node* L) {
    struct node* P;
    P = L;
    while (P->next != NULL && P->next->data != x)
        P = P->next;
    return P;
}

int IsLast(struct node* P) {
    return P->next == NULL;
}

void Delete(int x, struct node* L) {
    struct node* P;
    struct node* Tempcell;
    P = FindPrevious(x, L);
    if (!IsLast(P)) {
        Tempcell = P->next;
        free(Tempcell);
    }
}

void MakeEmpty(struct node* L) {
    if (L == NULL)
        printf("list is not created");
    else {
        while (!IsLast(L))
            Delete(L->next->data, L);
    }
}

struct node* Find(int x, struct node* L) {
    struct node* Temp;
    Temp = L;
    while (Temp != NULL) {
        if (Temp->data == x)
            return Temp;
        Temp = Temp->next;
    }
    return Temp;
}

void Display(struct node* L) {
    L = L->next;
    while (L != NULL) {
        printf("\n%d", L->data);
        L = L->next;
    }
}

void Deletelist(struct node* L) {
    MakeEmpty(L);
    free(L);
    L = NULL;
}

struct node* create() {
    struct node* L = (struct node*)malloc(sizeof(struct node));
    if (L == NULL)
        printf("fatal error");
    else {
        L->data = -1;
        L->next = NULL;
    }
    return L;
}

int main() {
    struct node* myList = create();
    int numElements, element;
    
    printf("Enter the number of elements to insert: ");
    scanf("%d", &numElements);

    for (int i = 0; i < numElements; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &element);
        insert(element, myList);
    }

    printf("List contents:\n");
    Display(myList);
    Deletelist(myList);
    
    return 0;
}