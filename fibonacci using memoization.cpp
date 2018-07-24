#include<bits/stdc++.h>
using namespace std;

int fibonacci(int fib[], int n)
{
	if(n <= 1)
		return n;
		
	if(fib[n] == -1)
	{
		fib[n] = fibonacci(fib, n-1) + fibonacci(fib, n-2);
		return fib[n];
	}
	
	return fib[n];
}

int main()
{
	int n;
	cin>>n;
	int arr[n*n*n];
	for(int i = 0; i < pow(n,3); i++)
		arr[i] = -1;
	arr[0] = 0;
	arr[1] = 1;
		
	int result = fibonacci(arr, n);
	for(int i = 0; i < n; i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl<<result;
	return 0;
}
