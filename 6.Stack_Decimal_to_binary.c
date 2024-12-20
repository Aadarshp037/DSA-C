#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define max 10

int Stack[max];
int first=-1;

bool isFull(){
    if (first=max-1){
        return true;
    }
    return false;
}
bool isEmpty(){
    if (first==-1){
        return true;
    }
    return false;
}
void push(int data){
    first+=1;
    for (int i=first;i>0;i--){
        Stack[i]=Stack[i-1];
    }
    Stack[0]=data;
}

int pop(){
    if (isEmpty()){
        printf("The stack is already empty");
    }
    else{
    int value=Stack[0];
    for (int i=0;i<first;i++){
        Stack[i]=Stack[i+1];
    }
    first-=1;
    return value;
    }
}

void print(){
    if (isEmpty()){
        printf("The stack is already empty");
        return;
    }
    if (first==-1){
        printf("Stack is underflow");
    }
    else{
        for (int i=0;i<=first;i++){
            printf("%d",Stack[i]);
        }
    }
}
void peek(){
    if (isEmpty()){
        printf("The stack is already empty");
        return;
    }
    printf("%d\n",Stack[0]);
}
void Decimal_Binary(int x){
    int k=x;
    while (k!=1){
        if (k%2==0){
            k= k/2;
            push(0);
        }
        else{
            k=k/2;
            push(1);
        }
    }
    push(1);
    printf("The number %d in binary is ",x);
    print();
}
int main(){
    int x;
    printf("Enter any decimal to convert in binary : ");
    scanf("%d",&x);
    Decimal_Binary(x);
    return 0;
}



