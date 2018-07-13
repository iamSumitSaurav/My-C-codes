#include<iostream.h>
#include<conio.h>
int main()
{
	int a[10],b[10],c[20],x,y;
	cout<<"Enter the size of the first array\n";
	cin>>x;
	cout<<"Enter the elements of the array\n";
	for(int i=0;i<x;i++)
	cin>>a[i];
	cout<<"Enter the size of the second array\n";
	cin>>y;
	cout<<"Enter the elements of the array\n";
	for(int j=0;j<y;j++)
	cin>>b[j];
	//Merging of two arrays into the third array
	for(i=0;i<x;i++)
	c[i]=a[i];
	for(i=x;i<x+y;i++)
	c[i]=b[i];
	cout<<"The merged array is\n";
	for(i=0;i<x+y;i++)
	cout<<c[i]<<" ";
	return 0;
}
