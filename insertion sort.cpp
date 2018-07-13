#include<stdio.h>
int swap(int *a, int *b)
{
	int temp=*a;
	*a=*b;
	*b=temp;
}
int main()
{
	int i,j,n,arr[100];
	printf("Enter the size of the array \n");
	scanf("%d",&n);
	printf("Enter the elements of the array \n");
	for(i=0;i<n;i++)
	scanf("%d",&arr[i]);
	for(i=0;i<n-1;i++)
	{
		if(arr[i]>arr[i+1])
		swap(&arr[i],&arr[i+1]);
		if(i>0)
		for(j=i;j>0;j--)
		if(arr[j]<arr[j-1])
		swap(&arr[j],&arr[j-1]);
	}
	printf("The sorted array is \n");
	for(i=0;i<n;i++)
	printf("%d  ",arr[i]);
	return 0;
}

