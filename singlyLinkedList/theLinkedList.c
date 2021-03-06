#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

struct node{

    int value;

    struct node *next;

};

struct node *HEAD = NULL;

struct node *TAIL = NULL;

void addNode(int value){

    struct node *tempNode = (struct node *)malloc(sizeof(struct node));
    tempNode->next = NULL;
    tempNode->value = value;
    if(HEAD == NULL){
        HEAD = tempNode;
        TAIL = tempNode;
    }
    else{
        struct node *markerNode = HEAD;
        while(markerNode->next != NULL){
            markerNode = markerNode->next;
        }
        markerNode->next = tempNode;
    }

}

int numberOfNodes(){

    int numberOfNodes = 0;
    if(HEAD == NULL){
        return 0;
    }
    struct node *placerNode = HEAD;
    while(placerNode != NULL){
        numberOfNodes++;
        placerNode = placerNode->next;
    }
    return numberOfNodes;

}

void printNumberOfNodes(){

    printf("\n\nThe number of nodes in the list is : %d\n\n",numberOfNodes());
    
}

void printNodes(){

    struct node *tempNode = HEAD;
    int index = 0;
    while(tempNode != NULL){
        printf("\n\nNODE %d : %d\n\n",index++,tempNode->value);
        tempNode = tempNode->next;
    }

}

void printNodesReverse(){

    int numNodes = numberOfNodes();

    int arr[numNodes];

    struct node *tempNode = HEAD;
    int index = 0;

    while(tempNode != NULL){
        arr[index] = tempNode->value;
        tempNode = tempNode->next;
        index++;
    }

    int nodeIndex = 0;
    for(int i = numNodes-1; i >= 0 ; i--){
        printf("\n\nNODE %d : %d\n\n",nodeIndex++,arr[i]);
    }

}

void addHead(int value){

    struct node *tempNode = (struct node *)malloc(sizeof(struct node));

    tempNode->value = value;

    if(HEAD == NULL){
        tempNode->next = NULL;
    }
    else{
        tempNode->next = HEAD;
        HEAD->next = tempNode;
    }

}


void addTail(int value){

    struct node *tempNode = (struct node *)malloc(sizeof(struct node));

    tempNode->value = value;

    if(TAIL == NULL){

        tempNode = TAIL;
        tempNode->next = NULL;        

    }
    else{

        TAIL->next = tempNode;
        TAIL = tempNode;
        tempNode->next = NULL;

    }

}


void addMiddle(int value){

    int numNodes = numberOfNodes();

    int middle = numNodes / 2;

    if(numNodes == 0){
        addNode(value);
        return;
    }
    if(numNodes == 1){
        addNode(value);
        return;
    }

    struct node *prevNode;
    struct node *currNode = HEAD;

    int index = 0;

    while(currNode != NULL){
        if(index == middle){
            struct node *newNode = (struct node *)malloc(sizeof(struct node));
            newNode->value = value;
            newNode->next = currNode;
            prevNode->next = newNode;
            break;
        }
        prevNode = currNode;
        currNode = currNode->next;
        index++;
    }

}



void printOnlyEvenValue(){

    struct node *placerNode = HEAD;

    int index = 0;

    while(placerNode != NULL){
        int nodeValue = placerNode->value;
        if(nodeValue % 2 == 0){
            printf("\n\n Node %d has an even value of %d\n\n",index,nodeValue);
        }
        placerNode = placerNode->next;
        index++;
    }

}


void printOnlyOddValue(){

    struct node *placerNode = HEAD;

    int index = 0;


    while(placerNode != NULL){
        int nodeValue = placerNode->value;

        if(nodeValue % 2 != 0){
            printf("\n\nNode %d has an odd value of %d\n\n",index,nodeValue);
        }
        placerNode = placerNode->next;
        index++;
    }

}


void printHeadValue(){

    if(HEAD == NULL){
        printf("\n\nHEAD value has not been set yet\n\n");
    }
    else{
        printf("\n\nThe value of the head is : %d",HEAD->value);
    }

}


void printTailValue(){

    if(TAIL == NULL){
        printf("\n\nTAIL value has not been set yet\n\n");
    }
    else{
        printf("\n\nThe value of the tail is : %d",TAIL->value);
    }

}

void deleteHead(void){

    if(HEAD == NULL){
        return;
    }
    else{
        if(numberOfNodes() == 1){
            HEAD = NULL;
        }
        else{
            struct node *tempNode = HEAD->next;
            HEAD = NULL;
            HEAD = tempNode;
        }
    }

}

void deleteTail(void){

    if(TAIL == NULL){
        return;
    }
    else{
        struct node *tempNode = HEAD;
        struct node *prevNode;
        while(tempNode->next != NULL){
            prevNode = tempNode;
            tempNode = tempNode->next;
        }
        TAIL = NULL;
        prevNode->next = NULL;
        TAIL = prevNode;
    }

}

void deleteMiddle(void){

    int numNodes = numberOfNodes();
    if(numNodes == 0){
        return;
    }
    else if(numNodes == 1){
        HEAD = NULL;
        TAIL = NULL;
    }
    else{
        int middle = numNodes / 2;
        struct node *tempNode = HEAD;
        struct node *prevNode;
        int currIndex = 0;
        while(tempNode != NULL){
            if(currIndex == middle){
                prevNode->next = tempNode->next;
                tempNode = NULL;
                return;
            }
        }
        return;
    }

}

void searchForNumber(int numSearch){

    struct node *currNode = HEAD;

    int index = 0;

    while(currNode != NULL){
        if(currNode->value == numSearch){
            printf("\n\nFound the number %d at Node %d\n\n",numSearch,index);
            return;
        }
        currNode = currNode->next;
        index++;
    }
    printf("The number %d does not exist in the Linked List",numSearch);

}





void displayMenu(){

    printf("\n\n~=~=~=MENU~=~=~=\n0)Add node\n1)Print nodes\n2)Print nodes reverse\n3)Print number of nodes\n4)Add node middle\n5)Delete HEAD\n6)Delete TAIL\n7)Delete Middle\n8)Search for Number in Linked List\n9)Exit program\n\n Choice :  ");

}



int main(void){

    int choice = 0;
    int nodeValue = 0;



    while(1){

        displayMenu();
        scanf("%d",&choice);
        switch(choice){

            case 0:
                printf("Enter a value to append onto the Linked List    ");
                scanf("%d",&nodeValue);
                addNode(nodeValue);
                break;
            case 1:
                printNodes();
                break;
            case 2:
                printNodesReverse();
                break;
            case 3:
                printNumberOfNodes();
                break;
            case 4:
                printf("Enter a value for the node to be added into the middle of the linked list     ");
                scanf("%d",&nodeValue);
                addMiddle(nodeValue);
                break;
            case 5:
                deleteHead();
                break;
            case 6:
                deleteTail();
                break;
            case 7:
                deleteMiddle();
                break;
            case 8:
                printf("Enter a value to search the linked list for :   ");
                scanf("%d",&nodeValue);
                searchForNumber(nodeValue);
                break;
            default:
                return 0;
        }

    }


    return 0;
}