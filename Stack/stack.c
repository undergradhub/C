// Stack is LIFO
#include<stdio.h>
int arr[5],top,x;
// functions needs declaration like this before calling or defining it
int push(int elem);
void show(void);
void pop(void);

int main(){
    top = -1;
    printf("Stack implementation using arrays\n");
    push(3);//f
    // push(4);//s
    // push(5);//t
    //the array looks like this 5 4 3
    pop();
    pop();
    show();
    return 0;
}
// pushing the element into the stack
int push(int elem){
    if(top >= 5){
        printf("Overflow");
    }else{
        top++;
        arr[top] = elem;
        printf("Element added");
    }
    return 0;
}
// show stack
void show(){
    for(int i = top; i >=0; i--){
        printf("\t%d",arr[i]);
    }
}

// pop item from stack
void pop(){
    if(top <= -1){
        printf("underflow\n");
    }
    arr[top] = 0;
    top--;
}
