#include<stdio.h>
int main()
{
   char a[10];
   int i=0,n=0;
   printf("\n NAME:Anjani\n SECTION :CSE-2C \n ");
   printf("\n enter a roman number:");
   scanf("%s",&a);
   while(a[i]!=NULL)
   {
       if(a[i]=='m')
       {
           n+=1000;
           i++;
       }
       else if(a[i]=='d')
       {
           n+=500;
           i++;
       }
       else if(a[i]=='c')
       {
           n+=100;
           i++;
           if(a[i]=='m')
           {
               n+=800;
               i++;
           }
           else if(a[i]=='d')
           {
               n+=300;
           }
       }
       else if(a[i]=='l')
       {
           n+=50;
           i++;
       }
       else if(a[i]=='x')
       {

           n+=10;
           i++;
           if(a[i]=='c')
           {
               n+=80;
               i++;
           }
           else if(a[i]=='l')
           {
               n+=30;
               i++;
           }
       }
       else if(a[i]=='v')
       {
           n+=5;
           i++;
       }
       else if(a[i]=='i')
       {
           n+=1;
           i++;
           if(a[i]=='x')
           {
               n+=8;
               i++;
           }
           else if(a[i]=='v')
           {
               n+=3;
               i++;
           }
       }

   }
   printf("\n ordinary number=%d",n);
}

