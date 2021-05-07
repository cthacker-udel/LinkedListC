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

void printMenu(){

    printf("\n~=~=~=MENU~=~=~=\n");

}

int main(void){

    int choice = 0;
    int nodevalue = 0;
    while(1){

        printMenu();
        scanf("%d",&choice);
        switch(choice){


            default:
                return 0;
        }


    }


}