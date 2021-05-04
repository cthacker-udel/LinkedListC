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

void displayList(){

    int index = 0;
    struct node *currNode = HEAD;

    printf("\n\n");
    while(currNode != NULL){
        printf("\nNode %d : %d\n",index++,currNode->value);
        currNode = currNode->next;
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

    printf("\n~=~=~=MENU~=~=~=\n0)Print nodes\n1)Add Node\n2)Print List\n3)Exit Program");

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
                return 0;
            default:
                return 0;
        }


    }


}