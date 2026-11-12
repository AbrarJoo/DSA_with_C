#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *front = 0;
struct node *rear = 0;

void enqueue(int x) {
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));

    newnode->data = x;
    newnode->next = 0;

    if (front == 0 && rear == 0) {
        front = rear = newnode;
    } else {
        rear->next = newnode;
        rear = newnode;
    }

    printf("%d Enqueued\n", x);
}

void dequeue() {
    struct node *temp;
    temp = front;

    if (front == 0 && rear == 0) {
        printf("Queue is empty\n");
    } else {
        printf("Dequeued %d\n", front->data);

        front = front->next;
        free(temp);

        if (front == 0) {
            rear = 0;
        }
    }
}

void display() {
    struct node *temp;

    if (front == 0 && rear == 0) {
        printf("Queue is empty\n");
    } else {
        temp = front;

        while (temp != 0) {
            printf("%d\t", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {

    printf("Initial Queue:\n");
    display();

    printf("\nTesting Dequeue:\n");
    dequeue();

    printf("\nEnqueue Operations:\n");
    enqueue(10);
    enqueue(20);
    enqueue(30);

    printf("\nDisplaying Queue:\n");
    display();

    printf("\nDequeue Operations:\n");
    dequeue();
    dequeue();

    printf("\nDisplaying Queue:\n");
    display();

    printf("\nRemoving Last Element:\n");
    dequeue();

    printf("\nTesting Empty Queue:\n");
    display();
    dequeue();

    printf("\nEnqueue After Emptying:\n");
    enqueue(40);
    enqueue(50);

    printf("\nDisplaying Queue:\n");
    display();

    return 0;
}
