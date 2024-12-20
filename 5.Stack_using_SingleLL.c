// Stack Using Single linked List

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

bool isEmpty(struct node* top){
    if (top==NULL){
        return true;
    }
    return false;
}
void push(int data, struct node** top){
    struct node* N;
    N= (struct node*)malloc(sizeof(struct node));
    N->data=data;
    N->next=(*top);
    (*top)=N;
}
void pop(struct node** top){
    if (isEmpty(*top)){
        printf("Stack is already empty\n");
    }
    else{
        struct node* curr;
        curr=*top;
        (*top)=curr->next;
        free(curr);
        curr=NULL;
    }
}
void peek(struct node* top){
    if (isEmpty(top)){
        printf("The stack has no elements to show \n"); 
    }
    else{
        printf("%d\n",(top)->data);
    }
}


int main(){
    struct node* top=NULL;
    pop(&top);
    peek(top);

    return 0;

}