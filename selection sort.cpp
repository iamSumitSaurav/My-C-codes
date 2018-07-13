#include<stdio.h>
#include<conio.h>
int main()
{
	int i,j,k,n,arr[100],small,temp;
	printf("Enter the size of the array \n");
	scanf("%d",&n);
	printf("Enter the elements of the array \n");
	for(i=0;i<n;i++)
	scanf("%d",&arr[i]);
	for(i=0;i<n;i++)
	{
	    small=arr[i];
	    for(j=i;j<n;j++)
	    {
		   if(arr[j]<small)
	       small=arr[j];
	    }
	    if(arr[i]!=small)
	    {
	    	for(k=i;k<n;k++)
	    	{
	    		if(arr[k]==small)
	    		{
	    			temp=arr[k];
	    			arr[k]=arr[i];
	    			arr[i]=temp;
				}
			}
		}
   }
   printf("The sorted array is \n");
   for(i=0;i<n;i++)
   printf("%d  ",arr[i]);
   return 0;
}
