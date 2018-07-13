#include<iostream>
using namespace std;
int Bsort(int arr[], int);
int main()
{
	int i,a[100],b[20],size,x,y=0;
	cout<<"Enter the size of the array \n";
	cin>>size;
	cout<<"Enter the array elements \n";
	for(i=0;i<size;i++)
	cin>>a[i];
	Bsort(a,size);
	for(i=0;i<size;i++)
	cout<< a[i];
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
