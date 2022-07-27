#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node*link;
};
struct node*root=NULL;
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
		root=temp;
		temp->link==NULL;
		}
	else
	{ 
		struct node *p=root;
		while(p->link!=NULL)
		{
			p->link=p;
			}
			p->link=temp;
			temp->link=NULL;
		}
}

void add_begin()
{
	struct node *temp;
	temp=(struct node*)malloc(sizeof(struct node));
	printf("Enter the node data:\n");
	scanf("%d\n",&temp->data);
    temp->link=NULL;
  if(root==NULL)
     {
	     root=temp;
	     temp->link=NULL;
     }
   else
     {
		  temp->link=root;
		  root=temp;	
	 }
}

int length()
{
	int count=0;
	struct node *p;
	p=root;
			while(p!=NULL)
			{ 
				count++;
				p=p->link;
			}
			  return count;
}
void add_after()
  {
	 int loc;
	 printf("Enter the location to add an element:\n");
	 scanf("%d",&loc);
	 if(loc>length())
	   {
		  printf("element can't be added\n\n");	
			}	
  
  else
  {     
		struct node *p=root;
		int i=1;
		while(i<loc)
		{
		  p=p->link;
		  i++;	
			}
		   struct node *temp;
		   temp=(struct node*)malloc(sizeof(struct node));
		   printf("Enter the node data:\n");
	       scanf("%d",&temp->data);
		   temp->link=NULL;
		   temp->link=p->link;
		   p->link=temp;
		}
	}
	
void deleteof()
  {
		struct node *temp;
		int loc;
		printf("Enter the location to delete an element:\n");
		scanf("%d",&loc);
		  if(loc>length())
		  {
				printf("Invalid Location\n\n");
				}
			else if(loc==1)
			{
			   struct node *p=root;
			   root=p->link;
			   p->link=NULL;
			   free(p);
				}
			else
			{
				int i=1;
				struct node *q=root;
				while(i<loc-1)
				{ 
					q=q->link;
					i++;
					}
					struct node*temp;
				  temp=q->link;
		          temp->link=q->link;
		          q->link=NULL;
		          free(q);
				}
  }

void display()
{
	struct node*temp=root;
	if(root==NULL)
	{ 
		printf("No nodes to display\n\n");
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
		printf("\nenter your choice:\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:append();
			break;
			case 2:add_begin();
			break;
			case 3:add_after();
			break;
			case 4:len=length();
			       printf("length of the list:%d\n",len);
			break;
			case 5:display();
			break;
			case 6:deleteof();
			break;
			case 7:exit(1);
			break;
			default:printf("\nInvalid choice\n");
		}
	}
	return 0;
}
