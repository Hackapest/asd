#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


struct node {
    char symbol;
    struct node* prev;
};

typedef struct node Node;

struct node *top = NULL;

bool isEmpty() {
    if (top == NULL) {
        return true;
    } else {
        return false;
    }
}

void appendStack(char data) {
    struct node *link = (struct node*) malloc(sizeof(struct node));
    link->symbol = data;

    if (isEmpty()) {
        top = link;
        return;
    }

    link->prev = top;
    top = link;
    
    return;
}

Node *popStack() {
    if (isEmpty()) {
        printf("\nThe stack is empty");
        return NULL;
    }
    
    struct node *ptr = top;
    top = top->prev;
    
    return ptr;
}

void displayList(){
    struct node *ptr;
    if (isEmpty()) {
        printf("\nThe list is empty\n");
        return;
    }

    ptr = top;

    while (ptr != NULL) {
        printf("\n[ (%c)", ptr->symbol);

        printf(" ]");

        ptr = ptr->prev;
    }
}

int main() {
    appendStack('a');
    appendStack('a');
    appendStack('a');
    appendStack('a');

    displayList();

    //struct node *ptr = NULL;

    //ptr = popStack();
    //printf("%c", ptr->symbol);
    
    return 0;
}