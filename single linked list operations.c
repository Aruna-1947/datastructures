#include<stdio.h>
#include<stdlib.h>
struct node
{
	char student_name[40];
	int id_no;
	char gender[30];
	struct node*link;
 };
struct node*root=NULL;
int len;
void append()
{
	struct node*temp;
	temp=(struct node*)malloc(sizeof(struct node));
	printf("enter the student_name:");
	scanf("%s",&temp->student_name);
	printf("enter id_no:");
	scanf("%d",&temp->id_no);
	printf("enter the gender:");
	scanf("%s",&temp->gender);
	temp->link=NULL;
	if(root==NULL)
	{
		root=temp;
	}
	else
	{
		struct node*s;
		s=root;
		while(s->link!=NULL)
		{
			s=s->link;
		}
		s->link=temp;
	}
}
int length()
{
	int count=0;
	struct node*temp;
	temp=root;
	while(temp!=NULL)
	{
		count++;
		temp=temp->link;
	}
	return count;
}
void display()
{
	struct node*temp;
	temp=root;
	if(temp==NULL)
	{
		printf("no nodes to display");
	}
	else
	{
		while(temp!=NULL)
		{
			printf("student_name: %s\n",temp->student_name);
			printf("id_no: %d\n",temp->id_no);
			printf("gender:%s\n",temp->gender);
			temp=temp->link;
			
		}
	}
}
void addatbegin()
{
	struct node*temp;
	temp=(struct node*)malloc(sizeof(struct node));
	printf("enter the student_name: \n");
	scanf("%s",&temp->student_name);
	printf("enter id_no: \n");
	scanf("%d",&temp->id_no);
	printf("enter the gender: \n");
	scanf("%s",&temp->gender);
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
	struct node *temp,*p;
	int loc,i=1;
	printf("enter the location: ");
	scanf("%d",&loc);
	if(loc>length())
	{
		printf("invalid location");
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
	printf("enter the student_name:");
	scanf("%c",&temp->student_name);
	printf("enter id_no: ");
	scanf("%d",&temp->id_no);
	printf("enter the gender: ");
	scanf("%s",&temp->gender);
	temp->link=NULL;
	temp->link=p->link;
	p->link=temp;
	}
}
void delete1()
{
	struct node*temp;
	int loc;
	printf("enter the location:");
	scanf("%d",&loc);
	if(loc>length())
	{
		printf("invalid location");
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
		struct node*k=root,*s;
		while(i<loc-1)
		{
			k=k->link;
			i++;
		}
		s=k->link;
		k->link=s->link;
		s->link=NULL;
		free(s);
	}
	
}
void main()
{
	int ch;
	while(1)
	{
		printf("Operations of single linked lists:\n");
		printf("1.Append\n");
		printf("2.Add at begin\n");
		printf("3.Add at after\n");
		printf("4.Length\n");
		printf("5.Display\n");
		printf("Delete\n");
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
			case 6:delete1();
			break;
			case 7:exit(1);
			break;
			default:printf("Invalid choice");
			
		}
	}
}
