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
struct node *TEMP = NULL;


void printNodes(){

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

    printf("\n~=~=~=MENU~=~=~=\n0)Print nodes\n1)Exit Program");

}


int main(void){

    int choice;
    int nodeValue;

    while(1){

        printMenu();
        scanf("%d",&choice);
        switch(choice){

            case 0:
                print

        }


    }


}