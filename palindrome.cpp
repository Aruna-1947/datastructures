#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node*link;
};
struct node*root=NULL;
struct node*head,*tail=NULL;
int len;
void append()
{
	struct node *temp;
	temp=(struct node*)malloc(sizeof(struct node));
	printf("Enter the node data:\n");
	scanf("%d",&temp->data);
	temp->link=NULL;
	if(root==NULL)
	{ 
		head=temp;
		tail=temp;
		temp->link==NULL;
		}
	else
	{ 
		tail->link=temp;
		tail=temp;
		}
}

int palindrome()
{
	struct node *p=root,*q=root;
	int i=1;
	int j=1;
	while(q->link!=NULL)
	{
		q=q->link;
		j++;
	}
	
	if(i<j)
	{
		if(p->data==q->data)
		{
			p=p->link;
			q=q->link;
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
		append();
	}
	palindrome();
}

