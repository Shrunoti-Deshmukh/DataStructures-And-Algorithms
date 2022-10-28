#include <stdio.h>
#include "stack.h"
#include <stdlib.h>
#include<string.h>


tree* postfix_ex(tree *root){

stack *top=NULL;
char str[30];
printf("Enter the Postfix Expression : ");
scanf("%s",&str);

for(int i=0;str[i]!='\0';i++){

tree *tree_node=(tree*)malloc(sizeof(tree));
tree_node->val=str[i];
tree_node->lchild=tree_node->rchild=NULL;

if(isalpha(str[i])){

top=push(top,tree_node);
}
else{

tree_node->rchild=ReadTop(top);
top=pop(top);
tree_node->lchild=ReadTop(top);
top=pop(top);

top=push(top,tree_node);

}
}

root=ReadTop(top);
top=pop(top);
return root;

}

tree* prefix_ex(tree *root){


stack *top=NULL;
char str[30];
printf("Enter the Prefix Expression : ");
scanf("%s",&str);
int length=strlen(str);

for(int i=length-1;i>=0;i--){

tree *tree_node=(tree*)malloc(sizeof(tree));
tree_node->val=str[i];
tree_node->lchild=tree_node->rchild=NULL;

if(isalpha(str[i])){

top=push(top,tree_node);
}
else{

tree_node->lchild=ReadTop(top);
top=pop(top);
tree_node->rchild=ReadTop(top);
top=pop(top);

top=push(top,tree_node);

}
}

root=ReadTop(top);
top=pop(top);
return root;

}


void pre_order(tree *root){

if(root!=NULL){

printf("%c",root->val);
pre_order(root->lchild);
pre_order(root->rchild);
}
}

void post_order(tree *root){

if(root!=NULL){

post_order(root->lchild);
post_order(root->rchild);
printf("%c",root->val);
}
}

void in_order(tree *root){
if(root!=NULL){

in_order(root->lchild);
printf("%c",root->val);
in_order(root->rchild);
}
}

void main(){

int ch;
tree *root=NULL;
printf("Enter Prefix or Post Expression '1/2'");
scanf("%d",&ch);

if(ch==1){
	root=prefix_ex(root);
}
else{
	root=postfix_ex(root);
}

printf("\nPre Order: ");
pre_order(root);

printf("\nPost Order: ");
post_order(root);

printf("\nIn Order: ");
in_order(root);

}
