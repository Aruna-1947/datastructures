#include<stdio.h>
#include<stdlib.h>
struct tnode
{
	int data;
	struct tnode *right;
	struct tnode *left;
};
struct tnode *CreateBST(struct tnode *,int);
void Inorder(struct tnode *);
void Preorder(struct tnode *);
void Postorder(struct tnode *);
int main()
{
	struct tnode *root=NULL;
	int choice,item,n,i;
	do
	{
		printf("\n\nBinary Search Tree Operations\n");
		printf("\n1.Creation of BST");
		printf("\n2.Traverse in Inorder");
		printf("\n3.Traverse in Preorder");
		printf("\n4.Traverse in Postorder");
		printf("\n5.Exit\n");
		printf("\n Enter your choice: ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:root=NULL;
			printf("\n\n BST for how many nodes? ");
			scanf("%d",&n);
			for(i=1;i<=n;i++)
			{
			printf("\nEnter data for node %d: ",i);
			scanf("%d",&item);
			root=CreateBST(root,item);
			}
			printf("\nBST with %d nodes is ready to use!!\n",n);
			break;
			case 2:printf("\nBST Traversal in Inorder\n");
			Inorder(root);
			break;
			case 3:printf("\nBST Traversal in Preorder\n ");
			Preorder(root);
			break;
			case 4:printf("\nBST Traversal in Postorder\n ");
			Postorder(root);
			break;
			case 5:prntf("\n\n Terminating \n\n");
			break;
			defualt:printf("\n\n Invalid Option!!!Try again!!\n\n");
			break;
			
		}
	}
	while(choice!=5);
	return 0;
}
struct tnode *createBST(struct tnode *root,int item)
{
	if(root==NULL)
	{
		root=(struct tnode*)malloc(sizeof(struct tnode));
		root->left=root->right=NULL;
		root->data=item;
		return root;
	}
	else
	{
		if(item <root->data)
		root->left=CreateBST(root->left,item);
		else if(item>root->data)
		root->right=CreateBST(root->right,item);
		else
		printf("Duplicate Element!!Not Allowed!!!");
		return(root);
	}
}
void Inorder(struct tnode *root)
{
	if(root!=NULL)
	{
		Inorder(root->left);
		printf("%d",root->data);
		Inorder(root->right);
	}
}
void Preorder(struct tnode *root)
{
	if(root!=NULL)
	{
		printf("%d",root->data);
		Preorder(root->left);
		Preorder(root->right);
	}
}
void Postorder(struct tnode *root)
{
	if(root!=NULL)
	{
		Postorder(root->left);
		Preorder(root->right);
		printf("%d",root->data);
	}
}
