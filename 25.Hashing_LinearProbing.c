// Hashing using Linear Probing

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>  
#define MAX 10

int Hash[MAX];

void InitializeHash() {
    for (int i = 0; i < MAX; i++) {
        Hash[i] = -1; 
    }
}

int HashFunction(int key) {
    return key % MAX;
}

void Hashing(int key) {
    int index = HashFunction(key);

    while (Hash[index] != -1) {  
        if (Hash[index] == key) {  
            printf("Duplicate key %d found, skipping insertion.\n", key);
            return;
        }
       
        index = (index + 1) % MAX;
    }

    
    Hash[index] = key;
    printf("Inserted %d at index %d\n", key, index);
}

void DisplayHash() {
    printf("Hash Table Contents:\n");
    for (int i = 0; i < MAX; i++) {
        if (Hash[i] != -1) {
            printf("Index %d: %d\n", i, Hash[i]);
        } else {
            printf("Index %d: (empty)\n", i);
        }
    }
}

int main() {
    printf("This is the linear probing hash program for integers\n");

    InitializeHash();

    int n;
    printf("Enter the number of integers to insert: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int num;
        printf("Enter integer %d: ", i + 1);
        scanf("%d", &num);
        Hashing(num);
    }

    DisplayHash();

    return 0;
}