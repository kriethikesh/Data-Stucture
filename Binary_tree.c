#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *left, *right;
};
struct node *create(int d)
{
    struct node *nn = (struct node *)malloc(sizeof(struct node));
    nn->data = d;
    nn->left = nn->right = NULL;
    return nn;
}
void printnodes(struct node *root)
{
    if (root != NULL)
    {
        printnodes(root->left);
        printf("%d ", root->data);
        printnodes(root->right);
    }
}
int main()
{
    struct node *root = create(200);
    struct node *n1 = create(10);
    struct node *n2 = create(20);
    struct node *n3 = create(30);
    struct node *n4 = create(40);
    struct node *n5 = create(50);
    root->left = n1;
    root->right = n2;
    n1->left = n3;
    n1->right = n4;
    n2->left = n5;
    printnodes(root);
    free(root);
    free(n1);
    free(n2);
    free(n3);
    free(n4);
    free(n5);
    return 0;
}