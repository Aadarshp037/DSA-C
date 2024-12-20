// Reversing the stack element

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define max 10

typedef struct Stack{
    int Arr[max];
    int top;
}Stack;


Stack* createStack(){
    Stack* stack= (Stack*)malloc(sizeof(Stack));
    stack->top= -1;
    return stack;
}


bool isFull(Stack* stack){
    return stack->top==max-1;
}
bool isEmpty(Stack* stack){
    return stack->top==-1;
}

void push(Stack* stack,int s){
    if (isFull(stack)){
        printf("Stack overflow");
        return;
    }
    stack->Arr[++(stack->top)]=s;
}

int pop(Stack* stack){
    if (isEmpty(stack)){
        printf("Stack underflow");
        return 0;
    }
    return stack->Arr[(stack->top)--];
}

void ReverseStack(Stack* stack){
    Stack* auxStack1=createStack();
    Stack* auxStack2=createStack();
    while(!isEmpty(stack)){
        push(auxStack1,pop(stack));
    }
    while(!isEmpty(auxStack1)){
        push(auxStack2,pop(auxStack1));
    }
    while(!isEmpty(auxStack2)){
        push(stack,pop(auxStack2));
    }
}

void print(Stack* stack){
     if (isEmpty(stack)){
        printf("Stack underflow");
        return;
    }

    for (int i=0;i<=stack->top;i++){
        printf("%d\t",stack->Arr[i]);
    }
    
    printf("\n");
}


int main(){
    Stack* stack1=createStack();
    push(stack1,10);
    push(stack1,20);
    push(stack1,30);
    push(stack1,40);
    push(stack1,50);
    print(stack1);
    printf("The reversed stack is \n");
    ReverseStack(stack1);
    print(stack1);
}



