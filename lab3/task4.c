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
        head = link;
        last = link;
    }
    else if (tailEmpty()){
        ;
    }
    else {
        last->next = link;
        link->prev = last;
    }
    
    last = link;

    current = last;
}


void insertFromStart(char* word) {
    struct node *link = (struct node*) malloc(sizeof(struct node));
    link->word = word;

    if (tailEmpty() && headEmpty()) {
        head = link;
        last = link;
    }
    else if (headEmpty()){
        ; // skipt the case when head is empty
    }
    else {
        head->prev = link;
        link->next = head;
    }
    
    head = link;
    current = head;
}

void moveNode(int direction) {
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
        free(current);
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
        head = NULL;
        last = NULL;
        current = NULL;
    }
}

char *inputCharString() {
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
    struct node *ptr;
    if (headEmpty() && tailEmpty()) {
        printf("\nThe list is empty\n");
        return;
    }
    
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

int main() {

    char *str;

    str = inputCharString();
    insertFromStart(str);
    
    str = inputCharString();
    insertFromStart(str);

    str = inputCharString();
    insertFromStart(str);

    labTask();

    displayList(1);

    //system("clear");

    return 0;
}

/*

void displayInstructions() {
    printf("\nWelcome to my linked list");
    printf("\nInstructions:\n> - move right\n< - move left");
    printf("\ne - insert from end\ns - insert from start");
    printf("\nf - display from start\nb - display from end");
    printf("\nl - insert to left\nr - insert to right");
    printf("\nd - delete current\nt - do the lab task\n");
}

void getInstruction(){
    int c;
    scanf("%d", c);

    if (c == 1) {
        moveNode(1);
    } else if (c == 2){
        moveNode(0);
    } else if (c == 3){            
        insertFromEnd(inputCharString());
    } else if (c == 4){
        
    } else if (c == 5){
        displayList(0);
    } else if (c == 6){
        displayList(1);
    } else if (c == 7){
            
    } else if (c == 8){
            
    } else if (c == 9){
            
    } else if (c == 10){
            
    }

    return getInstruction();
}

*/