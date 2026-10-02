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


// INSERT AT BEGINNING

void insert_beg(struct node **head){
    struct node *newnode;

    newnode = (struct node*)malloc(sizeof(struct node));

    printf("enter data at beginning: ");
    scanf("%d",&newnode->data);

    newnode->next = *head;
    *head = newnode;
}


// INSERT AT END

void insert_end(struct node *head){
    struct node *newnode, *temp;

    newnode = (struct node*)malloc(sizeof(struct node));

    printf("enter data at end: ");
    scanf("%d",&newnode->data);

    newnode->next = 0;

    temp = head;

    while(temp->next != 0){
        temp = temp->next;
    }

    temp->next = newnode;
}


// INSERT AT POSITION

void insert_position(struct node **head){
    struct node *newnode, *temp;
    int pos, i;

    newnode = (struct node*)malloc(sizeof(struct node));

    printf("enter data: ");
    scanf("%d",&newnode->data);

    printf("enter position: ");
    scanf("%d",&pos);

    // inserting at beginning
    if(pos == 1){
        newnode->next = *head;
        *head = newnode;
        return;
    }

    temp = *head;

    for(i = 1; i < pos - 1 && temp != 0; i++){
        temp = temp->next;
    }

    if(temp == 0){
        printf("Invalid position!\n");
        free(newnode);
        return;
    }

    newnode->next = temp->next;
    temp->next = newnode;
}


// DELETE AT BEGINNING

void delete_beg(struct node **head){
    struct node *temp;

    if(*head == 0){
        printf("linked list is empty!\n");
    }
    else{
        temp = *head;
        *head = (*head)->next;
        free(temp);
    }
}


// DELETE AT END

void delete_end(struct node **head){
    struct node *prenode, *temp;

    if(*head == 0){
        printf("linked list is empty!\n");
    }

    else if((*head)->next == 0){
        free(*head);
        *head = 0;
    }

    else{
        temp = *head;

        while(temp->next != 0){
            prenode = temp;
            temp = temp->next;
        }

        prenode->next = 0;
        free(temp);
    }
}


// DELETE AT POSITION

void delete_pos(struct node **head){
    struct node *nextnode, *temp;
    int pos, i = 1;

    if(*head == 0){
        printf("linked list is empty!\n");
        return;
    }

    printf("enter position\n");
    scanf("%d",&pos);

    // deleting first node
    if(pos == 1){
        temp = *head;
        *head = (*head)->next;
        free(temp);
        return;
    }

    temp = *head;

    while(i < pos - 1 && temp != 0){
        temp = temp->next;
        i++;
    }

    if(temp == 0 || temp->next == 0){
        printf("Invalid position!\n");
        return;
    }

    nextnode = temp->next;
    temp->next = nextnode->next;
    free(nextnode);
}


// REVERSE

void reverse(struct node **head)
{
    struct node *previous = 0;
    struct node *current = *head;
    struct node *nextNode;

    while(current != 0){
        nextNode = current->next;
        current->next = previous;

        previous = current;
        current = nextNode;
    }

    *head = previous;

    printf("List reversed\n");
}


void main(){

    struct node *head, *newnode, *temp;
    head = 0;
    int choice = 1;

    // CREATE LINKED LIST

    while(choice){
        newnode = (struct node*)malloc(sizeof(struct node));

        printf("enter data\n");
        scanf("%d",&newnode->data);

        newnode->next = 0;

        if(head == 0){
            head = newnode;
            temp = newnode;
        }
        else{
            temp->next = newnode;
            temp = newnode;
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

    insert_position(&head);

    printf("After insertion:\n");
    display(head);


    // TEST CASE 4: DELETE AT BEGINNING

    printf("\n\n--- Delete at Beginning ---\n");

    delete_beg(&head);

    printf("After deletion:\n");
    display(head);


    // TEST CASE 5: DELETE AT END

    printf("\n\n--- Delete at End ---\n");

    delete_end(&head);

    printf("After deletion:\n");
    display(head);


    // TEST CASE 6: DELETE AT POSITION

    printf("\n\n--- Delete at Position ---\n");

    delete_pos(&head);

    printf("After deletion:\n");
    display(head);


    // TEST CASE 7: REVERSE

    printf("\n\n--- Reverse List ---\n");

    reverse(&head);

    printf("After reversal:\n");
    display(head);
}