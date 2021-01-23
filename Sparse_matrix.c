// ***************** Sparse Matrix ******************
#include<stdio.h>
void main(){
   int value,row,col,size=0;
   int matrix[3][4] = 
   {
       {0,0,0,3},
       {4,5,0,0},
       {0,0,0,6},
   };
   for(int i=0;i<3;i++){
       for(int j=0;j<4;j++){
           if(matrix[i][j] != 0){
               size++;
           }
       }
   }
   int newMat[3][size];
   int k =0;
   for(int i=0;i<3;i++){
       for(int j=0;j<4;j++){
           if(matrix[i][j]!=0){
               newMat[0][k] = i;
               newMat[1][k] = j;
               newMat[2][k] = matrix[i][j];
               k++;
           }
       }
   }
   printf("Sparse matrix is : \n");
   for(int i=0;i<3;i++){
       for(int j=0;j<size;j++){
           printf("%d ",newMat[i][j]);
       }
       printf("\n");
   }
}
