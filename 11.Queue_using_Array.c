// Queue using array

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define max 10
int Queue[max];
int front=-1;
int rear=-1;

bool isEmpty(){
    return front==-1;
}

bool isFull() {
    return (rear+1)%max==front;
}

void Enqueue(int data){
    if (isFull()){
        printf("Queue overflow\n");
        return;
    }
    if (front==-1){
        front=0;
    }
    rear= (rear+1)%max;
    Queue[rear]=data;
}

void Dequeue(){
    if (isEmpty()){
        printf("Queue underflow\n");
        return;
    }
    if (front==rear){
        front,rear=-1;
    }
    else{

    front= (front+1)%max;
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

void print() {
    if (isEmpty()) {
        printf("Queue underflow\n");
        return;
    }
    int i = front;
    while (true) {
        printf("%d\t", Queue[i]);
        if (i == rear) break;
        i = (i + 1) % max;
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
    printf("The queue : \n");
    print();
   
    
   
    return 0;
}