#include<iostream>
using namespace std;
int Bsort(int arr[], int);
int main()
{
	int i,a[20],size,x,y=0;
	cout<<"Enter the size of the array \n";
	cin>>size;
	cout<<"Enter the array elements \n";
	for(i=0;i<size;i++)
	cin>>a[i];
	Bsort(a,size);
	for(i=0;i<size;i++)
		cout<<a[i];
	cout<<"Enter the no which you want as the sum of two numbers in the array \n";
	cin>>x;
	int l=a[0];
	int r=a[size-1];
	cout<<"The corresponding pairs are: \n";
	while(l<r)
	{
		if(a[l]+a[r]==x)
		{
			y++;
			cout<<"("<<a[l]<<","<<a[r]<<"), ";
			
		}
		else if(a[l]+a[r]<x)
			l++;
		else r--;
	}
	if(y>0)
	cout<<"There are"<<y<<"such pairs in the given array \n";
	else
	cout<<"There are no such pairs \n";
	return 0;
}
int Bsort(int arr[], int N)
{
	for(int j=0;j<N-1;j++)
	for(int k=0;k<N-j-1;k++)
	if(arr[k]>arr[k+1])
	{ 
		int temp=arr[k];
		arr[k]=arr[k+1];
		arr[k+1]=temp;
	}
	return *arr;
}
