#include <stdio.h>
#include <stdlib.h>
          
void InsertionSort(int *A,int n){
    for (int i=1;i<=n-1;i++){
        int key,j;
        key= A[i];
        j=i-1;
        while (j>=0 && A[j]>key){
            A[j+1]=A[j];
            j--;
        }
        A[j+1]=key;
    }
}

void print(int *A,int n){
    for (int i=0;i<n;i++){
        printf("%d\t",A[i]);
    }
}
          
int main(){
    int A[]={2,1,8,9,5};
    int n=5;
    InsertionSort(A,n);
    print(A,n);
    return 0;
}