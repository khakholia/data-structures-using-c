#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *link;
};

struct Node *top; 
void push(){
    struct Node *new = (struct Node*)malloc(sizeof(struct Node));  
    printf("\nEnter the number: ");
    scanf("%d",&(new->data));
    if(top==NULL){
        new->link=NULL;
        top=new;
    }else{
        new->link=top;
        top=new;
    }
    printf("Pushed!!\n");
}
void pop(){
    if(top==NULL){
        printf("Empty!!\n");
    }else{
        int val = top->data;
        top = top->link;
        printf("Popped!!\n");
    }
}
void display(){
    struct Node *copy;
    copy=top;
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
void main(){
    int choice=-1;
    printf("Stack (Linked List)");
    while(choice!=0){
        printf("\nChoose any one\n0 Exit\n1 Push\n2 Pop\n3 Traverse\nSelect:- ");
        scanf("%d",&choice);
        switch(choice){
            case 0:{
                exit(0);
            }
            case 1:{
                push();
                break;
            }
            case 2:{
                pop();
                break;
            }
            case 3:{
                display();
                break;
            }
            default:{
                printf("\nPlease enter between 0-3 only!!!\n");
            }
        }
    }
}