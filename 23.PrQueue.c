// Priority Queue using max heap

#include <stdio.h>
#include <stdlib.h>
          
void swap(int* A, int i, int l) {
    int temp = A[i];
    A[i] = A[l];
    A[l] = temp;
}

void Heapify(int* A, int i, int size) {
    int l = 2 * i + 1; 
    int r = 2 * i + 2; 
    int largest = i;

    if (l < size && A[l] > A[largest]) {
        largest = l;
    }
    if (r < size && A[r] > A[largest]) {
        largest = r;
    }
    if (largest != i) {
        swap(A, i, largest);
        Heapify(A, largest, size);
    }
}

void BuildHeap(int* A, int size) {
    for (int i = size / 2 - 1; i >= 0; i--) {
        Heapify(A, i, size);
    }
}

void Delete_root(int* A, int* size) {
    if (*size <= 0) return; 
    A[0] = A[*size - 1]; 
    (*size)--; 
    Heapify(A, 0, *size); 
}


void HeapSort(int* A,int size){
    if (size>0){
        swap(A,0,size-1);
        Heapify(A,0,size-1);
        HeapSort(A,size-1);
    }
}

void Print(int*A, int size){
    for (int i=0;i<size;i++){
        printf("%d\t",A[i]);
    }
}       
int Maximum(int* A, int size){
    if (size<=0){
        printf("Heap is empty");
        return '\0';
    }
    return A[0];
}

int ExtractMax(int*A,int* size){
    if (size<=0){
        printf("Heap is empty");
        return '\0';
    }
    int temp= A[0];
    Delete_root(A,size);
    return temp;
}

void HeapifyUp(int*A,int i,int size){
    while (i>1 && A[i]>A[(i-1) / 2]){
        swap(A,i,(i-1)/2);
        i=(i-1)/2;
    }
}

void IncreaseKey(int* A, int i, int key,int size){
    if (key<A[i]){
        printf("New Key is smaller\n");
        return;
    }
    A[i]=key;
    HeapifyUp(A,i,size);
}
int main(){
     int A[7] = {30, 88, 67, 67, 32, 13, 34};
    int size = sizeof(A) / sizeof(int);
   
    BuildHeap(A, size);
    Print(A,size);
    printf("\n");
    IncreaseKey(A,size-1,100,size);
    Print(A,size);
    printf("\n");
    HeapSort(A,size);
    printf("The heap after sorting is \n");
    Print(A,size);
    return 0;
}