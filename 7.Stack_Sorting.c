// Sorting the given stack


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define max 10
int Stack1[max];
int Stack2[max];
int top1 = -1;
int top2 = -1;

bool isFull1() {
    return top1 == max - 1;
}
bool isFull2() {
    return top2 == max - 1;
}
bool isEmpty1() {
    return top1 == -1;
}
bool isEmpty2() {
    return top2 == -1;
}

void push1(int s) {
    if (isFull1()) {
        printf("Stack1 is full\n");
        return;
    }
    Stack1[++top1] = s;

}

void push2(int s) {
    if (isFull2()) {
        printf("Stack2 is full\n");
        return;
    }
    Stack2[++top2] = s;
}

int pop1() {
    if (isEmpty1()) {
        printf("Stack1 is already empty\n");
        return 0;
    }
    return Stack1[top1--];
}

int pop2() {
    if (isEmpty2()) {
        printf("Stack2 is already empty\n");
        return 0;
    }
    return Stack2[top2--];
}

int peek1() {
    if (isEmpty1()) {
        return -1;
    }
    return Stack1[top1];
}

int peek2() {
    if (isEmpty2()) {
        return -1;
    }
    return Stack2[top2];
}
void push(int s){
    if (isEmpty1()){
        push1(s);
    }
    else{
        if (s>=peek1()){
            push1(s);
        }
        else{
            while (s<peek1() || !isEmpty1()){
                push2(pop1());
            }
            push1(s);
            while (!isEmpty2()){
                push1(pop2());
            }
        }
    }
}

void printStack() {
    printf("Elements in Stack1:\n");
    for (int i = 0; i <= top1; i++) {
        printf("%d\t", Stack1[i]);
    }
    printf("\n");
}

int main(){
    push(40);
    push(50);
    push(60);
    push(30);
    push(20);
    printStack();
    return 0;
}