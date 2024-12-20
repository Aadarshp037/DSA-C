// Infix to postfix  

#include <stdio.h>  
#include <stdlib.h>  
#include <stdbool.h>  
  
#define max 10  
  
char Stack[max];  
int top = -1;  
  
int count(){  
    int k = 0;  
    for (int i = 0; i <= top; i++){  
        k++;  
    }  
    return k;  
}  

bool isFull(){  
    return top == max - 1;  
}  

bool isEmpty(){  
    return top == -1;  
}  

void push(char s){  
    if (isFull()){  
        printf("Empty\n");  
        return;  
    }  
    Stack[++top] = s;  
}  

char pop(){  
    if (isEmpty()){  
        printf("The stack is already empty\n");  
        return '\0';  
    }  
    return Stack[top--];  
}  

char peek(){  
    if (isEmpty()){  
        return '\0';  
    }  
    return Stack[top];  
}  

int precedence(char op) {  
    switch (op) {  
        case '+':  
        case '-': return 1;  
        case '*':  
        case '/': return 2;  
    }  
    return 0;   
}  

int is_operator(char ch) {  
    return ch == '+' || ch == '-' || ch == '*' || ch == '/';  
}  

void infix_to_postfix(char S[], char O[]) {  
    int i = 0;  
    int output = 0;  
    while (S[i] != '\0'){  
        if (is_operator(S[i])){  
            if (isEmpty()){  
                push(S[i]);  
            }  
            else {  
                if (precedence(S[i]) > precedence(peek())) {  
                    push(S[i]);  
                } else {  
                    char k = pop();  
                    O[output++] = k;  
                    push(S[i]);  
                }  
            }  
        }  
        else {  
            O[output++] = S[i];  
        }  
        i++;
    }  
   
    while (!isEmpty()) {
        O[output++] = pop();
    }
    
   
    O[output] = '\0';  
}  
  
int main(){  
    char S[] = "a+b+c-d";  
    char O[max] = "";  
    infix_to_postfix(S, O);   
    printf("Postfix Expression: %s\n", O);  
    return 0;  
}