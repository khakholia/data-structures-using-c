#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};

struct Node *list;
struct Node *front;
void insert(int data)
{
    struct Node *new = (struct Node *)malloc(sizeof(struct Node));
    new->data = data;
    if (list == NULL)
    {
        list = new;
        front = new;
    }
    else
    {
        list->next = new;
        list = list->next;
    }
}
void display()
{
    struct Node *new = front;
    while (new != NULL)
    {
        printf("%d->", new->data);
        new = new->next;
    }
    printf("\n--\n");
}
void removeDuplicates()
{
    struct Node *new = front;
    while (new != NULL)
    {
        if (new->next != NULL)
        {
            while (new->data == new->next->data)
            {
                new->next = new->next->next;
            }
        }
        new = new->next;
    }
}
void main()
{
    for (int i = 0; i < 10; i++)
    {
        printf("Input %d-", i);
        int x = 0;
        scanf("%d", &x);
        insert(x);
    }
    display();
    removeDuplicates();
    display();
}