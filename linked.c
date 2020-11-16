#include<stdio.h>
#include<stdlib.h>
// implementing LInked List 

struct node{
    /* data */
    int data;
    struct node *next;
};
struct node *head;

void printlist(struct node *p){
    while(p != NULL){
        printf("element: %d\n",p->data);
        p = p->next;
    }
}
//adding at index
void add_at_index(int index, int item){
    struct node *newnode = malloc(sizeof(struct node));
    struct node *ptr;
    newnode->data = item;
    if(newnode == NULL){
        printf("Memory Overflow at add at index");

    }
    //getting the head
    ptr = head;
    if(index == 0){
        newnode->next = head;
        head = newnode;
    }else{
        for(int i   = 0; i < index - 1; i++){
            ptr = ptr->next;
            if(ptr == NULL){
                printf("Cant Insert");
                return;
            }
        }
        newnode->next = ptr->next;
        ptr->next = newnode;
    }
}
//adding at start
void add_at_start(int item){
    struct node *newnode = malloc(sizeof(struct node));
    newnode->data = item;
    if(newnode == NULL){
        printf("Memory overflow at add at start");
        return;
    }
    if(head == NULL){
        head = newnode;
    }else{
        newnode->next = head;
        head = newnode;
    }
}

//adding at end
void add_at_end(int item){
    struct node *newnode = malloc(sizeof(struct node));
    // ptr to get the last node
    struct node *ptr;

    //since its adding at the end, next is always gona point at NULL so
    newnode->data = item;
    newnode->next = NULL;

    if(newnode == NULL){
        printf("Memory overflow, newnode pointing to NULL");
        return;
    }
    if(head == NULL){
        printf("Head is null, insert at beginning\n");
        head = newnode;
    }else{
        printf("Head not null, normal insert\n");
        ptr = head;
        while(ptr->next != NULL){
            ptr = ptr->next;
        } 

        // after getting the last node point it to the newnode and newnode points to NULL
        ptr->next = newnode;
    }
    

}
int main(){

    //printing nodes pointer
    struct node *p;
    add_at_start(100);
    add_at_end(500);
    add_at_start(200);
    add_at_start(300);
    add_at_start(3045);
    add_at_end(1000);
    add_at_start(2000);
    add_at_start(34345);
    add_at_index(1,3000);
    add_at_index(0,4000);
    add_at_end(333);
    printlist(head);
    
}