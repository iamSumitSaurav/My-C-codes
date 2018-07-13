#include<iostream>
using namespace std;
int main()
{
	int A[20],B[10],n,x,y=-1;
	cout<<"Enter the no of elements \n";
	cin>>n;
	cout<<"Enter the array \n";
	for(int i=0;i<n;i++)
	cin>>A[i];
	cout<<"Enter the no which you want as a sum of two numbers in the array \n";
	cin>>x;
	cout<<"The corresponding pairs are \n";
	for(int i=0;i<n;i++)
	for(int j=0;j<n;j++)
	if(A[i]+A[j]==x){
	y++;
	cout<<"("<<A[i]<<"+"<<A[j]<<"), ";}
	if(y==-1)
	cout<<"Sorry, no such pair is found \n";
	return 0;
	
}
