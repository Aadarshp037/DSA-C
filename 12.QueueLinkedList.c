//   Queue using Linked List

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
struct node{
    int data;
    struct node*next;
};
struct node* head=NULL;
struct node* rear=NULL;
bool isEmpty(){
    return rear==NULL;
}  
void count(){
    struct node* temp;
    temp=head;
    int c=0;
    while (temp!= NULL){
        c++;
        temp=temp->next;
    }
    printf("The number of elements in %d ",c);
  
}
void Enqueue(int data){
    struct node *N;
    N= (struct node*)malloc(sizeof(struct node));
    N->data=data;
    N->next=NULL;
    if (isEmpty()){
        N->next=head;
        head=N;
        rear=N;
    }
    else{
        struct node* temp;
        temp=head;
        while (temp->next!=NULL){
            temp= temp->next;
        }
        temp->next=N;
        rear=N;
    }
}

void Dequeue(){
    struct node* temp;
    temp=head;
    if (isEmpty()){
        printf("Queue underflow\n");
    }
    else{
        head=head->next;
    }
    free(temp);
    temp=NULL;
}

int getFront(){
    if (isEmpty()){
        printf("Queue underflow\n");
        return 0;
    }
    return head->data;
}
int getRear(){
    if (isEmpty()){
        printf("Queue underflow\n");
        return 0;
    }
    return rear->data;
}   
void print(){ 
    struct node* temp;
    temp=head;
    if (head==NULL){
        printf("List is empty\n");
    }
    while (temp!= NULL){
        printf("%d\t", temp->data);
        temp=temp->next;
    }
    printf("\n");
}
int main(){
    Enqueue(10);
    Enqueue(20);
    Enqueue(30);
    Enqueue(40);
    Enqueue(50);
    Dequeue();
    print();
    printf("The front element in queue is %d \n",getFront());
    printf("The rear element in queue is %d \n",getRear());
    count();
    return 0;
}
