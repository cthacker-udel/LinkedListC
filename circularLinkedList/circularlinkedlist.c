#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>



typedef struct{

    int value;
    node *next;
    node *previous;

}node;


node *HEAD = NULL;
node *TAIL = NULL;


void addNode(int value){

    node *newNode = (node *)malloc(sizeof(node));
    newNode->value = value;


    if(HEAD == NULL){
        HEAD->previous = NULL;
        HEAD = newNode;
        TAIL = newNode;
    }
    else{
        node *currNode = HEAD;
        while(currNode != TAIL){
            currNode = currNode->next;
        }
        TAIL->next = newNode;
        newNode->next = HEAD;
        newNode->previous = TAIL;
        TAIL = newNode;
    }

    return;
}



void printMenu(){

    printf("\n\n~=~=~=MENU~=~=~=\n1)Add value to list\n2)Exit program");

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
                return 0;
            default:
                return 0;
        }

    }


}