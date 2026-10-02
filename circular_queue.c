#include <stdio.h>
#define n 5

int queue[n];
int front=-1;
int rear=-1;

void enqueue(int value){
    if(front==-1 && rear==-1){
        front=rear=0;
        queue[rear]=value;
        printf("%d >>> queue\n",value);
    }else if( ((rear+1)%n)==front ){
        printf("Overflow!\n");
    } else{
        rear=(rear+1)%n;
        queue[rear]=value;
        printf("%d >>> queue\n",value);
    }
}

void dequeue(){
    if(front==-1&&rear==-1){
        printf("Underflow!\n");
    } else if(front == rear){
        printf("Dequeud--%d\n",queue[front]);
        front=rear=-1;
    } else{
        printf("Dequeud--%d\n",queue[front]);
        front=(front+1)%n;
    }
}

void display(){
    int i=front;
    if(front==-1 && rear==-1){
        printf("Empty!\n");
    } else{
        printf("Queue is: ");
            while(i!=rear){
            printf("%d ",queue[i]);
            i=(i+1)%n;
            }
        printf("\n");
    }
}

int main(){
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);

    display();

    dequeue();
    dequeue();

    display();

    enqueue(60);
    enqueue(70);

    display();

    enqueue(80);   // Should show Overflow

    return 0;
}