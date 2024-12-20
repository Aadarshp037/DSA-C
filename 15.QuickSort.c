#include <stdio.h>
#include <stdlib.h>
int partition(int *A, int low, int high) {
    int pivot_index = (low + high) / 2; 
    int pivot = A[pivot_index];
    
    int temp = A[pivot_index];
    A[pivot_index] = A[high];
    A[high] = temp;

    int i = low - 1; 

    for (int j = low; j < high; j++) {
       
        if (A[j] <= pivot) {
            i++; 
          
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    }

    temp = A[i + 1];
    A[i + 1] = A[high];
    A[high] = temp;

    return i + 1; 
}

void QuickSort(int *A,int low,int high){
    int partition_index;
    if (low<high){
    partition_index= partition(A,low,high);
    QuickSort(A,low,partition_index-1);
    QuickSort(A,partition_index+1,high);
    }

}


void print(int *A,int n){
    for (int i=0;i<n;i++){
        printf("%d\t",A[i]);
    }
}
          
int main(){
    int A[]={2,1,8,9,5,3,24,11,27};
    int n=sizeof(A)/sizeof(int);
    QuickSort(A,0,n-1);
    print(A,n);
    return 0;
}



