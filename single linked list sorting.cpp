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

void sortlist()
{
	struct node *current = root;
	struct node *index = NULL;  
    int temp;  
    if(root == NULL) 
	{  
            return;  
     }  
    else 
	  {  
         while(current != NULL) 
		 {  
            //Node index will point to node next to current  
            index = current->link;  
                while(index != NULL)
				 {  
                   //If current node's data is greater than index's node data, swap the data between them  
                if(current->data > index->data) 
				{  
                        temp = current->data;  
                        current->data = index->data;  
                        index->data = temp;  
                }  
                   index = index->link;  
                }  
                   current = current->link;  
        } 
		
		struct node*temp = root;
        while (temp != NULL) 
	{
        printf("%d  ", temp->data);
        temp = temp->link;
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
		printf("6.sortlist\n");
		printf("7.Quit\n");
		printf("enter your choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:append();
			break;
			case 2:addatafter();
			break;
			case 3:addatafter();
			break;
			case 4:len=length();
			       printf("length of the list:%d\n",len);
			break;
			case 5:display();
			break;
			case 6:sortlist();
			break;
			case 7:exit(1);
			break;
			default:printf("Invalid choice\n");
		}
	}
	return 0;
}
