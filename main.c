#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node *next;
} Node;

Node *createNode(int data) {
    Node *newNode = (Node*) malloc (sizeof(Node));
    if (newNode == NULL) {
        printf("Ошибка выделения памяти");
        exit(1);
    }
    newNode -> value = data;
    newNode -> next = NULL;
    return newNode;
}

void append(Node **head, int data) {
    Node* newNode = createNode(data);

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    Node* last = *head;
    while(last->next != NULL) {
        last = last -> next;
    }
    last -> next = newNode;
}

void printList(Node *head){
    Node *p = head;
    while(p != NULL) {
        printf("%d ", p -> value);
        p = p -> next;
    }
}

void clearList(Node *head){
    while (head != NULL) {
        Node *p = head;
        head = head -> next;
        free(p);
    }

}

int main() {
    Node *head = NULL;

    append(&head, 7);
    append(&head, 25);
    append(&head, 12);
    append(&head, 5);
    append(&head, 1);

    printList(head);
    clearList(head);

    return 0;
}