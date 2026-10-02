#include <stdio.h>

#define n 5

int stack[n];
int top = -1;

void push(int value){
    if(top == n-1){
        printf("Stack Overflow!\n");
    } else{
        top++;
        stack[top] = value;
        printf("%d is pushed onto the stack\n", value);
    }
}

void pop(){
    int item;

    if(top == -1){
        printf("Stack Underflow!\n");
    } else{
        item = stack[top];
        top--;
        printf("%d has been popped off the stack!\n", item);
    }
}

void peek(){
    if(top == -1){
        printf("Stack Empty!\n");
    } else{
        printf("%d\n", stack[top]);
    }
}

void display(){
    int i;

    if(top == -1){
        printf("Stack Empty!\n");
    } else{
        for(i = top; i >= 0; i--){
            printf("%d\t", stack[i]);
        }
        printf("\n");
    }
}

void isEmpty(){
    if(top == -1){
        printf("Stack Empty!\n");
    } else{
        printf("Stack not Empty!\n");
    }
}

void isFull(){
    if(top == n-1){
        printf("Stack Full!\n");
    } else{
        printf("Stack Not Full!\n");
    }
}

int main(){
    push(10);
    push(110);
    push(110);
    push(110);
    push(110);
    push(110);
    push(110);

    pop();
    peek();
    display();
    isEmpty();
    isFull();

    return 0;
}