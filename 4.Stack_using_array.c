// Stack using array 

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
            printf("%d\t",Stack[i]);
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



int main(){
    
}