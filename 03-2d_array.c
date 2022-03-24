#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *link;
};
struct Header{
    struct Header *nextHeader;
    struct Node *dataLink;
    
};
struct Header *header;
void main(){
    int rows,cols;
    printf("Enter rows followed by cols of the Array(rows cols)");
    if(scanf("%d %d",&rows, &cols)==2){

        for(int i =0;i<rows;i++)
        {
            struct Header *newHeader = (struct Header*)malloc(sizeof(struct Header));
            
            struct Node *dataNode;
            for(int j=0;j<cols;j++){
                struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
                printf("Enter value for col %d row %d: ",i,j);
                scanf("%d",&(newNode->data));
                newNode->link=NULL;
                if(dataNode==NULL){
                    dataNode=newNode;
                }else{
                    dataNode->link= newNode;
                }
            }
            newHeader->dataLink=dataNode;
            if(header==NULL){
                header=newHeader;
            }else{
                header->nextHeader=newHeader;
            }

        }
        
        
    }else{
        printf("Enter valid rows and cols");
    }
    while(header->nextHeader!=NULL){
        struct Node *node=header->dataLink;
        while (node->link!=NULL)
        {
            printf("%d----",node->data);
        }
        printf("\n");
        
    }
}