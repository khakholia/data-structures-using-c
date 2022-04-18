#include <stdio.h>

struct Data
{
    int partNo;
    int qty;
};
int hashVal(int key)
{
    return key % 20;
}

void main()
{
    // cretaing array
    struct Data inventory[20];

    // initializing to NULL
    for (int i = 0; i < 20; i++)
    {
        inventory[i].partNo = 0;
    }
    while (1)
    {
        int choice, collision;
        printf("\n1 Insert\n2 Search\n3 Collisions\n0 Exit\nSelect-");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Inserting...");
            // insert item
            int partNo, qty;
            printf("\nEnter part number- ");
            scanf("%d", &partNo);
            printf("\nEnter quantity- ");
            scanf("%d", &qty);

            int index = hashVal(partNo);
            while (inventory[index].partNo != 0)
            {
                index++;
                collision++;
            }
            inventory[index].partNo = partNo;
            inventory[index].qty = qty;
            break;
        case 2:
            // search item
            printf("Searching...");
            printf("\nEnter part number to search- ");
            int search, hIndex;
            scanf("%d", &search);
            hIndex = hashVal(search);
            while (inventory[hIndex].partNo != search)
            {
                hIndex++;
            }
            printf("\nPart No:- %d, Quantity:- %d", inventory[hIndex].partNo, inventory[hIndex].qty);
            break;
        case 3:
            printf("Collisions- %d", collision);
            break;
        case 4:
            for(int i=0;i<20;i++){
                printf("%d---%d\n",inventory[i].partNo,inventory[i].qty);
            }
        case 0:
            return;
        default:
            printf("\nInvalid Choice...");
            break;
        }
    }
}