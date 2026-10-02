#include <stdlib.h>
#include <stdio.h>

struct node{
    int data;
    struct node *next;
};

void display(struct node *head){
    struct node *temp = head;

    while(temp != 0){
        printf("%d\t", temp->data);
        temp = temp->next;
    }
}

void insert_beg(struct node **head){
    struct node *newnode;

    newnode=(struct node*)malloc(sizeof(struct node));

    printf("enter data at beginning: ");
    scanf("%d",&newnode->data);

    newnode->next=*head;
    *head=newnode;
}

void insert_end(struct node *head){
    struct node *newnode, *temp;

    newnode = (struct node*)malloc(sizeof(struct node));

    printf("enter data at end: ");
    scanf("%d", &newnode->data);

    newnode->next = 0;

    temp = head;

    while(temp->next != 0){
        temp = temp->next;
    }

    temp->next = newnode;
}

void insert_position(struct node *head){
    struct node *newnode, *temp;
    int pos, i;

    newnode = (struct node*)malloc(sizeof(struct node));

    printf("enter data: ");
    scanf("%d", &newnode->data);

    printf("enter position: ");
    scanf("%d", &pos);

    temp = head;

    for(i = 1; i < pos - 1; i++){
        temp = temp->next;
    }

    newnode->next = temp->next;
    temp->next = newnode;
}

void main(){

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

     printf("\nOriginal list:\n");
    display(head);


    // TEST CASE 1: INSERT AT BEGINNING

    printf("\n\n--- Insert at Beginning ---\n");

    insert_beg(&head);

    printf("After insertion:\n");
    display(head);


    // TEST CASE 2: INSERT AT END

    printf("\n\n--- Insert at End ---\n");

    insert_end(head);

    printf("After insertion:\n");
    display(head);


    // TEST CASE 3: INSERT AT POSITION

    printf("\n\n--- Insert at Position ---\n");

    insert_position(head);

    printf("After insertion:\n");
    display(head);
}