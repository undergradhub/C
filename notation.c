#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int arr[100000],top,x;
int bigarr[100000];
/*
Given the input 100000
average time taken for stack pop operation is 0.000002s
average time taken for array delete operation is 0.000928.5s
more in readme #links 
*/
// functions needs declaration like this before calling or defining it
//for stack
int push(int elem);
void show(void);
void pop(void);

//for arr
void rem(int elem);

//main entry
int main(){
    top = -1;
    //for stack
    printf("Stack implementation using arrays\n");
    clock_t start,end;
	for(int i = 0; i < 100000; i++){
		push(i);
	}
	start = clock();
    pop();
    // show();
	end = clock();
	double time_taken = ((double) (end - start))/ CLOCKS_PER_SEC;
	printf("Time taken for stack %f\n",time_taken);

    //for arr
	clock_t s,e;
	for(int i = 0; i < 100000; i++){
		bigarr[i] = i;
	}
	s = clock();
	rem(99999);
	e = clock();
	double tt = ((double) (e - s))/CLOCKS_PER_SEC;
	printf("Time taken for arr %f",tt);

    //end
    return 0;
}
// pushing the element into the stack
int push(int elem){
    if(top > 100000){
        printf("Overflow");
    }else{
        top++;
        arr[top] = elem;
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
        printf("Emtpy");
    }
    arr[top] = 0;
    top--;
}


// for array

void rem(int elem){
	for(int i = 0; i < 100000; i++){
		if(bigarr[i] == elem){
			printf("[+] Found\n");
		}
	}
}