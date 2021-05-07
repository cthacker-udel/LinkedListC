#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

/*

Prototypes

*/

int numberOfNodes(void);



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

    if(HEAD == NULL){
        addNode(value);
    }

    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->value = value;
    HEAD->previous = newNode;
    newNode->previous = NULL;
    newNode->next = HEAD;
    HEAD = newNode;

}

void insertTail(int value){

    if(TAIL == NULL){
        addNode(value);
    }

    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->value = value;
    newNode->previous = TAIL;
    newNode->next = NULL;
    TAIL->next = newNode;
    TAIL = newNode;

}

void insertPosition(int index, int value){

    struct node *newNode = (struct node *)malloc(sizeof(struct node));

    newNode->value = value;
    newNode->next = NULL;
    newNode->previous = NULL;

    int numNodes = numberOfNodes();

    if(numNodes < index){
        insertTail(value);
    }
    else if(index == 0){
        insertHead(value);
    }
    else{
        int theIndex = 0;
        struct node *currNode = HEAD;
        struct node *prevNode;
        while(currNode != NULL){
            prevNode = currNode;
            currNode = currNode->next;
            theIndex++;
            if(theIndex == index){
                prevNode->next = newNode;
                currNode->previous = newNode;
                newNode->next = currNode;
                newNode->previous = prevNode;
                break;
            }
        }
    }

}

void deleteHead(){

    int numNodes = numberOfNodes();
    if(numNodes == 1){
        HEAD = NULL;
        TAIL = NULL;
    }
    else{
        struct node *tempNode = HEAD->next;
        tempNode->previous = NULL;
        HEAD = tempNode;
    }
}


void deleteTail(){

    int numNodes = numberOfNodes();
    if(numNodes == 1){
        HEAD = NULL;
        TAIL = NULL;
    }
    else{
        struct node *tempNode = TAIL->previous;
        tempNode->next = NULL;
        TAIL = NULL;
        TAIL = tempNode;
    }

}


void deleteNode(int index){

    int numNodes = numberOfNodes();
    if(numNodes == 1){
        HEAD = NULL;
        TAIL = NULL;
    }
    else if(index == 0){
        deleteHead();
    }
    else if(index > numNodes){
        deleteTail();
    }
    else{
        int nodeIndex = 0;
        struct node *currNode = HEAD;
        struct node *prevNode;
        while(currNode != NULL){
            prevNode = currNode;
            currNode = currNode->next;
            nodeIndex++;
            if(nodeIndex == index){
                prevNode = currNode->next;
                currNode->previous = NULL;
                currNode->next = NULL;
                currNode = NULL;
            }
        }
    }


}


void insertMiddle(int value){

    int numNode = numberOfNodes();
    int middle = numNode / 2;
    if(numNode <= 1){
        addNode(value);
    }
    else{
        int index = 0;
        struct node *currNode = HEAD;
        struct node *prevNode;
        struct node *newNode = (struct node *)malloc(sizeof(struct node));
        newNode->value = value;
        newNode->next = NULL;
        newNode->previous = NULL;
        while(currNode != NULL){
            prevNode = currNode;
            currNode = currNode->next;
            index++;
            if(index == middle){
                prevNode->next = newNode;
                currNode->previous = newNode;
                newNode->previous = prevNode;
                newNode->next = currNode;
                break;
            }
        }
    }

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

int listMax(){

    int numNodes = numberOfNodes();
    if(numNodes == 0){
        printf("\nMax number unavailable, add a node to access the maximum value\n");
        return 0;
    }
    else if(numNodes == 1){
        return HEAD->value;
    }
    else{
        int max = 0;
        struct node *currNode = HEAD;
        while(currNode != NULL){
            if(currNode->value > max){
                max = currNode->value;
            }
            currNode = currNode->next;
        }
        return max;
    }

}

int listMin(){

    int numNodes = numberOfNodes();
    if(numNodes == 0){
        printf("\n\nMin number unavailable, please add a node to begin calculating the minimun");
        return 0;
    }
    else if(numNodes == 1){
        return HEAD->value;
    }
    else{
        int currNumber = HEAD->value;
        struct node *currNode = HEAD;
        while(currNode != NULL){
            int currVal = currNode->value;
            if(currVal < currNumber){
                currNumber = currVal;
            }
            currNode = currNode->next;
        }
        return currNumber;
    }

}

void printMinNumber(){

    printf("\n\nThe min number in the linked list is : %d\n\n",listMin());

}

void printMaxNumber(){

    printf("\n\nThe max number in the linked list is : %d\n\n",listMax());

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

    printf("\n~=~=~=MENU~=~=~=\n0)Print number of nodes\n1)Add Node\n2)Print List\n3)Print List Reverse\n4)Insert Head\n5)Insert Tail\n6)Print Max\n7)Print min\n8)Exit Program     ");

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
            case 6:
                printMaxNumber();
                break;
            case 7:
                printMinNumber();
                break;
            case 8:
                return 0;
            default:
                return 0;
        }


    }


}