#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define MAX 100
char stack[MAX];
int top=-1;
void push(char item)
{
	if(top>MAX-1)
	{
		printf("Stack is overflowed\n");
		}
		else
		{
			stack[top++]=item;
			}
}

void pop()
{
	if(top==-1)
	{
		printf("No elemets in the stack\n");
		}
		else
		{
			char item;
			item=stack[top];
			top--;
			free(item);
			}
}

int is_operator(char item)
{
	if((item=='^') || (item=='/') || (item=='%') || (item=='+') || (item=='-') || (item=='*') )
	{
		return 1;
		}
		else 
		{
			return 0;
			}
}

int precedence()
{ 
	char item;
	if(item=='^')
	{ 
		return 3;
		}
	else if(item=='*' || item=='/')
	{
		return 2;
		}
	else if(item=='+' || item=='-')
	{
		return 1;
		}
	else 
	{  
		return 0;
		}
}

int main()
{
	char infix[MAX],postfix[MAX],prefix[MAX];
	char temp,item;
	int i=0,j=0;
	printf("Enter the infix expression:\n");
	gets(infix);


while((item=infix[i])!='\o')
{
	if(item=='(')
	{
		push(item);
		}
	else if((item>='A' && item<='Z') || (item>='a' && item<='z'))
	{
		postfix[j]=item;
		j++;
		}
	else if(is_operator(item)==1)
	{ 
		temp=pop();
		while((is_operator(temp)==1) && (precedence(temp)>=precedence(item)))
		{
			postfix[j]=temp;
			j++;
			temp=pop();
			}
			push(temp);
			push(item);
		}
	else if(item=='(')
	{
		temp=pop();
		while(temp!='(')
		{
			postfix[j]=temp;
			j++;
			temp=pop();
			}
		}
	else
	{
		printf("Invalid Expression\n");
		}
		i++;	
}
while(top>-1)
{
	postfix[j]=pop();
	j++;
}
postfix[j]!='\o'
printf("Postfix expression:\n");
puts(postfix);
return 0;
}
