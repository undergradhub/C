#include<stdio.h>
int main(){
int temp;
    int arr[5] = {0,5,3,200,-1};
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            if(arr[j] > arr[j+1]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

    for(int k = 0; k < 5; k++){
        printf("%d\n",arr[k]);
    }
}


/*
Time Complexities:

Worst Case Complexity:O(n2)
If we want to sort in ascending order and the array is in descending order then, the worst case occurs.

Best Case Complexity:O(n)
If the array is already sorted, then there is no need for sorting.

Average Case Complexity:O(n2)
It occurs when the elements of the array are in jumbled order (neither ascending nor descending).
*/