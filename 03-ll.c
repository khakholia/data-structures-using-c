// Part A Write a program that traverses a list implemented using a linked list and deletes the node following a node with a negative key
// Part B Write a program that creates a two-dimensional array using a linked list implementation. The nodes in the first column contain only two pointers,
// as shown in the attached Figure. The left pointer points to the next row. The right pointer points to the data in the row
#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *link;
};
struct Node *front; 
struct Node *rear; 
int size=0;
void push(int data){
    struct Node *new = (struct Node*)malloc(sizeof(struct Node));  
    new->data=data;
    if(front==NULL && rear == NULL){
        front=rear=new;
    }else{
        rear->link=new;
        rear=new;
    }
    size++;
}
int pop(){
    if(front==NULL){
        printf("Empty!!\n");
    }else{
        int val = front->data;
        struct Node *toBeFreed=front;
        front = front->link;
        free(toBeFreed);
        size--;
        return val;
    }
}

void display(){
    struct Node *copy;
    copy=front;
    if(copy==NULL){
        printf("Empty!!\n");
    }else{
        printf("\nElements!!\n");
        while(copy!=NULL){
            printf("%d\n", copy->data);
            copy=copy->link;
        }
    }
}
void removeFollowedByNegetative(){
    struct Node *new = front;
    if (new==NULL){
        return;
    }
    while (new->link !=NULL)
    {
        if(new->data<0){
            struct Node * toBeFreed = new->link;
            
            if(toBeFreed->link!=NULL){
                new->link=toBeFreed->link;
            }else{
                new->link=NULL;
            }
            
            free(toBeFreed);
        }
        new=new->link;
    }
    
}
void main(){
    int choice=-1;
    printf("\nQueue (Linked List)");
    while(choice!=0){
        printf("\nChoose any one\n0 Exit\n1 Push\n2 Pop\n3 Display\n4 Remove followed by negetatives\nSelect:- ");
        scanf("%d",&choice);
        switch(choice){
            case 0:{
                return;
            }
            case 1:{
                int n;
                printf("\nEnter the no of elements you want to insert:- ");
                scanf("%d",&n);
                for(int i=0;i<n;i++){
                    int data;
                    printf("\nEnter the number: ");
                    scanf("%d",&data);
                    push(data);
                }
                break;
            }
            case 2:{
                printf("Popped: %d",pop());
                break;
            }
            case 3:{
                display();
                break;
            }
            case 4: {
                removeFollowedByNegetative();
                break;
            }
            default:{
                printf("\nPlease enter between 0-4 only!!!\n");
            }
            
        }
    }
}