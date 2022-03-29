#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct Mobile
{
    char model[100];
    char name[30];
    int capacipy;
    double price;
    struct Mobile *next;
};
struct Mobile *front;
struct Mobile *rear;
int size = 0;
void push()
{
    char model[100];
    char name[30];
    int capacity;
    double price;
    printf("****************");
    printf("\nModel\t\t:");
    scanf("%s", model);
    printf("\nBrand\t\t:");
    scanf("%s", name);
    printf("\nMemory\t\t:");
    scanf("%d", &capacity);
    printf("\nPrice\t\t:");
    scanf("%lf", &price);
    printf("****************");
    struct Mobile *new = (struct Mobile *)malloc(sizeof(struct Mobile));
    strcpy(new->model, model);
    strcpy(new->name, name);
    new->capacipy = capacity;
    new->price = price;
    if (front == NULL && rear == NULL)
    {
        front = rear = new;
    }
    else
    {
        rear->next = new;
        rear = new;
    }
    size++;
}
int pop()
{
    if (front == NULL)
    {
        printf("Empty!!\n");
    }
    else
    {
        // todo
        struct Mobile *toBeFreed = front;
        front = front->next;
        free(toBeFreed);
        size--;
        return 0;
    }
}

void display()
{
    struct Mobile *copy;
    copy = front;
    if (copy == NULL)
    {
        printf("Empty!!\n");
    }
    else
    {
        while (copy != NULL)
        {
            printf("Model\t\t:%s\n\nBrand\t\t:%s\n\nMemory\t\t:%d\n\nPrice\t\t:%lf\n--------\n", copy->model, copy->name, copy->capacipy, copy->price);
            copy = copy->next;
        }
    }
}
void sortPrice()
{
    struct Mobile *cpy=front;
    struct Mobile *x;
    while (cpy != NULL)
    {
        x=cpy->next;
        while (x != NULL)
        {
            // printf("%s---%s\n",cpy->name,x->name);

            if (cpy->price > x->price)
            {
                char model[100];
                char name[30];
                int capacity;
                double price;

                strcpy(model,cpy->model);
                strcpy(name,cpy->name);
                capacity=cpy->capacipy;
                price=cpy->price;

                strcpy(cpy->model,x->model);
                strcpy(cpy->name,x->name);
                cpy->capacipy=x->capacipy;
                cpy->price=x->price;

                strcpy(x->model,model);
                strcpy(x->name,name);
                x->capacipy=capacity;
                x->price=price;


            }
            
            x=x->next;
        }
        cpy=cpy->next;
    }
}
void sortBrand()
{
    printf("\n");
    struct Mobile *cpy=front;
    struct Mobile *x;
    while (cpy != NULL)
    {
        x=cpy->next;
        while (x != NULL)
        {
            // printf("%s---%s\n",cpy->name,x->name);
            if (strcmp(cpy->name, x->name)>1)
            {
                char model[100];
                char name[30];
                int capacity;
                double price;

                strcpy(model,cpy->model);
                strcpy(name,cpy->name);
                capacity=cpy->capacipy;
                price=cpy->price;

                strcpy(cpy->model,x->model);
                strcpy(cpy->name,x->name);
                cpy->capacipy=x->capacipy;
                cpy->price=x->price;

                strcpy(x->model,model);
                strcpy(x->name,name);
                x->capacipy=capacity;
                x->price=price;


            }
            
            x=x->next;
        }
        cpy=cpy->next;
    }
}
void sortBrandsByPrice(){
    sortBrand();
    printf("\n");
    struct Mobile *cpy=front;
    struct Mobile *x;
    while (cpy != NULL)
    {
        x=cpy->next;
        while (x != NULL)
        {
            // printf("%s---%s\n",cpy->name,x->name);
            if (cpy->price > x->price)
            {
                char model[100];
                char name[30];
                int capacity;
                double price;

                strcpy(model,cpy->model);
                strcpy(name,cpy->name);
                capacity=cpy->capacipy;
                price=cpy->price;

                strcpy(cpy->model,x->model);
                strcpy(cpy->name,x->name);
                cpy->capacipy=x->capacipy;
                cpy->price=x->price;

                strcpy(x->model,model);
                strcpy(x->name,name);
                x->capacipy=capacity;
                x->price=price;


            }
            x=x->next;
            if(cpy->name!=x->name){
                break;
            }
        }
        cpy=cpy->next;
    }
}
void main()
{
    //input n mobiles
    int loop;
    printf("Please enter number of mobiles you want to store-");
    scanf("%d", &loop);
    for (int i = 0; i < loop; i++)
    {

        push();
    }
    printf("\n\n\n\n\n\n");
    
    
    
    
    //read n mobiles from ll
    printf("\nRead\n");
    display();
    printf("\n\n\n\n\n\n");


    //sort with price
    printf("\nSort By Brand");
    sortBrand();
    display();
    printf("\n\n\n\n\n\n");

    // sort with price
    printf("\nSort By Price\n");
    sortPrice();
    display();
    printf("\n\n\n\n\n\n");

    // sort with price
    printf("\nSort By Brand & Price\n");
    sortBrandsByPrice();
    display();
    printf("\n\n\n\n\n\n");


}
