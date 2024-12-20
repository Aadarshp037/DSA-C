// Heap implementation 
#include <stdio.h>
#include <stdlib.h>
          

void Preorder(int A[], int i, int s) {
    if (i < s) {
        printf("%d\t", A[i]);
        Preorder(A, 2 * i + 1, s);
        Preorder(A, 2 * i + 2, s);
    }
}

void Postorder(int A[], int i, int s) {
    if (i < s) {
        Postorder(A, 2 * i + 1, s);
        Postorder(A, 2 * i + 2, s);
        printf("%d\t", A[i]);
    }
}

void Inorder(int A[], int i, int s) {
    if (i < s) {
        Inorder(A, 2 * i + 1, s);
        printf("%d\t", A[i]);
        Inorder(A, 2 * i + 2, s);
    }
}
void swap(int* A,int i,int l){
    int temp=A[i];
    A[i]=A[l];
    A[i]=temp;
}
void Heapify(int* A,int i,int size){
    int l= 2* i +1;
    int r= 2*i +2;
    int largest=i;

    if (l<size && A[l]>A[largest] ){
        largest=l;
    }
    if (r<size && A[r]>A[largest] ){
        largest=r;
    }
    if (largest!=i){
        swap(A,i,largest);
        Heapify(A,largest,size);
    }
   

    
}

void BuildHeap(int*A, int size){
    for (int i = size / 2 - 1; i >= 0; i--) {
        Heapify(A, i, size);
    }
}

void Delete_root(int *A,int* size){
    if (*size<=0) return;
    A[0]=A[*size-1];
    (*size)--;
    Heapify(A,0,*size);
}
int main(){
    int A[7] = {30, 40, 67, 67, 32, 13, 34};
    int size = sizeof(A) / sizeof(int);
    
  
    BuildHeap(A, size);
    
    printf("Heap before deletion:\n");
    printf("The preorder traversal is:\n");
    Preorder(A, 0, size);
    printf("\n");

    Delete_root(A, &size);

    printf("Heap after deletion:\n");
    printf("The preorder traversal is:\n");
    Preorder(A, 0, size);
    printf("\n");

    printf("The postorder traversal is:\n");
    Postorder(A, 0, size);
    printf("\n");
    return 0;
}