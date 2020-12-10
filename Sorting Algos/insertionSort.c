#include<stdio.h>
void show(int arr[], int size){
    for(int i = 0; i < size; i++){
        printf("%d\t", arr[i]);
    }
}
int main(){
    int arr[5] = {5,1,0,4,2};
    int key;
    int j;
    printf("Array before sorting\n");
    show(arr,5);
    for(int i = 1; i < 5; i++){
        key = arr[i];
        printf("key %d\n",key);
        j = i - 1;
        while(arr[j] > key && j >= 0){
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key; 
        show(arr,5);
    }
}