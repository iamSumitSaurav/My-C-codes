#include<iostream>
using namespace std;
int printelement(int x)
{
	cout<<x<<" ";
}
int main()
{
	int arr[20],i,j,n,p,c=0,flag=-1;
    cout<<"Enter the number of the elements in the array \n";
    cin>>n;
    cout<<"Enter the elements of the array \n";
    for(i=0;i<n;i++)
    cin>>arr[i];
    cout<<"The elements(s) occuring odd number of times are: \n";
    for(i=0;i<n;i++)
    {
    	for(j=0;j<n;j++)
        if(arr[i]==arr[j])
        c++;
        if(c/2!=0)
        {
        	p=arr[i];
        	flag++;
        	printelement(p);
		}
	}
	if(flag==-1)
	cout<<"Verdict: There is no element occuring odd number of times \n";
	return 0;
}
