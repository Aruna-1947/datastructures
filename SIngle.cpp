#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int len;
struct node 
{
	int data;
	struct node *link;
};
struct node *root=NULL;
void append()
{
	struct node *temp;
	temp=(struct node*)malloc(sizeof(struct node));
	temp->link=NULL;
	struct node *p=root;
	if(root==NULL)
	{
		root=temp;
		temp->link=NULL;
		}
		else
		{
			while(p->link!=NULL)
			{
				p->link=p;
				}
				p->link=temp;
				temp->link=NULL;
			}
}

void addat_begin()
{
	struct node *temp;
	struct node *p=root;
	temp=(struct node*)malloc(sizeof(struct node));
	temp->link=NULL;
	if(root==NULL)
	{
		root=temp;
		temp-<link=NULL;
		}
		else 
		{
			temp->link=p;
			root=temp;
			}
	}
	
int length()
{
	int count=0;
    struct node *temp=root;
    if(root==NULL)
    {
		printf("No elements in the list\n");
		}
		else
		{
			while(temp!=NULL)
			{
				count++;
				temp=temp->link;
				}
				return count;
			}
}

void addat_after()
{
	int i=1;
	int loc;
	struct node *temp;
	temp=(struct node*)malloc(sizeof(struct node));
	struct node *p=root;
	printf("Enter your required location:\n");
	scanf("%d",&loc);
	if(loc>length())
	{
		printf("Your location is not found!");
	}
	else 
	{ 
		printf("Enter the node data:\n");
		scanf("%d",&temp->data);
		while(i<loc)
		{
			p=p->link;
			i++;
			}
			temp->link=p->link;
			p->link=temp;
		}
}

void display()
{
	struct node *temp=root;
	if(root==NULL)
	{
		printf("No elements in the list:\n");
		}
		else
		{
			while(temp!=NULL)
			{
				printf("%d",temp->data);
				temp=temp->link;
				}
			}
}

void deletat_begin()
{
struct node *temp=root;
    if(root==NULL)
	{ 
		printf("No elemets to delete\n");
		}
		else
		{
			root=temp->link;
			temp>link=NULL;
			free(temp);
			}	
}

void deletat_end()
{
	struct node *temp=root;
	if(root==NULL)
	{
		printf("No elemets to delete\n");
		}
		else 
		{
			while(temp->link!=NULL)
			{
				temp->link=temp;
				}
				p->link=temp->link;
				temp->link=NULL;
				free(temp);
			}
}
