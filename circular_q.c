#include<stdlib.h>
#include<stdio.h>
#define size 3
int q[size];
int front = -1,rear = -1;

void insert(int item){
    if((front == rear +1) || (front == 0 && rear == size -1)){
        printf("Q is full");
        return;
    }
    if(front == -1)front = 0;
    rear = (rear + 1) % size; //This is important for circular queue
    q[rear] = item;
    printf("[+] Element %d added at %d\n",item,rear);
}

void delete(){
    if(front == -1){
        printf("q is empty\n");
        return;
    }else{
        if(front == rear){
            front = -1;
            rear = -1;
            printf("test out\n");
        }else{
            printf("[-] Element deleted from %d\n",front);
            front = (front + 1) % size;
        }
    }
}

void show(){
    printf("%d f %d r\n",front, rear);
    if(front == -1){
        printf("Empty\n");
        return;
    }
    int i = front;
    while(i != rear){
        printf("[*] %d\n",q[i]);
        i = (i + 1) % size;
    }
    printf("[*] %d\n",q[i]); //cheap trick to display THAT one last element
}


//main entry
int main(){
    insert(10);
    insert(11);
    insert(12);
    delete();
    insert(13);
    show();
    // display();
    return 0;
}