#include "headers.h"


struct node{

    int value;
    struct node *next;
    struct node *previous;

};


struct node *HEAD = NULL;
struct node *TAIL = NULL;



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