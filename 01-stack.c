#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *link;
};
int stack[100];
int stackTop=0;
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
        struct Node *toBeFreed=top;
        top = top->link;
        free(toBeFreed);
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
void pushIntoArray(){
    if(stackTop==100){
        printf("Full!!\n");
    }else{
        printf("\nEnter the number: ");
        scanf("%d",&stack[stackTop]);
        stackTop++;
    }
}
void popFromArray(){
    if(stackTop==0){
        printf("Empty!!\n");
    }else{
        stackTop--;
    }
}
void displayArrayStack(){
    printf("\nElements!!\n");
    for(int i=(stackTop-1); i>=0;i--){
        printf("%d\n",stack[i]);
    }
}
void usingArray(){
    int choice1=-1;
    printf("\nStack (Array)");
    while(choice1!=0){
        printf("\nChoose any one\n0 Exit\n1 Push\n2 Pop\n3 Traverse\nSelect:- ");
        scanf("%d",&choice1);
        switch (choice1)
        {
            case 0:{
                return;
            }
            case 1:{
                pushIntoArray();
                break;
            }
            case 2:{
                popFromArray();
                break;
            }
            case 3:{
                displayArrayStack();
                break;
            }
            default:{
                printf("\nPlease enter between 0-3 only!!!\n");
            }
        }
    }
}
void usingLL(){
    int choice=-1;
    printf("\nStack (Linked List)");
    while(choice!=0){
        printf("\nChoose any one\n0 Exit\n1 Push\n2 Pop\n3 Traverse\nSelect:- ");
        scanf("%d",&choice);
        switch(choice){
            case 0:{
                return;
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
void main(){
    int select=-1;
    while (select!=0)
    {
        printf("\nChoose any one\n0 Exit\n1 Linked List\n2 Array\nSelect:- ");
        scanf("%d",&select);
        switch (select)
        {
        case 0:
            exit(0);
            break;
        case 1:
            usingLL();
            break;
        case 2:
            usingArray();
            break;
        default:
            printf("\nPlease enter between 0-2 only!!!\n");
        }
    }
    
    

    
}