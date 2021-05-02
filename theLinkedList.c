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


int main(void){

    int choice = 0;


    return 0;
}