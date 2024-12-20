// Circular Linked List 

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node{
    int data;
    struct node*next;
};

struct node* rear=NULL;
 
bool isEmpty(){
    return rear==NULL;
}
int count(){
    int c=0;
    if (isEmpty()){
        return 0;
    }
     
    struct node* temp = rear->next;
    do {
        c++;
        temp = temp->next;
    } while (temp != rear->next); 
        
    return c;
    
}

void Insert_start(int data){
    struct node* N;
    N=(struct node*)malloc(sizeof(struct node));
    N->data=data;
    if (isEmpty()){
        N->next=N;
        (rear)=N;
    }
    else{
        N->next=(rear)->next;
        (rear)->next=N;
    }
}
void Insert_last(int data){
    struct node* N;
    N=(struct node*)malloc(sizeof(struct node));
    N->data=data;
    if (isEmpty(rear)){
        N->next=N;
        (rear)=N;
    }
    else{
        N->next=rear->next;
        rear->next=N;
        rear=N;
    }
}
void Insert_pos(int data,int pos){
    if (pos==1 || isEmpty()==true){
        Insert_start(data);
    }
    else if(pos-1==count()){
        Insert_last(data);
    }
    else if (pos<1 || pos+1>count()){
        printf("Invalid Position \n");
    }
    else{
        struct node* N;
        N=(struct node*)malloc(sizeof(struct node));
        N->data=data;
        struct node* temp=rear->next;
        while (pos>2){
            temp=temp->next;
            pos--;
        }
        N->next=temp->next;
        temp->next=N;

    }
    
}
void print(){
    if (isEmpty()){
        printf("Linked List is empty\n");
    }
    else {
        printf("The linked list is : \n");
        struct node* temp = rear->next;
        do {
            printf("%d\t", temp->data);
            temp = temp->next;
        } while (temp != rear->next); 
        printf("\n");
    }
    
}

int main(){
    
    Insert_start(40);
    Insert_start(60);
    Insert_start(70);
    Insert_last(100);
    Insert_pos(50,67);
    print();
    printf("The total node in LL is %d",count());

    return 0;
}