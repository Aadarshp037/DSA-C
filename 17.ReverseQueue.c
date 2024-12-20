// Reversing the given Queue


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define max 10
int Queue[max];
int front=-1;
int rear=-1;

int Stack1[max];

int top1=-1;
bool isFull1() {
    return top1 == max - 1;
}
bool isEmpty1() {
    return top1 == -1;
}

void push1(int s) {
    if (isFull1()) {
        printf("Stack1 is full\n");
        return;
    }
    Stack1[++top1] = s;
}

void pop1() {
    if (isEmpty1()) {
        printf("Stack1 is already empty\n");
        return;
    }
    top1--;
}



int peek1() {
    if (isEmpty1()) {
        return -1;
    }
    return Stack1[top1];
}


bool isEmpty(){
    return front==-1;
}

bool isFull() {
    return rear==max-1;
}

void Enqueue(int data){
    if (isFull()){
        printf("Queue overflow\n");
        return;
    }
    if (isEmpty()){
        front=0;
        rear++;
        Queue[rear]=data;
    }
    else{
        rear++;
        Queue[rear]=data;
    }
}

void Dequeue(){
    if (isEmpty()){
        printf("Queue underflow\n");
        return;
    }
    front++;
    if (front>rear){
        front=rear=-1;
    }
}
int getFront(){
    if (isEmpty()){
        printf("Queue underflow\n");
        return -1;
    }
    return Queue[front];
}
int getRear(){
    if (isEmpty()){
        printf("Queue underflow\n");
        return -1;
    }
    return Queue[rear];
}
void Reverse(){
    
    while (!isEmpty()){
        push1(getFront());
        Dequeue();
    }
    while (!isEmpty1()){
        Enqueue(peek1());
        pop1();
    }
}
void print() {
    if (isEmpty()) {
        printf("Queue underflow\n");
        return;
    }
    for (int i=front;i<=rear;i++){
        printf("%d\t",Queue[i]);
    }
    printf("\n");
}       

int main(){
    Enqueue(10);
    Enqueue(20);
    Enqueue(30);
    Enqueue(40);
    Enqueue(50);
    Enqueue(60);
    Enqueue(70);
    Enqueue(80);
    printf("The queue : \n");
    print();
   
    printf("The reversed queue is \n");
    Reverse();
    print();
    
   
    return 0;
}