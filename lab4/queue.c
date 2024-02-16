#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


struct node {
    char symbol;
    struct node* prev;
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

void appendStack(char data) {
    struct node *link = (struct node*) malloc(sizeof(struct node));
    link->symbol = data;

    if (isEmpty()) {
        head = link;
        tail = link;
        return;
    }

    link->prev = tail;
    tail = link;
    
    return;
}

Node *popStack() {
    if (isEmpty()) {
        printf("\nThe stack is empty");
        return NULL;
    }
    
    struct node *ptr = head;
    head = head->prev;
    
    return ptr;
}