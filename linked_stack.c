void main(){

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