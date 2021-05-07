#include "headers.h"


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
    }
    else{

        struct node *currNode = (struct node *)malloc(sizeof(struct node));
        while(currNode->next != NULL){
            currNode = currNode->next;
        }
        currNode->next = newNode;
        newNode->next = NULL;
        newNode->previous = currNode;
        TAIL = newNode;
    }

} 


int numNodes(){

    int count = 0;
    struct node *currNode = HEAD;
    while(currNode != NULL){
        count++;
        currNode = currNode->next;
    }
    return count;

}

void addHead(int value){

    if(HEAD == NULL){
        addNode(value);
    }
    else{

        struct node *newNode = (struct node *)malloc(sizeof(struct node));
        newNode->value = value;
        HEAD->previous = newNode;
        newNode->next = HEAD;
        newNode->previous = NULL;
        HEAD = newNode;

    }

}

void addTail(int value){

    if(TAIL == NULL){
        addNode(value);
    }
    else{
        struct node *newNode = (struct node *)malloc(sizeof(struct node));
        newNode->value = value;
        TAIL->next = newNode;
        newNode->previous = TAIL;
        newNode->next = NULL;
        TAIL = newNode;
    }

}

void addMiddle(int value){

    int numNode = numNodes();

    if(HEAD == NULL){
        addNode(value);
    }
    else if(numNode < 2){
        addNode(value);
    }
    else{

        struct node *newNode = (struct node *)malloc(sizeof(struct node));
        newNode->value = value;
        int middle = numNode / 2;
        int index = 0;
        struct node *currNode = HEAD;
        struct node *prevNode;
        while(currNode != NULL){
            prevNode = currNode;
            currNode = currNode->next;
            index++;
            if(index == middle){
                prevNode->next = newNode;
                currNode->previous = newNode;
                return;
            }
        }

    }

}

void printMenu(){

    printf("\n~=~=~=MENU~=~=~=\n\n0)Add node\n1)Add head\n2)Add tail");

}

int main(void){

    int choice = 0;
    int nodevalue = 0;
    while(1){

        printMenu();
        scanf("%d",&choice);
        switch(choice){

            case 0:
                printf("\nEnter a node value to add to the linked list :   ");
                scanf("%d",&nodevalue);
                addNode(nodevalue);
                break;
            case 1:
                printf("\nEnter a value to append a new node to the top of the list with :    ");
                scanf("%d",&nodevalue);
                addNode(nodevalue);
                break;
            case 2:
                printf("\nEnter a value to append a new node to the end of the list with :    ");
                scanf("%d",&nodevalue);
                addTail(nodevalue);
                break;
            default:
                return 0;
        }


    }


}