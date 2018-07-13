#include<iostream>
using namespace std;
int printelement(int x)
{
	cout<<x<<" ";
}
int main()
{
	int arr[20],i,t,maxsum,flag=-1,p,n;
	cout<<"Enter the size of the array \n";
	cin>>n;
	cout<<"Enter the elements of the array \n";
	for(i=0;i<n;i++)
	cin>>arr[i];
	maxsum=arr[0];
	t=maxsum;
	i=1;
	cout<<"The required array constituting the maximum sum is: \n";
	while(i<n)
	{
		maxsum=maxsum+arr[i];
		if(maxsum>=t)
		{
			t=maxsum;
			p=arr[i];
			i++;
			flag++;
			printelement(p);
		}
		else
		{
			maxsum=maxsum-arr[i];
			t=maxsum;
			i++;
		}
	}
	if(flag==-1)
	cout<<"Element at 0th index i.e. "<<arr[0]<<" is the only such number in the array constituting the maximum sum \n";
	return 0;
}
