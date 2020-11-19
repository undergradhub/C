#include<stdio.h>
#include<stdlib.h>

//stack struct node declaration
struct stack{
    int item;
    struct stack *next;
};

//head pointer to be used globally
struct stack  *head,*top;
//for the size of the stack
long int size;

//pushing onto top of stack
void push(int item){
    if(head == NULL){
        printf("Stack is empty, inserting at index 0\n");
        struct stack *newnode = malloc(sizeof(struct stack));
        newnode->item = item;
        newnode->next = NULL;
        head = newnode;
        top = newnode;
        size++;
        return;
    }else{
        printf("Stack isnt empty, inserting at next index\n");
        struct stack *newnode = malloc(sizeof(struct stack));
        newnode->item = item;
        newnode->next = NULL;
        //This operation is same as inserting a node at the end, since stack is LIFO
        //so we declare a ptr to get the last node
        struct stack *ptr;
        ptr = head;
        while(ptr->next != NULL){
            ptr = ptr->next;
        }
        ptr->next = newnode;
        top = newnode;
        size++;
        
    }
}
//pop operation
void pop(){
    printf("Top is:%d\n",top->item);
    if(head == NULL){
        printf("Stack is empty\n");
        return;
    }
    if(head->next == NULL){
        head = NULL;
        free(head);
        size--;
        return;
    }
    struct stack *ptr,*sptr;
    ptr = head;
    while(ptr != top){
        sptr = ptr;
        ptr = ptr->next;

    }
    sptr->next = NULL;
    top = sptr;
    size--;
    printf("Deleting element %d\n",ptr->item);
    free(ptr);
}
//printing stack
void printstack(struct stack *p){
    if(p == NULL){
        printf("Stack is empty,now exiting\n");
        return;
    }
    //fix this, run from top till the head
    while(p != NULL){
        printf("%d--->",p->item);
        p = p->next;
    }
    printf("\nSize of Stack %ld",size);
}
int main(){
    push(5);
    push(10);
    push(15);
    push(15145);
    push(124);
    push(1565);
    pop();
    pop();
    pop();
    printstack(head);
}
