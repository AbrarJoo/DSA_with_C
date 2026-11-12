#include <stdio.h>
#include <stdlib.h>

void push(int);
void pop();
void display();
void peek();


int main() {

    printf("\nInitial stack:\n");
    display();

    printf("\n\nTesting POP on empty stack:\n");
    pop();

    printf("\n\nTesting PEEK on empty stack:\n");
    peek();

    printf("\n\nPushing elements:\n");
    push(10);
    push(20);
    push(30);

    printf("\nDisplaying stack:\n");
    display();

    printf("\n\nTesting PEEK:\n");
    peek();

    printf("\n\nTesting POP:\n");
    pop();

    printf("\nDisplaying stack:\n");
    display();

    printf("\n\nRemoving remaining elements:\n");
    pop();
    pop();

    printf("\n\nTesting POP again:\n");
    pop();

    return 0;
}

struct node {
    int data;
    struct node *link;
};


struct node *top=0;

void push(int x){
    struct node *newnode;
    newnode=(struct node *)malloc(sizeof(struct node));

    newnode->data=x;
    newnode->link=top;
    top=newnode;
}

void pop(){
    struct node *temp;
    temp=top;
    if(top==0){
        printf("empty stack");
    }else{
        printf("%d Popped\n",top->data);
        top=top->link;
        free(temp);
    }
}

void display(){
    struct node *temp;
    temp=top;

    if(top==0){
        printf("stack is empty");
    } else {
        while(temp!=0){
            printf("%d\t",temp->data);
            temp=temp->link;
        }
    }
}

void peek(){
    if(top==0){
        printf("stack is empty");
    } else{
        printf("Top = %d\n",top->data);
    }
}