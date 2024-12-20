// Min Heap

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
    int smallest = i;

    if (l < size && A[l] < A[smallest]) {
        smallest = l;
    }
    if (r < size && A[r] < A[smallest]) {
        smallest = r;
    }
    if (smallest != i) {
        swap(A, i, smallest);
        Heapify(A, smallest, size);
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

void HeapSort(int* A, int size) {
    BuildHeap(A, size);
    for (int i = size - 1; i > 0; i--) {
        swap(A, 0, i); 
        Heapify(A, 0, i); 
    }
}

void Print(int* A, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d\t", A[i]);
    }
    printf("\n");
}

int Minimum(int* A, int size) {
    if (size <= 0) {
        printf("Heap is empty\n");
        return -1; 
    }
    return A[0];
}

int ExtractMin(int* A, int* size) {
    if (*size <= 0) {
        printf("Heap is empty\n");
        return -1; 
    }
    int temp = A[0];
    Delete_root(A, size);
    return temp;
}

void HeapifyUp(int* A, int i) {
    while (i > 0 && A[i] < A[(i - 1) / 2]) {
        swap(A, i, (i - 1) / 2);
        i = (i - 1) / 2;
    }
}

void DecreaseKey(int* A, int i, int key) {
    if (key > A[i]) {
        printf("New Key is larger\n");
        return;
    }
    A[i] = key;
    HeapifyUp(A, i);
}

int main() {
    int A[7] = {30, 88, 67, 67, 32, 13, 34};
    int size = sizeof(A) / sizeof(int);
    
    BuildHeap(A, size);
    printf("Heap built from array:\n");
    Print(A, size);
    
    DecreaseKey(A, size - 1, 10); 
    printf("After decreasing key:\n");
    Print(A, size);
    
    HeapSort(A, size);
    printf("The heap after sorting is:\n");
    Print(A, size);
    
    return 0;
}