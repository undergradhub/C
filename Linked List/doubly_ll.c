#include<stdio.h>
#include<stdlib.h>
struct doubly{
	int data;
	struct doubly *next;
	struct doubly *prev;
};
struct doubly *head;

// ADD AT BEGINNING
void add_at_start(int data){
	struct doubly *newnode = malloc(sizeof(struct doubly));
	newnode->data = data;
	if(head == NULL){
		newnode->prev = NULL;
		newnode->next = NULL;
		head = newnode;
	}else{
		/*
		- make the newnode next to point to first node ie head
		- make the first node prev point to newnode
		- newnode prev should be NULL
		- then assign head to newnode
		*/
		newnode->next = head;
		head->prev = newnode;
		newnode->prev = NULL;
		head = newnode;
	}
}

// ADD AT END
void add_at_end(int data){
	struct doubly *newnode = malloc(sizeof(struct doubly));
	newnode->data = data;
	if(head == NULL){
		add_at_start(data);
		return;
	}else{
		struct doubly *ptr;
		ptr = head;
		while(ptr->next != NULL){
			ptr = ptr->next;
		}
		newnode->next = NULL;
		ptr->next = newnode;
		newnode->prev = ptr;
	}
}

// DELETE AT START
void delete_at_start(){
	if(head == NULL){
		printf("[!] List is empty\n");
		return;
	}
	if(head->next == NULL){
		/* If there is only one element in the list
		- simple make head null, emptying the list 
		- Free the head
		*/
		head = NULL;
		free(head);
		return;
	}else{
		struct doubly *temp;
		/* If there are multiple elements in the list 
		- make head point towards second element ie head->next
		- make the previous of second element point NULL
		- free the temp ie head
		*/
		temp = head;
		head = head->next;
		head->prev = NULL;
		free(temp);
	}
}

// DELETE AT END
void delete_at_end(){
	if(head == NULL){
		printf("[!] List is empty\n");
		return;
	}
	if(head->next == NULL){
		delete_at_start();
		return;
	}else{
		struct doubly *temp;
		temp = head;
		while(temp->next->next != NULL){
			temp = temp->next;
		}
		temp->next = NULL;
		free(temp->next);
	}
}

// SHOW
void show(struct doubly *ptr){
	ptr = head;
	if(ptr == NULL){
		printf("[!] List is empty\n");
		return;
	}
	while(ptr != NULL){
		printf("[!] Element: %d\tPrev: %p\t Self: %p\t Next: %p\n",ptr->data, ptr->prev,ptr, ptr->next);
		ptr = ptr->next;
	}
}

// MAIN ENTRY
int main(){
	add_at_start(10);
	add_at_start(20);
	add_at_end(30);
	add_at_end(40);
	delete_at_start();
	delete_at_end();
	show(head);
}




