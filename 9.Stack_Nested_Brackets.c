// Check the valid parenthesis or brackets Using Stack

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define max 10

char Stack[max];
int top=-1;
int count(){
    int k=0;
    for (int i=0;i<=top;i++){
        k++;
    }
    return k;
}
bool isFull(){
    return top==max-1;
}
bool isEmpty(){
    return top==-1;
}
void push(char s){
    if (isFull()){
        printf("Empty");
        return;
    }
    Stack[++top]=s;
}

void pop(){
    if (isEmpty()){
        printf("The stack is already empty");
        return;
    }
    top--;
}

char peek(){
    if (isEmpty()){
        return '\0';
    }
    return Stack[top];
}

bool check_balance(char* S){
    int i=0;
    while (S[i] !='\0'){
        if (S[i]=='{' || S[i]=='(' || S[i]=='['){
            push(S[i]);
        }
        else{
            if (isEmpty()){
                return false;
            }
            else if((S[i]=='}' && peek()=='{') || (S[i]==')' && peek()=='(') || (S[i]==']' && peek()=='[')){
                pop();
            }
            else{
                return false;
            }
        }
        i++;

    }
    return isEmpty();

}

int main(){
    char S[]="{[([])]}";
    bool a=check_balance(S);
    if (a){
        printf("Balanced\n");
    }
    else{
        printf("UnBalanced\n");
    }
 
    return 0;
}

