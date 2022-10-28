#include<stdio.h>
#include<stdlib.h>


typedef struct tree{

char val;
struct tree *lchild;
struct tree *rchild;
}tree;


typedef struct node
{
        tree *data;
        struct node *next;
}stack;

stack* push(stack *top,tree *data)
{
        stack *NewNode=(stack*)malloc(sizeof(stack));
        NewNode->data=data;
        NewNode->next=NULL;
        if(top==NULL)
        {
                top=NewNode;
        }
        else
        {
                NewNode->next=top;
                top=NewNode;
        }
        return top;
}


stack* pop(stack *top)
{
        stack *temp=top;
        if(top==NULL)
        {
                printf("\nStack is Empty");
        }
        else
        {
                top=top->next;
                free(temp);
        }
        return top;
}


tree* ReadTop(stack *top)
{
        return top->data;
}

