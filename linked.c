#include<stdio.h>
#include<stdlib.h>
// implementing Linked List 

struct node{
    /* data */
    int data;
    struct node *next;
};
struct node *head;
long int size = 0;
void add_at_start(int item);
//head is passed here
void printlist(struct node *p){
    if(p == NULL){
        printf("List is empty\n");
        return;
    }
    while(p != NULL){
        printf("element: %d\n",p->data);
        p = p->next;
    }
    printf("Size of linked list %ld\n",size);
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
        add_at_start(item);
    }else{
        for(int i  = 0; i < index ; i++){
            ptr = ptr->next;
            if(ptr == NULL){
                printf("Cant Insert");
                return;
            }
        }
        newnode->next = ptr->next;
        ptr->next = newnode;
        size++;
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
        size++;
    }else{
        newnode->next = head;
        head = newnode;
        size++;
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
        size++;
    }else{
        printf("Head not null, normal insert\n");
        ptr = head;
        while(ptr->next != NULL){
            ptr = ptr->next;
        } 

        // after getting the last node point it to the newnode and newnode points to NULL
        ptr->next = newnode;
        size++;
    }
    

}

// delete at beginning
void delete_at_start(){
    if(head == NULL){
        printf("List is empty\n");
        return;
    }
    struct node *delete_ptr;

    delete_ptr = head;
    head = delete_ptr->next;

    free(delete_ptr);
    size--;
    printf("Element deleted\n");
}

//delete at end
void delete_at_end(){
    if(head == NULL){
        printf("List is empty\n");
        return;
    }
    if(head->next == NULL){
        head = NULL;
        free(head);
        size--;
        return;
    }
    struct node *last_ptr,*secondlast_ptr;
    last_ptr = head;
    while(last_ptr->next != NULL){
        secondlast_ptr = last_ptr;
        last_ptr = last_ptr->next;
    }

    secondlast_ptr->next = NULL;
    free(last_ptr);
    size--;
    printf("Node deleted at end\n");
}

//delete at index
void delete_at_index(int index){
    struct node *del_ptr, *ptr;
    del_ptr = head;
    if(index > size){
        printf("Index out of bounds\n");
        return;
    }
    if(head == NULL){
        printf("List is empty\n");
        return;
    }
    if(index == 0){
        delete_at_start();
        return;
    }
    for(int i = 0; i < index; i++){
        ptr = del_ptr;
        del_ptr = del_ptr->next;
    }
    if(del_ptr->next == NULL){
        delete_at_end();
        return;
    }
    ptr->next = del_ptr->next;
    free(del_ptr);
    size--;
    printf("Element deleted at index\n");
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

    // delete operation

    delete_at_start();
    delete_at_end();
    delete_at_index(2);
    printlist(head);
    
}