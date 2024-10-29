#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Node
{
    int data;
    struct Node *next;
}*first=NULL,*second=NULL,*third=NULL;

void create(int A[], int n)
{
    int i;
    struct Node *t, *last;
    first=(struct Node *)malloc(sizeof(struct Node));
    first->data=A[0];
    first->next=NULL;
    last=first;

    for(i=1;i<n;i++)
    {
        t=(struct Node *)malloc(sizeof(struct Node));
        t->data=A[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
}

void create2(int A[], int n)
{
    int i;
    struct Node *t, *last;
    second=(struct Node *)malloc(sizeof(struct Node));
    second->data=A[0];
    second->next=NULL;
    last=second;

    for(i=1;i<n;i++)
    {
        t=(struct Node *)malloc(sizeof(struct Node));
        t->data=A[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
}

void Display(struct Node *p)
{
    while(p!=NULL)
    {
        printf("%d ",p->data);
        p=p->next;
    }
}

void RDisplay(struct Node *p)
{
    if(p!=NULL)
    {
        printf("%d ", p->data);
        RDisplay(p->next);
    }
}

void ReverseRDisplay(struct Node *p)
{
    if(p!=NULL)
    {
        ReverseRDisplay(p->next);
        printf("%d ", p->data);
    }
}

int count(struct Node *p)
{
    if(p!=NULL)
        return 1+count(p->next);
    else
        return 0;
}

int Sum(struct Node *p)
{
    int sum=0;
    while(p)
    {
        sum=sum+p->data;
        p=p->next;
    }
    return sum;
}

int Max(struct Node *p)
{
    int m=INT_MIN;
    while(p)
    {
        if(p->data > m)
            m=p->data;
        p=p->next;
    }
    return m;
}

struct Node * LSearch(struct Node *p, int key)
{
    // Implementing head-to-first
    struct Node *q=NULL;

    while(p!=NULL)
    {
        if(key==p->data)
        {
            q->next=p->next;
            p->next=first;
            first=p;
            return p;
        }
        q=p;
        p=p->next;
    }
    return NULL;
}

struct Node * RSearch(struct Node *p, int key)
{
    if(p==NULL)
        return NULL;
    if(key==p->data)
        return p;
    return RSearch(p->next, key);
}

void Insert(struct Node *p, int index, int x)
{
    struct Node *t;
    int i;
    if(index < 0 || index > count(p))
        return;
    t=(struct Node *)malloc(sizeof(struct Node));
    t->data=x;

    if(index == 0)
    {
        t->next=first;
        first=t;
    }
    else
    {
        for(i=0;i<index-1;i++)
            p=p->next;
        t->next=p->next;
        p->next=t;
    }
}

void InsertLast(struct Node *p, int x)
{
    struct Node *last, *t;
    t=(struct Node *)malloc(sizeof(struct Node));
    t->data=x;
    t->next=NULL;

    if(first==NULL)
        first=last=t;
    else
    {
        last=first;
        while(last->next)
            last=last->next;
        last->next=t;
        last=t;
    }
}

void SortedInsert(struct Node *p, int x)
{
    struct Node *q, *t;
    t=(struct Node *)malloc(sizeof(struct Node));
    t->data=x;
    t->next=NULL;

    if(first==NULL)
        first=t;
    else
    {
        while(p && p->data<x)
        {
            q=p;
            p=p->next;
        }
        if(p==first)
        {
            t->next=first;
            first=t;
        }
        else
        {
            t->next=q->next;
            q->next=t;
        }
    }
}

int Delete(struct Node *p, int index)
{
    struct Node *q=NULL;
    int x=-1,i;

    if(index < 1 || index > count(p))
        return -1;
    if(index==1)
    {
        q=first;
        x=first->data;
        first=first->next;
        free(q);
        return x;
    }
    else
    {
        for(i=0;i<index-1;i++)
        {
            q=p;
            p=p->next;
        }
        q->next=p->next;
        x=p->data;
        free(p);
        return x;
    }
    
}

int isSorted(struct Node *p)
{
    int x=-65536;

    while(p!=NULL)
    {
        if(p->data < x)
            return 0;
        x=p->data;
        p=p->next;
    }
    return 1;
}

void RemoveDuplicate(struct Node *p)
{
    struct Node *q=p->next;

    while(q!=NULL)
    {
        if(p->data!=q->data)
        {
            p=q;
            q=q->next;
        }
        else
        {
            p->next=q->next;
            free(q);
            q=p->next;
        }
    }
}

void RemoveDuplicateUnsorted(struct Node *p)
{
    struct Node *q=p->next;
    int hash[1000]={0};
    

    while(q!=NULL)
    {
        hash[p->data] = 1;
        if (hash[q->data] == 1)
        {
            p->next=q->next;
            free(q);
            q=p->next;
        }
        else
        {
            hash[q->data] = 1;
            p=q;
            q=q->next;
        }
    }
}

void Reverse(struct Node *p)
{
    struct Node *q=NULL,*r=NULL;

    while(p!=NULL)
    {
        r=q;
        q=p;
        p=p->next;
        q->next=r;
    }
    first=q;
}

void RReverse(struct Node *q, struct Node *p)
{
    if(p)
    {
        RReverse(p,p->next);
        p->next=q;
    } else
        first=q;
}

void Concat(struct Node *p, struct Node *q)
{
    third=p;

    while(p->next!=NULL)
        p=p->next;
    p->next=q;
}

void Merge(struct Node *p, struct Node *q)
{
    struct Node *last;
    if(p->data < q->data)
    {
        third=last=p;
        p=p->next;
        third->next=NULL;
    }
    else
    {
        third=last=q;
        q=q->next;
        third->next=NULL; 
    }
    while(p && q)
    {
        if(p->data < q->data)
        {
            last->next=p;
            last=p;
            p=p->next;
            last->next=NULL;
        }
        else
        {
            last->next=q;
            last=q;
            q=q->next;
            last->next=NULL;            
        }
    }
    if(p)
        last->next=p;
    if(q)
        last->next=q;
}

int isLoop(struct Node *f)
{
    struct Node *p, *q;
    p=q=f;

    do
    {
        p=p->next;
        q=q->next;
        q=q?q->next:q;
    } while (p && q && p!=q);
    
    if(p==q)
        return 1;
    else
        return 0;
}

int main()
{
    int A[]={1,6,3,7,5};
    int B[]={50,20,10,30,40};
    create(A,5);
    create2(B,5);
    Merge(first, second);

    printf("Third\n");
    Display(third);
    printf("\n\n");
      
    return 0;
}