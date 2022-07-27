#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node*link;
};
struct node*root=NULL;
void append()
{
	struct node*temp;
	temp=(struct node*)malloc(sizeof(struct node));
	printf("Enter the node data:");
	scanf("%d\n--->",&temp->data);
	temp->link=NULL;
	if(root==NULL)
	 {
	    root=temp;
		}
	else
	{
		struct node*p;
		p=root;
		while(p->link!=NULL)
		{ 
			p=p->link;
			}
		p->link=temp;
		}
}
int length()
{
	int count=0;
	struct node*temp;
	temp=root;
	if(temp==NULL)
	{
		printf("The size of the given Single Linked List is ZERO\n\n");
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
void display()
{
struct node*temp;
temp=root;
if(temp==NULL)
{
	printf("There is no elements in the Single Linked List\n\n");
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
void addatBegin()
{
	struct node*temp;
	temp=(struct node*)malloc(sizeof(struct node));
	printf("Enter the value of node data:\n");
	scanf("%d\n",&temp->data);
	temp->link=NULL;
	if(root==NULL)
	{
		root=temp;
		}
	else
	{ 
		temp->link=root;
		root=temp;
		}
}
void addatAfter()
{
	struct node*temp,*P;
	int loc,i=1;
	printf("Enter the location to add an element:\n");
	scanf("%d",&loc);
	if(loc>length())
	{
		printf("node elements can't be added at that location\n");
		}
	else
	{
		struct node*p;
		p=root;
		while(i<loc)
		{
			p=p->link;
			i++;
		}
		temp=(struct node*)malloc(sizeof(struct node));
	    printf("Enter the value of node data:\n");
	    scanf("%d",&temp->data);
	    temp->link=NULL;
	    temp->link=p->link;
		p->link=temp;
		}
    	
}
void deleteof()
{
	struct node*temp;
	int loc;
	printf("enter the location to delete:");
	scanf("%d",&loc);
	if(loc>length())
	{
		printf("invalid location\n");
	}
	else if(loc==1)
	{
		temp=root;
		root=temp->link;
		temp->link=NULL;
		free(temp);
		}
		else
	{
		int i=1;
		struct node*p=root,*q;
		while(i<loc-1)
		{
			p=p->link;
			i++;
		}
		q=p->link;
		p->link=q->link;
		q->link=NULL;
		free(q);
	}
}
int main()
{
	int ch;
	while(1)
	{
		printf("Single linked list operations\n");
		printf("1.Append\n");
		printf("2.Add at begin\n");
		printf("3.Add at after\n");
		printf("4.length\n");
		printf("5.Display\n");
		printf("6.Delete\n");
		printf("7.Quit\n");
		printf("enter your choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:append();
			break;
			case 2:addatBegin();
			break;
			case 3:addatAfter();
			break;
			case 4:length();
			break;
			case 5:display();
			break;
			case 6:deleteof();
			break;
			case 7:exit(1);
			break;
			default:printf("Invalid choice\n");
		}
	}
	return 0;
}
