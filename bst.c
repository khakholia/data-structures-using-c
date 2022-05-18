#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *left, *right;
};
struct Node * create(int data)
{
    struct Node *obj = (struct Node *)malloc(sizeof(struct Node));
    obj->data = data;
    obj->left = obj->right = NULL;
    return obj;
}
struct Node * insert(struct Node *tree, int data)
{
    if (tree == NULL)
    {
        return create(data);
    }
    if (data < tree->data)
    {
        tree->left=insert(tree->left, data);
    }
    else
    {
        tree->right=insert(tree->right, data);
    }
    return tree;
}
void inorder(struct Node* root)
{
    if (root != NULL) {
        inorder(root->left);
        printf("%d \n", root->data);
        inorder(root->right);
    }
}
void main()
{
    struct Node *tree = NULL;
    // tree=insert(tree,20);
    // insert(tree,19);
    // insert(tree,40);
    // insert(tree,1);
    // insert(tree,66);
    // insert(tree,22);
    // insert(tree,9);
    // insert(tree,11);
    // inorder(tree);
    while (1)
    {
        printf("\n1 insert\n2 inorder");
        int action;
        scanf("%d", &action);
        if (action)
        {
            int data;
            scanf("%d", &data);
            tree = insert(tree, data);
        }else{
            inorder(tree);
        }
    }
}