#include<bits/stdc++.h>
using namespace std;

int Fibonacci(int n)
{
	if(n <= 1)
		return n;
	
	int first = 0, second = 1, fib;
	for(int i = 0; i < n; i++)
	{
		fib = first + second;
		second = first;
		first = fib;	
	}
	return fib;
}

int main()
{
	int n;
	cin>>n;
	int result = Fibonacci(n);
	cout<<result;
	return 0;
}
