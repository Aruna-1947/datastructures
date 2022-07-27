#include<stdio.h>
 int main()
{
    int n,p;
    printf("\n NAME:Anjani\n SECTION :CSE-2C \n ");

    char a[10][10]={"zero","one","two","three","four","five","six","seven","eight","nine"};
    char b[10][10]={"ten","eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen"};
    char c[10][10]={"ten","twenty","thirty","forty","fifty","sixty","seventy","eighty","ninety","hundred"};
    printf("enter number:");
    scanf("%d",&n);
    if(n<10000)
    {
        if(n>=1000)
        {
            p=n/1000;
            printf("%s thousand  ",a[p]);
            n=n%1000;
        }
        if(n>100)
        {
            p=n/100;
            printf("%s hundred and  ",a[p]);
            n=n%100;
        }
        if(n>=10 && n<20)
        {
            p=n%10;
            printf("%s  ",b[p]);
        }
        if(n>19 && n<=100)
        {
            p=n/10;
            printf("%s ",c[p-1]);
            n=n%10;
        }
        if(n!=0&&n<10)
        {
            printf("%s  ",a[n]);
        }
}}

