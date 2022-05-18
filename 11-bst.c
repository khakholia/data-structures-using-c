#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int key;
    struct Node *left, *right;
};
struct Node *searchNode(struct Node *root, int key)
{
    // printf("%d-------\n", root->key);
    // Base Cases: root is null or key is present at root
    if (root == NULL || root->key == key)
        return root;

    // Key is greater than root's key
    if (root->key < key)
        return searchNode(root->right, key);

    // Key is smaller than root's key
    return searchNode(root->left, key);
};

struct Node *createNode(int item)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

void inOrderDisplay(struct Node *root)
{
    if (root != NULL)
    {
        inOrderDisplay(root->left);
        printf("%d \n", root->key);
        inOrderDisplay(root->right);
    }
}

struct Node *insertIntoTree(struct Node *node, int key)
{
    if (node == NULL)
        return createNode(key);

    if (key < node->key)
        node->left = insertIntoTree(node->left, key);
    else if (key > node->key)
        node->right = insertIntoTree(node->right, key);

    return node;
}
void FloorAndCeil(struct Node *root, int key, int *floor, int *ceil)
{

    while (root)
    {

        if (root->key == key)
        {
            *ceil = root->key;
            *floor = root->key;
            return;
        }

        if (key > root->key)
        {
            *floor = root->key;
            root = root->right;
        }
        else
        {
            *ceil = root->key;
            root = root->left;
        }
    }
    return;
}
int main()
{
    /*        8
           /     \
          
          4       10
         /  \    /  \
        2    6  9   12 */
    struct Node *root = NULL;
    root = insertIntoTree(root, 2);

    insertIntoTree(root, 4);
    insertIntoTree(root, 6);

    insertIntoTree(root, 8);
    insertIntoTree(root, 9);
    insertIntoTree(root, 10);
    insertIntoTree(root, 12);

    inOrderDisplay(root);
    int searchKeys[] = {1,3,9,7};
    for (int i=0;i<4;i++)
    {
        int searchKey = searchKeys[i];
        printf("Searching:- %d...\n", searchKey);
        struct Node *searchRes = searchNode(root, searchKey);
        if (searchRes != NULL)
        {
            printf("Key: %d, Floor: %d, Ceil: %d\n", searchRes->key, searchKey == searchRes->key ? searchKey : 0, searchKey == searchRes->key ? searchKey : 0);
        }
        else
        {
            int ceil, floor;
            FloorAndCeil(root, searchKey, &floor, &ceil);
            printf("Key: %d, Ceil: %d, Floor: %d\n", searchKey, ceil, floor);
        }
    }

    return 0;
}