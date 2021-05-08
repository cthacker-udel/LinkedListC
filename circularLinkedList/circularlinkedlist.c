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


int numNodes(){

    if(HEAD == NULL){
        return 0;
    }
    else if(HEAD->next == NULL){
        return 1;
    }
    else{
        struct node *currNode = HEAD;
        int count = 1;
        while(currNode->next != HEAD){
            count++;
            currNode = currNode->next;
        }
        return count;
    }
}

void insertHead(int value){

    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->value = value;
    newNode->previous = TAIL;
    newNode->next = HEAD;
    TAIL->next = newNode;
    HEAD = newNode;

}

void insertTail(int value){

    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->value = value;
    newNode->next = HEAD;
    newNode->previous = TAIL;
    TAIL->next = newNode;
    TAIL = newNode;


}

void insertNode(int value){

    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->value = value;
    int index = 0;
    printf("\nSecond : Enter the index which to place the node   ");
    scanf("%d",&index);
    int numberOfNodes = numNodes();
    if(index == 0){
        insertHead(value);
    }
    else if(index >= numberOfNodes){
        insertTail(value);
    }
    else{
        int currIndex = 0;
        struct node *currNode = HEAD;
        struct node *prevNode;
        while(currNode->next != HEAD){
            prevNode = currNode;
            currNode = currNode->next;
            currIndex++;
            if(currIndex == index){
                prevNode->next = newNode;
                newNode->previous = prevNode;
                currNode->previous = newNode;
                newNode->next = currNode;
                return;
            }
        }
    }

}

void printList(){


    if(HEAD == NULL){
        return;
    }
    int nodeNum = 0;
    struct node *currNode = HEAD;
    printf("\n\nNODE %d : %d\n",nodeNum++,currNode->value);
    currNode = currNode->next;
    while(currNode != HEAD){
        printf("\n\nNODE %d : %d",nodeNum++,currNode->value);
        currNode = currNode->next;
    }

}

void deleteHead(){

    int numNode = numNodes();
    if(numNode == 0){
        return;
    }
    else if(numNode == 1){
        HEAD = NULL;
        TAIL = NULL;
    }
    else{

        struct node *currNode = HEAD->next;
        HEAD = NULL;
        currNode->previous = TAIL;
        TAIL->next = currNode;
        HEAD = currNode;

    }

}

void deleteTail(){

    int numNode = numNodes();
    if(numNode == 0){
        return;
    }
    else if(numNode == 1){
        HEAD = NULL;
        TAIL = NULL;
    }
    else{
        struct node *currNode = TAIL->previous;
        TAIL = NULL;
        HEAD->previous = currNode;
        currNode->next = HEAD;
        TAIL = currNode;
    }

}




void reversePrintList(){

    if(HEAD == NULL){
        return;
    }
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

    printf("\n\n~=~=~=MENU~=~=~=\n1)Add value to list\n2)Print list\n3)Reverse List Print\n4)Insert head\n5)Insert tail\n6)Insert node at index\n7)Delete Head\n8)Delete TailExit program");

}

int main(void){

    int choice = 0;
    int nodevalue = 0;

    while(1){
        
        sleep(2);
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
            case 5:
                printf("\nEnter the value to add to the end of the list : ");
                scanf("%d",&nodevalue);
                insertTail(nodevalue);
                break;
            case 6:
                printf("\nFirst : specify the value to give the node\t");
                scanf("%d",&nodevalue);
                insertNode(nodevalue);
                break;
            case 7:
                deleteHead();
                break;
            case 8:
                deleteTail();
                break;
            default:
                return 0;
        }

    }


}