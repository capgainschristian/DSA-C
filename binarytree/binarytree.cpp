#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"

struct Node *root=NULL;

void Treecreate()
{
    struct Node *p,*t;
    int x;
    struct Queue q;
    create(&q,100);

    printf("Enter root value: ");
    scanf("%d", &x);
    root=(struct Node *)malloc(sizeof(struct Node));
    root->data=x;
    root->lchild=root->lchild=NULL;
    enqueue(&q,root);

    while(!isEmpty(q))
    {
        p=dequeue(&q);
        printf("enter the left child of %d: ", p->data);
        scanf("%d",&x);
        if(x!=-1)
        {
            t=(struct Node *)malloc(sizeof(struct Node));
            t->data=x;
            t->lchild=t->rchild=NULL;
            p->lchild=t;
            enqueue(&q,t);
        }
        printf("enter the right child of %d: ", p->data);
        scanf("%d",&x);
        if(x!=-1)
        {
            t=(struct Node *)malloc(sizeof(struct Node));
            t->data=x;
            t->lchild=t->rchild=NULL;
            p->rchild=t;
            enqueue(&q,t);
        }
    }
}

void Preorder(struct Node *p)
{
    if(p)
    {
        printf("%d ", p->data);
        Preorder(p->lchild);
        Preorder(p->rchild);
    }
}

void Inorder(struct Node *p)
{
    if(p)
    {
        Inorder(p->lchild);
        printf("%d ",p->data);
        Inorder(p->rchild);
    }
}
void Postorder(struct Node *p)
{
    if(p)
    {
        Postorder(p->lchild);
        Postorder(p->rchild);
        printf("%d ",p->data);
    }
}

void LevelOrder(struct Node *root)
{
    struct Queue q;
    create(&q,100);

    printf("%d ", root->data);
    enqueue(&q,root);

    while(!isEmpty(q))
    {
        root=dequeue(&q);
        if(root->lchild)
        {
            printf("%d ", root->lchild->data);
            enqueue(&q,root->lchild);
        }
         if(root->rchild)
        {
            printf("%d ", root->rchild->data);
            enqueue(&q,root->rchild);
        }       
    }
}

int count(struct Node *root)
{
    if(root)
        return count(root->lchild)+count(root->rchild)+1;
        return 0;
}

int height(struct Node *root)
{
    int x=0,y=0;
    if(root==0)
        return 0;
    x=height(root->lchild);
    y=height(root->rchild);
    if(x>y)
        return x+1;
    else
        return y+1;
}

int main()
{
    Treecreate();

    printf("Count %d ", count(root));
    printf("Height %d ", height(root));

    return 0;
}