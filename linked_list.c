#include <stdlib.h>
#include <stdio.h>
// #define NULL 0
void main(){
    struct node{
        int data;
        struct node *next;
    };

    struct node *head,*newnode,*temp;
    head=0;
    int choice=1;

    while(choice){
        newnode=(struct node *)malloc(sizeof(struct node));
        printf("enter data\n");
        scanf("%d",&newnode->data);
        newnode->next=0;

        if(head==0){
            head=newnode;
            temp=newnode;
        }
        else{
            temp->next=newnode;
            temp=newnode;
        }

        printf("do u want to continue(0/1)");
        scanf("%d",&choice);
    }

    //printing
    temp=head;
    while(temp!=0){
        printf("%d\t",temp->data);
        temp=temp->next;
    }

}