// Queue implementation in array
// front and rear 
// insert element from rear and delete element from front

#include<stdio.h>
int insert(int elem);
void delete(void);
void show(void);
int q[5];
int front,rear;
int main(){
    front = -1,rear = -1;
    // calling the functions
    insert(5);
    insert(6);
    insert(7);
    insert(8);
    delete();
    show();
    return 0;
}

// insert function
int insert(int elem){
    if(rear >= 5){
        printf("Queue is full");
    }else{
        front = 0;
        rear++;
        q[rear] = elem;
        printf("element added at %d and elem %d\n",rear,elem);
    }
    return 0;
}

//show q
void show(){
    for(int i = front; i <=rear; i++){
        printf("elem %d at pos %d;\t",q[i],i);
    }
}

// delete elemt from q
void delete(){
    if(front <= -1){
        printf("Queue is empty");
    }else{
        front++;
        printf("Element deleted\n");
    }
}