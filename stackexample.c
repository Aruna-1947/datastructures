#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *link;
};
struct node *top=NULL;
void push()
{
	struct node *temp;
	temp=(struct node*)malloc(sizeof(struct node));
	printf("Enter the node data:\n");
	scanf("%d",&temp->data);
	temp->link=top;
	top=temp;
}

void pop()
{
	struct node *temp;
	temp=top;
	if(temp==NULL)
	{
		printf("No stack elements to delete\n");
		}
		else
		{
			printf("Deleting element:%d\n",temp->data);
			temp->link=NULL;
			free(temp);
			top--;
			}
}

int length()
{
	struct node *temp=top;
	int count=0;
	while(temp!=NULL)
	{
		count++;
		temp=temp->link;
		}
		return count;
}

void traverse()
{
	struct node *temp=top;
	if(top==NULL)
	{
		printf("No elements in the stack to traverse\n");
		}
	else
	{
		while(temp!=NULL)
		{
			printf("%d\n",temp->data);
			temp=temp->link;
			}
		}
}

void peak()
{
	struct node *temp=top;
	if(temp==NULL)
	{
		printf("No nodes to display\n");
		}
	else
	{
		printf("Element at the top is:%d\n",temp->data);
		}
}

int main()
{
	int ch;
	while(1)
	{
		printf("1.push\n");
		printf("2.pop\n");
		printf("3.peak\n");
		printf("4.Traverse\n");
		printf("5.length\n");
		printf("6.exit\n");
		printf("Select any operation to perform\n");
		scanf("%d\n",&ch);
		switch(ch)
		{
			case 1 : push();
			         break;
			         
			case 2 : pop();
			         break;
			         
			case 3 : peak();
			         break;
			         
			case 4 : traverse();
			         break;
			         
			case 5 : length();
			         break;
			         
			case 6 : exit(0);
			         break;
			         
			default : printf("Invalid Choise\n");

			}
		}
		return 0;
}
