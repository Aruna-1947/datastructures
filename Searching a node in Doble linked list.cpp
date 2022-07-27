#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *right;
	struct node*left;
};
struct node *root=NULL;
void append()
{
	struct node *temp;
	temp=(struct node *)malloc(sizeof(struct node));
	printf("enter your node:");
	scanf("%d",&temp->data);
	temp->right=NULL;
	temp->left=NULL;
	if(root==NULL)
	{
	root=temp;
    }
	else
	{
		struct node *p;
		p=root;
		while(p->right!=NULL)
		{
		p=p->right;
	    }
		p->right=temp;
		temp->left=p;
	}
}
void addatbegin()
{
	struct node *temp;
	temp=(struct node*)malloc(sizeof(struct node));
	printf("enter the node data:");
	scanf("%d",&temp->data);
	temp->left=NULL;
	temp->right=NULL;
	if(root==NULL)
	{
	root=temp;
    }
	else
	{	
	temp->right=root;
	root->left=temp;
	root=temp;
   }
}
int length()
{
	struct node *temp=root;
	int count=0;
	while(temp!=NULL)
	{
		count++;
		temp=temp->right;
	}
	return count;
}
void display()
{
	struct node *temp=root;
	if(temp==NULL)
	printf("List is empty\n");
	else
	{
		while(temp!=NULL)
		{
			printf("%d-->",temp->data);
			temp=temp->right;
		}
	}
}
void addatafter()
{
	struct node *temp,*p=root;
	int loc,i=1;
	printf("enter the location:");
	scanf("%d",&loc);
	if(loc>length())
	printf("invalid location\n");
	else
	{
		temp=(struct node *)malloc(sizeof(struct node));
		printf("enter the node data:");
		scanf("%d",&temp->data);
		temp->right=NULL;
		temp->left==NULL;
		while(i<loc)
		{
			p=p->right;
			i++;
		}
		temp->right=p->right;
		p->right->left=temp;
		temp->left=p;
		p->right=temp;
	}
}

void searchNode()
 {  
    int i = 1;
	int value;
	printf("Enter the value to be searched\n");
	scanf("%d",&value);  
    bool flag = false;   
    struct node *current = root;    
    if(root == NULL) 
	{  
        printf("List is empty\n");  
        return;  
    }  
    while(current != NULL) 
	{  
       if(current->data == value) 
	   {  
            flag = true;  
            break;  
        }  
        current = current->right;  
        i++;  
    }  
    if(flag)  
         printf("Node is present in the list at the position : %d\n", i);  
    else  
         printf("Node is not present in the list\n");  
}

int main()
{
	int ch,len;
	while(1)
	{
		printf("\n 1.Append\n");
		printf("2.Add at beginning\n");
		printf("3.Add at after\n");
		printf("4.length\n");
		printf("5.Display\n");
		printf("6.Searchnode\n");
		printf("7.Quit\n");
		printf("enter your choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:append();
			break;
			case 2: addatbegin();
			break;
			case 3:addatafter();
			break;
			case 4:len=length();
			printf("length of list:%d\n",len);
			break;
			case 5:display();
			break;
			case 6:searchNode();
			break;
			case 7:exit(1);
			break;
			default:printf("invalid choice\n");
		}
	}
	return 0;
}  
