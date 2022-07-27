#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
struct node
{
    int data;
    struct node *right;
    struct node *left;
};
struct node *tree=NULL;
void insert()
{
    struct node *temp,*parent;
    temp=(struct node *)malloc(sizeof(struct node));
    printf("Enter the node data : ");
    scanf("%d",&temp->data);
    temp->right=NULL;
    temp->left=NULL;
    if(tree==NULL)
        tree=temp;
    else
    {
        struct node *current=tree;
        while(current)
        {
              parent=current;
              if(temp->data>current->data)
                current=current->right;
              else
                current=current->left;
        }
        if(temp->data>parent->data)
            parent->right=temp;
        else
            parent->left=temp;
    }
}
void preorder(struct node *tree)
{
    if(tree!=NULL)
    {
        printf("%d\t",tree->data);
        preorder(tree->left);
        preorder(tree->right);
    }
}
void inorder(struct node *tree)
{
    if(tree!=NULL)
    {
        preorder(tree->left);
        printf("%d\t",tree->data);
        preorder(tree->right);
    }
}
void postorder(struct node *tree)
{
    if(tree!=NULL)
    {
        preorder(tree->left);
        preorder(tree->right);
        printf("%d\t",tree->data);
    }
}
struct node *find_small(struct node *tree)
{
    if(tree==NULL||tree->left==NULL)
        return tree; 
    else
        return find_small(tree->left); 
}
struct node *find_large(struct node *tree)
{
  if(tree==NULL||tree->right==NULL)
        return tree;
  else
        return  find_large(tree->right);
}
struct node *Delete(struct node *tree,int val)
{
    struct node *cur,*parent,*suc,*psuc,*ptr;
    if(tree->left==NULL)
    {
        printf("The tree is empty\n");
        return tree;
    }
    parent=tree;
    cur=tree->left;
    while(cur!=NULL&&val!=cur->data)
    {
        parent=cur;
        cur=(val<cur->data)?cur->left:cur->right;
    }
    if(cur==NULL)
    {
        printf("The value to be deleted is not in the tree\n");
        return tree;
    }
    if(cur->left==NULL)
        ptr=cur->right;
    else if(cur->right==NULL)
        ptr=cur->left;
    else
    {
        psuc=cur;
        cur=cur->left;
        while(suc->left!=NULL)
        {
            psuc=suc;
            suc=suc->left;
        }
        if(cur==psuc)
            suc->left=cur->right;
        else
        {
            suc->left=cur->left;
            psuc->left=suc->right;
            suc->right=cur->right;
        }
        ptr=suc;
    }
    if(parent->left==cur)
        parent->left=ptr;
    else
        parent->right=ptr;
    free(cur);
    return tree;
}
int total_nodes(struct node *tree)
{
    if(tree==NULL)
        return 0;
    else
        return (total_nodes(tree->left)+total_nodes(tree->right)+1);
}
int height(struct node *tree)
{
    int lheight,rheight;
    if(tree==NULL)
        return 0;
    else
    {
        lheight=height(tree->left);
        rheight=height(tree->right);
        if(lheight>rheight)
            return (lheight+1);
        else
            return (rheight+1);
    }
}
void at_level(struct node *temp,int desired,int current)
{
    if(temp)
    {
        if(desired==current)
            printf("%d\t",temp->data);
        else
        {
            at_level(temp->left,desired,current+1);
            at_level(temp->right,desired,current+1);
        }
    }
}
int main()
{
    int option,val,ch,l;
    struct node *ptr;
        printf("\n1.Insert element\n");
        printf("2.Preorder traversal\n");
        printf("3.Inorder traversal\n");
        printf("4.Postorder traversal\n");
        printf("5.Smallest element\n");
        printf("6.Largest element\n");
        printf("7.Delete an element\n");
        printf("8.Total no.of nodes\n");
        printf("9.Height of tree\n");
        printf("10.Elements at nth level\n");
        printf("11.Exit\n");

    while(1)
    {
        printf("\nEnter your choice : ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: insert();
                        break;
            case 2:printf("The elements of the tree are : ");
                        preorder(tree);
                        break;
            case 3:printf("The elements of the tree are : ");
                        inorder(tree);
                        break;
            case 4:printf("The elements of the tree are : ");
                        postorder(tree);
                        break;
            case 5:ptr=find_small(tree);
                        printf("Smallest element : %d\n",ptr->data);
                        break;
            case 6:ptr=find_large(tree);
                        printf("Largest element : %d\n",ptr->data);
                        break;
            case 7:printf("Enter the element to be deleted : ");
                        scanf("%d",&val);
                        tree=Delete(tree,val);
                        break;
            case 8:printf("Total no .of nodes : %d\n",total_nodes(tree));
                        break;
            case 9:printf("The height of the tree : %d\n",height(tree));
                        break;
            case 10:printf("Enter the value of n : ");
                        scanf("%d",&l);
                        at_level(tree,l,0);
                        break;
            case 11:exit(0);
                        break;
            default:printf("Invalid choice\n");
        }
    }
    return 0;
}
