#include <stdio.h>
#include <stdlib.h>
 
struct btnode
{
    int owner_id;
    int value;
    char owner_name[20];
    
    struct btnode *l;
    struct btnode *r;
}*root = NULL;
 
// Function Prototype
void printout(struct btnode*);
struct btnode* newnode(int);
struct btnode* genesis(int);
struct btnode* add_leftchild(struct btnode*,int);
struct btnode* add_rightchild(struct btnode*,int);

void main()
{
    root=genesis(30);
    add_leftchild(root,17);
    add_rightchild(root,10);
    //root->l=newnode(17);
    //root->r=newnode(10);
   
    printf("Tree elements are\n");
    printf("Displayed in order\n");
    printout(root);
    printf("\n");
}
 
// Create a node
struct btnode* newnode(int value)
{
    struct btnode* node = (struct btnode*)malloc(sizeof(struct btnode));
    node->value = value;
    node->l = NULL;
    node->r = NULL;
    return(node);
}

struct btnode* genesis(int value)
{
    struct btnode* genesis= (struct btnode*)malloc(sizeof(struct btnode));
    genesis->value = value;
    genesis->l = NULL;
    genesis->r = NULL;
    return(genesis);
}
 
 
struct btnode* add_leftchild(struct btnode *parent, int child_value)
{
    struct btnode* child =(struct btnode*)malloc(sizeof(struct btnode));
    child->value = child_value;
    
    if(parent->l == NULL)
        parent->l = child;
    
    else
    {
        struct btnode* temp = parent->l;
        while(temp->l != NULL)
            temp = temp->l;
        temp->l = child;
    }
    return child;
}

struct btnode* add_rightchild(struct btnode *parent, int child_value)
{
    struct btnode* child =(struct btnode*)malloc(sizeof(struct btnode));
    child->value = child_value;
    
    if(parent->r == NULL)
        parent->r = child;
    
    else
    {
        struct btnode* temp = parent->r;
        while(temp->r != NULL)
            temp = temp->r;
        temp->r = child;
    }
    return child;
}

// to display the tree in inorder
void printout (struct btnode *tree)
{
    if (tree->l)
        printout(tree->l);
    printf("%d->", tree->value);
    if (tree->r)
        printout(tree->r);
}
