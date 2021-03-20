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
    if(top == NULL){
        printf("Stack is empty, inserting at index 0\n");
        struct stack *newnode = malloc(sizeof(struct stack));
        newnode->item = item;
        newnode->next = top;
        top = newnode;
        size++;
        if(newnode->next == NULL) printf("true");
        return;
    }else{
        printf("Stack isnt empty, inserting at next index\n");
        struct stack *newnode = malloc(sizeof(struct stack));
        newnode->item = item;
        newnode->next = top;
        top = newnode;
        size++;
        
    }
}
//pop operation
void pop(){
    printf("Top is:%d\n",top->item);
    if(top == NULL){
        printf("Stack is empty\n");
        return;
    }
    // if theres only one node, then make top point null and free it
    if(top->next ==NULL){
        top = NULL;
        free(top);
        size--;
    }else{
        struct stack *ptr; // ptr for node thats gona be deleted
        ptr = top; // assign top, since LIFO
        top = top->next; // point top to address of next node 
        printf("top is %d\n",top->item);
        size--;
        free(ptr); // deleting the ptr
        // Visualization
            /*
            10(add1) -> 5(add2) -> NULL
            top = add1
            pop()
            make top  = add2
            delete ptr

            */
    } // if there are multiple nodes then do this
}
//printing stack
void printstack(struct stack *p){
    if(p == NULL){
        printf("NULL\n");
    }else{
    //fix this, run from top till the head
        printf("%d-->",p->item);
        printstack(p->next);
    }
}

void peek(){
    printf("Peeking in %d\n",top->item);
    return;
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
    pop();
    printstack(top);
    peek();
}

