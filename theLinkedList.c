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

void printNodes(){

    struct node *tempNode = HEAD;
    int index = 0;
    while(tempNode != NULL){
        printf("\n\nNODE %d : %d\n\n",index++,tempNode->value);
        tempNode = tempNode->next;
    }

}

void printNodesReverse(){

    struct node *tempNode = HEAD;
    int index = 0;
    while(tempNode != NULL){
        tempNode = tempNode->next;
        index++;
    }

    for(int i = index; i >= 0; i--){
        printf("\n\nNODE %d : %d\n\n",index,tempNode[i].value);
    }

}

void displayMenu(){

    printf("\n\n~=~=~=MENU~=~=~=\n0)Add node\n1)Print nodes\n2)Print nodes reverse\n3)Exit program\n\n Choice :  ");

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
                return 0;
        }

    }


    return 0;
}