#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>



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

    if(HEAD == NULL){
        newNode->next = NULL;
        newNode->previous = NULL;
        HEAD = newNode;
        TAIL = newNode;
        TAIL->next = newNode;
    }
    else{
        struct node *currNode = HEAD;
        while(currNode != TAIL){
            currNode = currNode->next;
        }
        TAIL->next = newNode;
        newNode->next = HEAD;
        newNode->previous = TAIL;
        TAIL = newNode;
        HEAD->previous = newNode;
    }

    return;
}

void insertHead(int value){

    struct node *currNode = HEAD;
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->value = value;
    newNode->previous = TAIL;
    newNode->next = HEAD;
    TAIL->next = newNode;
    HEAD = newNode;

}

void printList(){

    int nodeNum = 0;
    struct node *currNode = HEAD;
    printf("\n\nNODE %d : %d",nodeNum++,currNode->value);
    currNode = currNode->next;
    while(currNode != HEAD){
        printf("\n\nNODE %d : %d",nodeNum++,currNode->value);
        currNode = currNode->next;
    }

}


void reversePrintList(){

    int nodeNum = 0;
    struct node *currNode = TAIL;
    printf("\n\nNODE %d : %d\n",nodeNum++,currNode->value);
    currNode = currNode->previous;
    while(currNode != TAIL){
        printf("\n\nNODE %d : %d\n",nodeNum++,currNode->value);
        currNode = currNode->previous;
    }

}



void printMenu(){

    printf("\n\n~=~=~=MENU~=~=~=\n1)Add value to list\n2)Print list\n3)Reverse List Print\n4)Insert head\n5)Exit program");

}

int main(void){

    int choice = 0;
    int nodevalue = 0;

    while(1){

        printMenu();
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("\nEnter value to add to the list    ");
                scanf("%d",&nodevalue);
                addNode(nodevalue);
                break;
            case 2:
                printList();
                break;
            case 3:
                reversePrintList();
                break;
            case 4:
                printf("\nEnter the value to add to the list :   ");
                scanf("%d",&nodevalue);
                insertHead(nodevalue);
                break;
            default:
                return 0;
        }

    }


}