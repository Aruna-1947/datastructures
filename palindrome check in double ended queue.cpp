#include<stdio.h>
#include<stdlib.h>

struct node
{
int data;
struct node *left;
struct node *right;
	
};
struct node *root=NULL;


void create()
{   
    
	struct node *temp,*p;
	temp=(struct node*)malloc(sizeof(struct node));
	printf("enter data:");
	scanf("%d",&temp->data);
	temp->left =NULL;
	temp->right =NULL;
	
	if(root==NULL)
	{
		root=temp;
	}
	else
	{
		struct node *p=root;
		while(p->right!=NULL)
		{
			p=p->right;
		}
		p->right=temp;
		temp->left=p;
	}
}


int palindrome()
{
	struct node *p=root,*q=root;
	int i=1;
	int j=1;
	while(q->right!=NULL)
	{
		q=q->right;
		j++;
	}
	
	if(i<j)
	{
		if(p->data==q->data)
		{
			p=p->right;
			q=q->left;
			i++;
			j--;
			printf("It is palindrome");
	   }
	   
			else
	{
		printf("it is not a palindrome");
	}

	
}
}

int main()
{
	int x,i;
	printf("enter number of nodes you want to insert in double linked list:");
	scanf("%d",&x);
	
	for(i=0;i<x;i++)
	{
		create();
	}
	palindrome();
}
