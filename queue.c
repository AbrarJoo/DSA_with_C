#include <stdio.h>
#define n 5

int queue[n];
int front=-1;
int rear=-1;

void enqueue(int value){
    if(rear==n-1){
        printf("Overflow!\n");
    } else if(front==-1 && rear==-1){
        front = rear=0;
        queue[rear]=value;
        printf("Enqueued-%d\n",value);
    } else{
        rear++;
        queue[rear]=value;
        printf("Enqueued-%d\n",value);
    }
}

void dequeue(){
    if(front==-1 && rear==-1){
        printf("Empty Queue!\n");
    } else if(front==rear){
        printf("Dequeud-%d\n",queue[front]);
        front=rear=-1;
    } else{
        printf("Dequeud-%d\n",queue[front]);
        front++;
    }
}

void display(){
    if(front==-1&&rear==-1){
        printf("Empty Queue\n");
    } else {
        for(int i=front;i<rear+1;i++){
            printf("%d\t",queue[i]);
        }
        printf("\n");
    }
}

void peek(){
    if(front==-1 && rear==-1){
        printf("Empty Queue!\n");
    } else{
        printf("Peeking -- %d\n",queue[front]);
    }
}

int main(){
    enqueue(10);
    enqueue(20);
    enqueue(30);

    display();

    peek();

    dequeue();
    dequeue();

    display();

    peek();

    enqueue(40);
    enqueue(50);

    display();

    dequeue();
    dequeue();
    dequeue();

    display();

    peek();
}