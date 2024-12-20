//      Single Linked List 

#include <stdio.h>

#include <stdlib.h>
#include <string.h>
struct node{
    int data;
    struct node* next;
};
int count(struct node* head){
    struct node* temp;
    temp=head;
    int c=0;
    while (temp!= NULL){
        c++;
        temp=temp->next;

    }
    return c;
  
}
void print(struct node* head){ 
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
void Insert_at_start(int data, struct node **head){
    struct node *N;
    N= (struct node*)malloc(sizeof(struct node));
    N->data=data;
    N->next=*head;
    *head=N;

}
void Insert_at_last(int data, struct node** head){
    struct node *N;
    N= (struct node*)malloc(sizeof(struct node));
    N->data=data;
    N->next=NULL;
    if (*head==NULL){
        N->next=*head;
        *head=N;
    }
    else{
        struct node* temp;
        temp=*head;
        while (temp->next!=NULL){
            temp= temp->next;
        }
        temp->next=N;
       
    }
   
}
struct node* Insert_after(int data,int target,struct node* head){
    struct node *temp,*N;
    N= (struct node*)malloc(sizeof(struct node));
    N->data=data;
    temp=head;
    while (temp->data!=target){
        temp=temp->next;
    }
    N->next=temp->next;
    temp->next=N;
    return head;
}
struct node* Insert_at_certain_position(int data,int pos,struct node* head){
    if (head==NULL || pos==1){
        Insert_at_start(data,&head);
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
        temp->next=N;
    }
    return head;
}
struct node* Insert_before(int data,int target,struct node* head){
    struct node *temp,*N;
    N= (struct node*)malloc(sizeof(struct node));
    N->data=data;
    if (head==NULL || head->data==target){
        N->next=head;
        head=N;
    }
    else{
        temp=head;
        while (temp->next->data!=target){
            temp=temp->next;
    }
        N->next=temp->next;
        temp->next=N;
    }
    return head;
}
struct node* Delete_first(struct node*head){
    struct node* temp;
    temp=head;
    if (temp==NULL){
        printf("The list is already empty\n");
    }
    else{
        head=head->next;
    }
    free(temp);
    temp=NULL;
    return head;
}
struct node* Delete_last(struct node*head){
    struct node* temp;
    struct node* curr;
    
    if (head==NULL){
        printf("The list is already empty\n");
    }
    else if (head->next==NULL){
        free(head);
        head=NULL;
    }
    else{
        temp=head;
        while (temp->next->next!=NULL){
            temp=temp->next;
        }
        curr=temp->next;
        temp->next=NULL;
        free(curr);
        curr=NULL;
    }
    return head;
}
struct node* Delete_element(int num,struct node*head){
    struct node* temp;
    struct node* curr;
    temp=head;
    if (head==NULL){
        printf("The list is already empty\n");
    }
    else if(head->next==NULL){
        if (head->data==num){
            free(head);
            head=NULL;
        }
        else{
            printf("%d element is not found\n",num);
        }
        
    }
    else {
        while(temp->next->data!=num){
             temp=temp->next;
        }
        curr=temp->next;
        temp->next=curr->next;
        free(curr);
        curr=NULL;
    }
    
    return head;
}

void Reverseprint(struct node*head){
    if (head==NULL){
        return;
    }
    Reverseprint(head->next);
    printf("%d\t",head->data);
}

void Middle(struct node* head){
    if (head==NULL){
        return;
    }
    struct node*temp=head;
    int k=count(head);
    if (k%2==0){
        k=k/2;
    }
    else{
        k=k/2 +1;
    }
    for (int i=1;i<k;i++){
        temp=temp->next;
    }
    printf("%d\n",temp->data);
}
int main(){
    struct node *head=NULL;
      Insert_at_start(40,&head);
      Insert_at_start(60,&head);
      Insert_at_last(50,&head);
    //   Insert_at_last(45,&head);
      head=Insert_after(20,40,head);
      head=Insert_after(80,50,head);
      head=Insert_before(96,40,head);
      head=Insert_before(75,60,head);
    //   head=Delete_first(head);
    //   head=Delete_last(head);
    //   head=Delete_element(60,head);
    
    print(head);
    Middle(head);
    
    Reverseprint(head);
    
    return 0;

}