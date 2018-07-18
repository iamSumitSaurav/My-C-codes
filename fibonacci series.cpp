#include<bits/stdc++.h>
using namespace std;
void printFibonacci(long long int fib[], int n)
{
	if(n <= 1)
	{
		fib[0] = 0;
		fib[1] = 1;
	}
	else
	{
		fib[0] = 0;
		fib[1] = 1;
		for(int i = 2; i < n; i++)
			fib[i] = fib[i-1] + fib[i-2];
	}
}

int main()
{
	int size;
	cin>>size;
	long long int array[size];
	printFibonacci(array, size);
	cout<<"The Fibonacci series is : ";
	for(int i = 0; i < size; i++)
		cout<<array[i]<<" ";
	return 0;
}
