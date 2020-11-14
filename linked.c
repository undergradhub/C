#include<stdio.h>
#include<stdlib.h>
// implementing LInked List 

struct node{
    /* data */
    int data;
    struct node *next;
};
void printlist(struct node *p){
    while(p != NULL){
        printf("%d\n",p->data);
        p = p->next;
    }
}
int main(){
    // initializing structs
    struct node *head;
    struct node *one = NULL; //storing NULL value on the address location *one
    struct node *two = NULL;
    struct node *three = NULL;

    //printing nodes pointer
    struct node *p;
    //allocate memory
    one = malloc(sizeof(struct node));
    two = malloc(sizeof(struct node));
    three = malloc(sizeof(struct node));

    //assign values
    one->data = 10;
    two->data = 20;
    three->data = 30;

    //linking nodes
    one->next = two; // since next is a pointer, we're pointing current pointer to the next pointer i.e one->next = two
    two->next = three;
    three->next = NULL;

    head = one;

    printf("Printing nodes\n");
    printlist(head);
    int *pointer, c;
    c = 1;
    pointer = &c;
    *pointer = (long unsigned int) &c;
    printf("%d",*pointer);
}