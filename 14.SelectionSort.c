#include <stdio.h>
#include <stdlib.h>
          
void SelectionSort(int *A,int n){
    int index_min;
    int temp;
    for (int i=0;i<n-1;i++){
        index_min=i;
        for (int j=i+1;j<n;j++){
            if (A[j]<A[index_min]){
                index_min=j;
            }
        }
        temp=A[i];
        A[i]=A[index_min];
        A[index_min]=temp;
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
    SelectionSort(A,n);
    print(A,n);
    return 0;
}