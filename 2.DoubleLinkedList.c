// Doubly Linked List

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node{
    int data;
    struct node* next;
    struct node* prev;
};
void count(struct node* head){
    struct node* temp;
    temp=head;
    int c=0;
    while (temp!= NULL){
        c++;
        temp=temp->next;

    }
    printf("The number of elements in %d ",c);
  
}

void print(struct node* head){
    struct node* temp;
    temp=head;
    while (temp!=NULL){
        printf("%d \n",temp->data);
        temp=temp->next;
    }
    
}

struct node* Insert_start(int data,struct node* head){
    struct node* N;
    N=(struct node*)malloc(sizeof(struct node));
    N->data=data;
    N->next=head;
    N->prev=NULL;
    head=N;
    return head;
}
struct node* Insert_last(int data,struct node* head){
    struct node *N,*temp;
    N=(struct node*)malloc(sizeof(struct node));
    N->data=data;
    
    if (head==NULL){
        N->next=head;
        N->prev=NULL;
        head=N;
    }
    else{
        temp=head;
        while (temp->next!=NULL){
           temp=temp->next;
        }
        N->next=temp->next;
        N->prev=temp;
        temp->next=N;
    }
    return head;
   
}

struct node* Insert_at_certain_position(int data,int pos,struct node* head){
    if (head==NULL || pos==1){
        head=Insert_start(data,head);
    }
    else{
        struct node *temp,*N;
        N= (struct node*)malloc(sizeof(struct node));
        N->data=data;
        temp=head;
        for (int i=1;i<(pos-1);i++){
            temp=temp->next;
        }
        N->next=temp->next;
        N->prev=temp;
        temp->next=N;
    }
    return head;
}
struct node* Delete_first(struct node*head){
    if (head==NULL){
        printf("The list is already empty\n");
    }
    else{
        head=head->next;
        free(head->prev);
        head->prev=NULL;
        
    }
    return head;


}

struct node* Delete_last(struct node* head) {
    if (head == NULL) {
        printf("The list is already empty\n");
        return NULL;
    }

    if (head->next == NULL) {
        free(head);
        return NULL;
    }

   
    struct node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

   
    struct node* prevNode = temp->prev;
    prevNode->next = NULL;

   
    free(temp);

    return head;
}

struct node* Delete_position(int pos,struct node* head){
    struct node *temp,*temp1;
    if (head == NULL) {
       
        printf("The list is already empty\n");
        return NULL;
    }

    if (head->next == NULL ) {
       
        free(head);
        return NULL;
    }
    temp=head;
    while (pos>1){
        temp=temp->next;
        pos--;
    }
    temp1=temp->prev;
    temp1->next=temp->next;
    temp->next->prev=temp1;
    free(temp);
    temp=NULL;
    return head;

}


int main(){
    struct node *head=NULL;
    struct node* temp;
    head=Insert_start(40,head);
    head=Insert_start(50,head);
    head=Insert_last(60,head);
    head=Insert_at_certain_position(70,2,head);
    head=Delete_position(3,head);
    print(head);
    count(head);
    

    
    return 0;

}