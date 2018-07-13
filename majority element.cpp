#include<iostream>
using namespace std;
int Bsort(int a[] , int);
int main()
{
	int a[100],n,maj,i,m=1,c=1,flag=-1;
	cout<<"Enter the size of the array \n";
	cin>>n;
	cout<<"Enter the array elements \n";
	for(i=0;i<n;i++)
	cin>>a[i];
    Bsort(a,n);
    cout<<"The array in increasing order is: ";
    for(i=0;i<n;i++)
    cout<<a[i]<<" ";
    cout<<endl;
	for(i=0;i<n;i++)
	{
	    if(a[i]==a[i+1])
	    {
	        c++;
	        if(c>n/2)	
	        {
		        maj=a[i];
	            flag++;
            }
        }
        else c=1;
   }
   if(flag==-1)
   cout<<"Verdict: No majority element found \n";
   else
   cout<<" Verdict: Majority element is: "<<maj;
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
