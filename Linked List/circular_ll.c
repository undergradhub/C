#include<stdio.h>
#include<stdlib.h>

struct cirq{
    int data;
    struct cirq *next;
};

struct cirq *head;

int is_empty(){
    if(head == NULL){
        return 1;
    }else return 0;
}
// add operations ->
void add_at_start(int data){
    struct cirq *newnode = malloc(sizeof(struct cirq));
    struct cirq *temp;
    newnode->data = data;

    if(is_empty()){
        // make head point to newnode
        head = newnode;
        // newnode point to head
        newnode->next = head;
    }else{
        // when theres multiple element
        temp = head;
        // run till last node
        while(temp->next != head){
            temp = temp->next;
        }
        //make the newnode point to head
        newnode->next = head;
        // make the last node point to newnode
        /* 1) 10->20->30->10(head)
           2) newnode = 40
           3) 40->10(head)
           4) 20->30->40(new node)->10(old head)
           5) 40(new head)->10->20->30->40(head)
        */
        temp->next = newnode;
        head = newnode;
    }
}

void add_at_end(int data){
    struct cirq *newnode = malloc(sizeof(struct cirq));
    struct cirq *temp;
    newnode->data = data;
    
    if(is_empty()){
        add_at_start(data); //add at end is same as add at start when list is empty
    }else{
        temp = head;
        // 1) run till the last node
        while(temp->next != head){
            temp = temp->next;
        }
        // 2) make the last node point to the newnode
        temp->next = newnode;
        // 3) make the newnode node (last node now) point to the head
        newnode->next = head;
    }
}


void show(struct cirq *ptr){
    if(ptr == NULL){
        printf("[!]Cannot print, List is empty\n");
        return;
    }
    while(ptr->next != head){
        printf("%d\n",ptr->data);
        ptr = ptr->next;
    }
    printf("%d",ptr->data); // THAT one remaining element
}

// delete operations ->
void delete_at_start(){
    if(is_empty()){
        printf("[!]Cannot delete, Nothing to delete\n");
        return;
    }
    struct cirq *temp;
    temp = head;
    // if theres only one element in the list, make head NULL > then free it
    if(head->next == head){
        head = NULL;
        free(head);
        return;
    }
    // if there are multiple elements in the list, 1) go to the last node
    while(temp->next != head){
        temp = temp->next;
    }
    // 2) since head is first, make the last node point to the second node from the beginning
    temp->next = head->next;
    // 3) free the head
    free(head);
    // 4) make head point to second node from the beginning
    head = temp->next;
    
}

void delete_at_end(){
    struct cirq *temp,*s_temp;
    temp = head;
    if(is_empty()){
        printf("[!] Cannot delete, list is empty\n");
        return;
    }else{
        // 1) temp for last node and s_temp for second last node
        while(temp->next != head){
            s_temp = temp;
            temp = temp->next;
        }
        // 2) make second last node point to head
        s_temp->next = head;
        // 3) free the last node
        free(temp);
    }
}
int main(){
    add_at_start(10);
    add_at_end(20);
    add_at_end(30);
    add_at_start(40);
    // add_at_start(50);
    // delete_at_start();
    // delete_at_end();
    show(head);
}

