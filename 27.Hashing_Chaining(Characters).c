// Hashing by chaining for characters

#include <stdio.h>
#include <stdlib.h>
#define max 10

typedef struct node {
    char key;       
    struct node* next;
} Node;

Node* Hash[max];  


Node* CreateNode(char key) {
    Node* N = (Node*)malloc(sizeof(Node));
    if (N == NULL) {
        printf("Memory allocation failed\n");
        exit(1); 
    }
    N->key = key;
    N->next = NULL;  
    return N;
}

void Hashing(char key) {
    int set = key % max;  
    Node* N1 = CreateNode(key);

    if (Hash[set] == NULL) {
        Hash[set] = N1;  
    } else {
        N1->next = Hash[set];  
        Hash[set] = N1;        
    }
}


void CreateHash() {
    int x;
    printf("Enter the number of characters: ");
    scanf("%d", &x);

    for (int i = 0; i < max; i++) {
        Hash[i] = NULL;
    }

    for (int i = 0; i < x; i++) {
        char n;
        printf("Enter character %d: ", i + 1);
        scanf(" %c", &n);  
        Hashing(n);
    }
}

void DisplayHash() {
    for (int i = 0; i < max; i++) {
        printf("Hash[%d]: ", i);
        Node* temp = Hash[i];
        while (temp != NULL) {
            printf("%c -> ", temp->key);  
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

int main() {
    printf("This is the character hash program\n");
    CreateHash();   
    DisplayHash(); 

    return 0;
}