#include<stdio.h>
#include<stdlib.h>
 
 struct node
 {
		int data;
		struct node *link;
};
struct node *front=NULL;
struct node *rear=NULL;

void enque(int ele)
{
	struct node *temp;
	temp=(struct node *)malloc (sizeof(struct node));
	temp->link=NULL;
	temp->data=ele;
	
	if(front==NULL)
	{
		front=temp;
		rear=temp;
	}
	
	else
	{
	   rear->link=temp;
	   rear=temp;	
	}
}

void deque()
{
	struct node *temp=front;
	front=front->link;
	temp->link=NULL;
	free(temp);
}

void display()
{
	struct node *temp=front;
	if(temp==NULL)
	{
		printf("queue is empty");
		}
		else{
		
	while(temp!=NULL)
	{
	printf("%d\t",temp->data);
	temp=temp->link;
	
	}
}
}

int main()
{
int val,ch;

while(1)
{     printf("\nQUEUE OPERATIONS\n");
	 	printf("\n1.Enque\n 2.Deque \n 3.display\n 4.exit\n");
	printf("enter your choice:");
	scanf("%d",&ch);

	switch(ch)
	{
		case 1:
			printf("enter element:");
			scanf("%d",&val);
			enque(val);
			break;
		
		case 2:deque();
		       break;
		       
		case 3:
			     display();
			     break;
		case 4:
			exit(0);
			break;
			
		default:
			printf("enter correct choice:");
			break;
		
		}
}
return 0;
}
