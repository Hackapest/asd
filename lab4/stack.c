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

bool is_operator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

bool is_digit(char c) {
    return (c >= '0' && c <= '9');
}

int perform_operation() {
    char operator = popStack()->symbol;
    int operand2 = popStack()->symbol;
    int operand1 = popStack()->symbol;

    operand1 = operand1 - 48;
    operand2 = operand2 - 48;

    printf("%c", operand1);

    int result;

    switch(operator) {
        case '+':
            result = operand1 + operand2;
            break;
        case '-':
            result = operand1 - operand2;
            break;
        case '*':
            result = operand1 * operand2;
            break;
        case '/':
            if (operand2 != 0) {
                result = operand1 / operand2;
            } else {
                printf("Error! Division by zero.");
            }
            break;
        default:
            printf("Error! Invalid operator.");
    }
}

void mainLoop() {
    char c;

    printf("Enter characters:\n");

    int i = 1;

    while(c = getc(stdin), c!='q') {
        printf("\n");
        if (i % 3 != 0) {
            if (!(is_digit(c))) {
                printf("Incorrect input\n");
                continue;
            }
            appendStack(c); 
            i++; 
        }
        else if (i % 3 == 0) {
            if (!(is_operator(c))) {
                printf("Incorrect input\n");
                continue;
            }
            appendStack(c);
            perform_operation();
            i++;
        }
        
        
    }
}



int main() {
    
    mainLoop();

    displayList();



    //struct node *ptr = NULL;

    //ptr = popStack();
    //printf("%c", ptr->symbol);
    
    return 0;
}