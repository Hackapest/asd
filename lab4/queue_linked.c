#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


struct node {
    int value;
    struct node* next;
};

typedef struct node Node;

struct node *head = NULL;

struct node *tail = NULL;

bool isEmpty() {
    if (head == NULL) {
        return true;
    } else {
        return false;
    }
}

bool oneElement() {
    if (head == tail) {
        return true;
    }
    else {
        return false;
    }
}

void clearQueue() {
    free(head);
    free(tail);
    head = NULL;
    tail = NULL;
    return;
}

void appendQueue(int myint) {
    struct node *link = (struct node*) malloc(sizeof(struct node));
    link->value = myint;

    if (isEmpty()) {
        head = link;
        tail = link;
        return;
    }

    tail->next = link;
    tail = link;
    
    return;
}

int popQueue() {
    if (isEmpty()) {
        printf("\nThe stack is empty");
        return -1;
    }
    
    struct node *ptr = head;

    if (oneElement()) {
        clearQueue();
    }
    else {
        // when more than one element
        free(head);
        head = head->next;
    }
    return ptr->value;
}

void printQueue() {
    if (isEmpty()) {
        printf("The queue is empty.\n");
        return;
    }

    Node* temp = head;
    printf("Queue: ");
    while (temp != NULL) {
        printf("%d ", temp->value);
        temp = temp->next;
    }
    printf("\n");
}

int peekQueue() {
    if (isEmpty()) {
        return -1; // Return a sentinel value to indicate an empty queue
    }
    return head->value;
}

int main() {

    appendQueue(10);
    appendQueue(20);
    appendQueue(30);

    printQueue();

    popQueue();
    popQueue();

    printQueue(); // Output: Queue: 10 20 30

    return 0;
}