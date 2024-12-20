#include <stdio.h>
#include <stdlib.h>
void Merge(int *A, int low, int high, int mid) {
    int i, j, k;
    int size = high - low + 1; 
    int *B = (int *)malloc(size * sizeof(int)); 

    i = low; 
    j = mid + 1; 
    k = 0; 

    while (i <= mid && j <= high) {
        if (A[i] < A[j]) {
            B[k] = A[i];
            i++;
        } else {
            B[k] = A[j];
            j++;
        }
        k++;
    }

    while (i <= mid) {
        B[k] = A[i];
        k++;
        i++;
    }

    while (j <= high) {
        B[k] = A[j];
        k++;
        j++;
    }
    for (i = 0; i < size; i++) {
        A[low + i] = B[i];
    }

    free(B); 
}

void MergeSort(int *A,int low,int high){
    int mid;
    if (low<high){
        mid=(low+high)/2;
        MergeSort(A,low,mid);
        MergeSort(A,mid+1,high);
        Merge(A,low,high,mid);
    }

}
void print(int *A,int n){
    for (int i=0;i<n;i++){
        printf("%d\t",A[i]);
    }
}
          
int main(){
    int A[]={2,8,1,9,5,3,24,11,27};
    int n=sizeof(A)/sizeof(int);
    MergeSort(A,0,n-1);
    print(A,n);
    return 0;
}
