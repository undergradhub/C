#include<stdio.h>
#include<stdlib.h>
struct q{
    int data;
    struct q *next; 
};
struct q *front,*rear;
void init(){
    rear = front = NULL;
}
void insert(int data){
    struct q *newnode = malloc(sizeof(struct q));
    newnode->data = data;
    //if theres only one elem in q
    if(front == NULL){
        front = newnode;
        rear = newnode;
        front->next = NULL;
        rear->next = NULL;
    }else{
        rear->next = newnode;
        rear = newnode;
        rear->next = NULL;
    } // if there are multiple
}

//show
void show(struct q *ptr){
    ptr = front;
    if(front == NULL){
	printf("queue is empty");
	return;
    }
    while(ptr != NULL){
	printf("%d\n",ptr->data);
	ptr = ptr->next;
    }
}

void delete(){
    struct q *ptr;
    ptr = front;
    if(front == NULL){
        printf("Underflow\n");
        return;
    }else{
        front = front->next;
        free(ptr);
    }
}
int main(){
    insert(8);
    delete();
    insert(9);
    insert(10);
    insert(11);
    delete();
    show(front);
}
