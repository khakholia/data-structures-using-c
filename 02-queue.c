#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *link;
};
struct Node *front; 
struct Node *rear; 
int size=0;
void enqueue(int data){
    struct Node *new = (struct Node*)malloc(sizeof(struct Node));  
    new->data=data;
    if(front==NULL && rear == NULL){
        front=rear=new;
    }else{
        rear->link=new;
        rear=new;
    }
    size++;
    printf("Pushed!!\n");
}
int dequeue(){
    if(front==NULL){
        printf("Empty!!\n");
    }else{
        int val = front->data;
        struct Node *toBeFreed=front;
        front = front->link;
        free(toBeFreed);
        printf("Popped!!\n");
        size--;
        return val;
    }
}
void removeNegetatives(){
    int n=size;
    for(int i=0;i<n;i++){
        int x = dequeue();
        if(x>-1){
            enqueue(x);
        }
    }
}
int sum(){
    int sum=0;
    for(int i=0;i<size;i++){
        int x = dequeue();
        sum+=x;
        enqueue(x);
    }
    return sum;
}
int average(){
    return (sum()/size);
}
void main(){
    int choice=-1;
    printf("\nQueue (Linked List)");
    while(choice!=0){
        printf("\nChoose any one\n0 Exit\n1 Enqueue\n2 Dequeue\n3 Sum\n4 Average\n5 Remove Negetatives\nSelect:- ");
        scanf("%d",&choice);
        switch(choice){
            case 0:{
                return;
            }
            case 1:{
                int n;
                printf("\nEnter the no of elements you want to enqueue:- ");
                scanf("%d",&n);
                for(int i=0;i<n;i++){
                    int data;
                    printf("\nEnter the number: ");
                    scanf("%d",&data);
                    enqueue(data);
                }
                break;
            }
            case 2:{
                dequeue();
                break;
            }
            case 3:{
                printf("\nSum:- %d\n",sum());
                break;
            }
            case 4:{
                printf("\nAverage:- %d\n",average());
                break;
            }
            case 5:{
                removeNegetatives();
                break;
            }
            default:{
                printf("\nPlease enter between 0-4 only!!!\n");
            }
            
        }
    }
}