#include<stdio.h>
int partition(int a[],int beg,int end);
void quicksort(int a[],int beg,int end);
int main()
{
	int i;
	int arr[10]={23,21,66,43,7,8,90,54,45,38};
	printf("elements before sorting\n");
	for(i=0;i<10;i++)
	{
		printf("%d\t",arr[i]);
		
	}
	quickSort(arr,0,9);
	printf("\n The sorted array is :\n");
	for(i=0;i<10;i++)
	printf("%d\t",arr[i]);
}
int partition(int a[],int beg,int end)
{
	int left,right,temp,loc,flag;
	loc=left=beg;
	right=end;
	flag=0;
	while(flag!=1)
	{
		while((a[loc]<=a[right])&&(loc!=right))
		right--;
		if(loc==right)
		flag=1;
		else if(a[loc]>a[right])
		{
			temp=a[loc];
			a[loc]=a[right];
			a[right]=temp;
			loc=right;
		}
		if(flag!=1)
		{
			while((a[loc]>=a[left])&&(loc!=left))
			left++;
			if(loc==left)
			flag=1;
			else if(a[loc]<a[left])
			{
				temp=a[loc];
				a[loc]=a[left];
				loc=left;
			}
		}
	}
	return loc;
}
void quickSort(int a[],int beg,int end)
{
	int loc;
	if(beg<end)
	{
		loc=partition(a,beg,end);
		quickSort(a,beg,loc-1);
		quickSort(a,loc+1,end);
	}
}
