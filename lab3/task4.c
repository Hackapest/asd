#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


struct node {
    char* word;
    struct node* prev;
    struct node* next;
};

typedef struct node Node;

// head node
struct node *head = NULL;

// tail node
struct node *last = NULL;

// current node
struct node *current = NULL;

// check if empty
bool headEmpty() {
    if (head == NULL) {
        return true;
    }
    else {
        return false;
    }
}

bool tailEmpty() {
    if (last == NULL) {
        return true;
    }
    else {
        return false;
    }
}

void displayList(int start){
    struct node *ptr;
    if (headEmpty() && tailEmpty()) {
        printf("\nThe list is empty\n");
        return;
    }

    // start from head
    if (start == 0) {
        ptr = head;
    }
    // start from tail
    else {
        ptr = last;
    }

    printf("\n");
    while(ptr != NULL) {
        printf("\n[ (%s)", ptr->word);

        // display the head, tail and current selected
        if (ptr == head) {
            printf("<-- Head");
        }
        if (ptr == last) {
            printf("<-- Tail");
        }
        if (ptr == current) {
            printf("<-- Current");
        }
        printf(" ]");

        // direction of display
        if (start == 0) ptr = ptr->next;
        else ptr = ptr->prev;
    }
    printf("\n");
}

void insertFromEnd(char* word) {
    struct node *link = (struct node*) malloc(sizeof(struct node));
    link->word = word;

    if (tailEmpty() && headEmpty()) {
        // the case when the list is empty
        head = link;
        last = link;
    }
    else if (tailEmpty()){
        ; // skipt the case when head is empty
          // not sure if this is needed
          // but let it be here for now
    }
    else {
        // the case when not empty
        last->next = link;
        link->prev = last;
    }
    
    last = link;

    current = last;
}

void insertFromStart(char* word) {
    // create the node to insert
    struct node *link = (struct node*) malloc(sizeof(struct node));
    link->word = word;

    if (tailEmpty() && headEmpty()) {
        // the case when the list is empty
        head = link;
        last = link;
    }
    else if (headEmpty()){
        ; // skipt the case when head is empty
          // not sure if this is needed
          // but let it be here for now
    }
    else {
        // the case when not empty
        head->prev = link;
        link->next = head;
    }
    
    head = link;
    current = head;
}

void moveNode(int direction) {
    // check if no node is selected
    if (current == NULL) {
        printf("\nCurrent node is NULL\n");
        return;
    }
    // move prev
    if (direction == 0 && current->prev != NULL) {
        current = current->prev;
    }
    // move next
    else if (direction == 1 && current->next != NULL) {
        current = current->next;
    }
    else {
        printf("\nUnable to move\n");
    }
}

void removeCurrentNode() {
    if (current == NULL) {
        printf("\nCurrent node is NULL\n");
        return;
    }
    
    if (current->next != NULL && current->prev != NULL) {
        current->prev->next = current->next;
        current->next->prev = current->prev;
        free(current); // not sure if needed
    }
    else if (current == head && current->next != NULL) {
        head = current->next;
        current = head;
    }
    else if (current == last && current->prev != NULL) {
        last = current->prev;
        current = last;
    }
    else if (current == last && current == head) {
        // if the list consists of only one node
        head = NULL;
        last = NULL;
        current = NULL;
    }
}

void insertLeft(char* word) {
    if (current == NULL) {
        printf("\nCurrent node is NULL\n");
        return;
    }

    if (current == head) {
        insertFromStart(word);
        return;
    }

    struct node *link = (struct node*) malloc(sizeof(struct node));
    link->word = word;

    link->next = current;
    link->prev = current->prev;
    current->prev->next = link;
    current->prev = link;
}

void insertRight(char* word) {
    if (current == NULL) {
        printf("\nCurrent node is NULL\n");
        return;
    }

    if (current == last) {
        insertFromEnd(word);
        return;
    }

    struct node *link = (struct node*) malloc(sizeof(struct node));
    link->word = word;

    link->prev = current;
    link->next = current->next;
    current->next->prev = link;
    current->next = link;
}

char *inputCharString() {
    // user input
    char *str, c;
    int i = 0;
    str = (char*) malloc(2 * sizeof(char));

    while(c = getc(stdin), c!='\n') {
        str[i] = c;
        i++;
        str = realloc(str, (i + 2) * sizeof(char));
    }

    str[i + 1] = '\0';
    return str;
}

void labTask() {
    
    if (headEmpty() && tailEmpty()) {
        printf("\nThe list is empty\n");
        return;
    }
    
    struct node *ptr;
    bool temp;
    int len;

    while (ptr != NULL) {
        ptr == head;

        // discard skip if sumular to the first word
        // first word is always skipped
        temp = strcmp(head->word, ptr->word);
        if (!temp) {
            ptr = ptr->next;
            continue;
        }
        
        len = strlen(ptr->word);
        if (len % 2 == 0) {
            // add one memory slot to the word
            ptr->word = realloc(ptr->word, (len + 2) * sizeof(char));

            // shift the string by one
            for (int i = (len + 1); i > 0; i--) {
                ptr->word[i] = ptr->word[i - 1];
            }
            
            // close the string
            ptr->word[len + 1] = '\0';

            // update the lenght to use later
            len = len + 1;
        }
        else {
            // take away the memory
            ptr->word = realloc(ptr->word, (len) * sizeof(char));

            // close the string
            ptr->word[len - 1] = '\0';

            // update the lenght to use later
            len = len - 1;
        }

        for (int i = 0; i < len; i++) {
            if (ptr->word[i] == 'a') {
                ptr->word[i] = 'e';
            }
        }
        
        // move to the next node
        ptr = ptr->next;
    }
}

void displayInstructions() {
    printf("\nWelcome to my linked list");
    printf("\nInstructions:\n> - move right\n< - move left");
    printf("\ne - insert from end\ns - insert from start");
    printf("\nf - display from start\nb - display from end");
    printf("\nl - insert to left\nr - insert to right");
    printf("\nd - delete current\nt - do the lab task");
    printf("\nh - show this message again\nx - exit\n");
}

void getInstruction(){

    char choice;

    // User input
    scanf("%c", &choice);

    char* str;
    // Process user choice
    switch(choice) {
        case '>':
            moveNode(1);
            break;
        case '<':
            moveNode(0);
            break;
        case 'e':
            while(choice = getc(stdin), choice!='\n') {
                ;
            }
            str = inputCharString();
            insertFromEnd(str);
            break;
        case 's':
            while(choice = getc(stdin), choice!='\n') {
                ;
            }
            str = inputCharString();
            insertFromStart(str);
            break;
        case 'f':
            displayList(0);
            break;
        case 'b':
            displayList(1);
            break;
        case 'l':
            while(choice = getc(stdin), choice!='\n') {
                ;
            }
            str = inputCharString();
            insertLeft(str);
            break;
        case 'r':
            while(choice = getc(stdin), choice!='\n') {
                ;
            }
            str = inputCharString();
            insertRight(str);
            break;
        case 'd':
            removeCurrentNode();
            break;
        case 't':
            labTask();
            break;
        case 'h':
            displayInstructions();
            break;
        case 'x':
            exit(0);
            break;
        default:
            break;
    }
}


int main() {

    displayInstructions();

    while (1) {
        getInstruction();
    }

    return 0;
}