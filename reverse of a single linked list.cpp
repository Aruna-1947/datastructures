#include<stdio.h>
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
	struct node*temp;
	temp=(struct node*)malloc(sizeof(struct node));
	printf("enter the data:");
	scanf("%d-->",&temp->data);
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
	if(root==NULL)
	{
		printf("Single linkd list is empty\n");
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

void addatbegin()
{
	struct node*temp;
	temp=(struct node*)malloc(sizeof(struct node));
	printf("enter the node data:");
	scanf("%d-->",temp->data);
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
void addatafter()
{
	struct node*temp,*p;
	int loc,i=1;
	printf("enter the location:");
	scanf("%d",&loc);
	if(loc>length())
	{
		printf("No nodes are present at the given location\n");
	}
	else
	{
		p=root;
		while(i<loc)
		{
			p=p->link;
			i++;
		}
		temp=(struct node*)malloc(sizeof(struct node));
		printf("enter the node data:");
		scanf("%d-->",&temp->data);
		temp->link=NULL;
		temp->link=p->link;
		p->link=temp;
	}
}

void display()
{
	struct node*temp;
	temp=root;
	if(temp==NULL)
	{
		printf("no nodes to display\n");
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


void reverse()
{
	struct node*previous;
	struct node*current;
	struct node*next;
	previous=0;
	current=next=root;
	while(next!=NULL)
	{
		next=next->link;
		current->link=previous;
		previous=current;
		current=next;
		}
		root=previous;
    struct node*temp = root;
    while (temp != NULL) 
	{
        printf("%d  ", temp->data);
        temp = temp->link;
    }
}


int main()
{
	int ch;
	while(1)
	{
		printf("Single linked list operations\n");
		printf("1.Append\n");
		printf("2.Add at Begin\n");
		printf("3.Add at After\n");
		printf("4.length\n");
		printf("5.Display\n");
		printf("6.reverse\n");
		printf("7.Quit\n");
		printf("enter your choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:append();
			break;
			case 2:addatbegin();
			break;
			case 3:addatafter();
			break;
			case 4:len=length();
			       printf("length of the list:%d\n",len);
			break;
			case 5:display();
			break;
			case 6:reverse();
			break;
			case 7:exit(1);
			break;
			default:printf("Invalid choice\n");
		}
	}
	return 0;
}
