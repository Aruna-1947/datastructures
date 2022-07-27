#include<stdio.h>
int main()
{
   int p,n=0,k,count=0,count1=0;
   printf("\n NAME:Anjani \n SECTION :CSE-2C \n ");
   printf("\nenter a number:");
   scanf("%d",&k);
   int temp=k,temp1;
   while(k!=0)
   {
   n=(n*10)+(k%10);
   k=k/10;
   }
   temp1=n;
   while(n!=0)
   {
      switch(n%10)
      {
         case 0:
             printf("zero\t");
             break;
         case 1:
             printf("one\t");
             break;
         case 2:
            printf("two\t");
            break;
         case 3:
            printf("three\t");
            break;
         case 4:
            printf("four\t");
            break;
         case 5:
            printf("five\t");
            break;
         case 6:
            printf("six\t");
            break;
         case 7:
            printf("seven\t");
            break;
         case 8:
            printf("eight\t");
            break;
         case 9:
            printf("nine\t");
            break;
      }
      n=n/10;
   }
    while(temp1!=0)
    {
    	temp1=temp1/10;
    	++count;

	}
	while(temp!=0)
	{
		temp=temp/10;
		++count1;
	}
    if(count<count1)
    {
        p=count1-count;
    }
   while(p!=0)
   {
        printf("zero\t");
      --p;
    }

}

