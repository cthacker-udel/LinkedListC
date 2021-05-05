#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>


struct node{

    int value;
    struct node *next;
    struct node *previous;

};


struct node *HEAD = NULL;
struct node *TAIL = NULL;


void addNode(int value){

    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->value = value;
    if(HEAD == NULL && TAIL == NULL){
        HEAD = newNode;
        TAIL = newNode;
        HEAD->next = NULL;
        HEAD->previous = NULL;
        TAIL->next = NULL;
        TAIL->previous = NULL;
    }
    else{
        struct node *currNode = HEAD;
        while(currNode->next != NULL){
            currNode = currNode->next;
        }
        currNode->next = newNode;
        newNode->previous = currNode;
        newNode->next = NULL;
        TAIL = newNode;
    }

}


void insertHead(int value){

    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->value = value;
    HEAD->previous = newNode;
    newNode->previous = NULL;
    newNode->next = HEAD;
    HEAD = newNode;

}

void insertTail(int value){

    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->previous = TAIL;
    TAIL->next = newNode;
    newNode->next = NULL;
    TAIL = newNode;

}

void displayList(){

    int index = 0;
    struct node *currNode = HEAD;

    printf("\n\n");
    while(currNode != NULL){
        printf("\nNode %d : %d\n",index++,currNode->value);
        currNode = currNode->next;
    }

}


void displayListReverse(){

    int index = 0;
    struct node *currNode = TAIL;
    while(currNode != NULL){
        printf("\n\nNODE %d : %d\n",index,currNode->value);
        currNode = currNode->previous;
        index++;
    }

}


void printNumNodes(){

    printf("\nThe number of nodes is : %d\n",numberOfNodes());

}


int numberOfNodes(){

    int count = 0;
    struct node *currNode = HEAD;
    while(currNode != NULL){
        currNode = currNode->next;
        count++;
    }
    return count;

}


void printMenu(){

    printf("\n~=~=~=MENU~=~=~=\n0)Print nodes\n1)Add Node\n2)Print List\n3)Print List Reverse\n4)Insert Head\n5)Insert Tail\n6)Exit Program");

}


int main(void){

    int choice;
    int nodeValue;

    while(1){

        printMenu();
        scanf("%d",&choice);
        switch(choice){

            case 0:
                printNumNodes();
                break;
            case 1:
                printf("\n\nEnter the value to append to the list :     ");
                scanf("%d",&nodeValue);
                addNode(nodeValue);
                break;
            case 2:
                displayList();
                break;
            case 3:
                displayListReverse();
                break;
            case 4:
                printf("\n\nEnter the value to append to the front of the list :      ");
                scanf("%d",&nodeValue);
                insertHead(nodeValue);
                break;
            case 5:
                printf("\n\nEnter the value to append to the end of the list :     ");
                scanf("%d",&nodeValue);
                insertTail(nodeValue);
                break;
            default:
                return 0;
        }


    }


}