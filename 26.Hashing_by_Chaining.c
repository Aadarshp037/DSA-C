// Hashing by chaining 

#include <stdio.h>
#include <stdlib.h>
#define max 10

typedef struct node{
    int key;
    struct node* next;
}Node;


Node* Hash[max];
Node* CreateNode(int key){
    Node* N= (Node*)malloc(sizeof(Node));
    if (N==NULL){
        printf("mEMORY ALLOCATION FAILED");
        exit(1);
    }
    N->key=key;
    N->next=NULL;
    return N;
}

void Hashing(int key){
    int set= key%max;
    Node* N1=CreateNode(key);
    if (Hash[set]==NULL){
        Hash[set]=N1;
    }
    else{
        N1->next=Hash[set];
        Hash[set]=N1;
    }
    
}
void CreateHash(){
    int x;
    printf("Enter the number of keys : ");
    scanf("%d",&x);
    for (int i=0;i<x;i++){
        int n;
        scanf("%d",&n);
        Hashing(n);
    }
}

void DisplayHash() {
    for (int i = 0; i < max; i++) {
        printf("Hash[%d]: ", i);
        Node* temp = Hash[i];
        while (temp != NULL) {
            printf("%d -> ", temp->key);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}
int main(){
    printf("This is hash program\n");
    CreateHash();
    DisplayHash();
    
    return 0;
}