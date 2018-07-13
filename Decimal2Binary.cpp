#include<iostream>
#include<math.h>
using namespace std;

int sum = 0;
int Binary(int r, int i)
{
	sum += r * pow(10,i);
	return sum;	
}
int main()
{
	int number, dividend = 1, remainder, i = 0, result;
	cin>>number;
	while(dividend)
	{
		dividend = number / 2;
		remainder = number % 2;
		number = dividend;
		result = Binary(remainder,i);
		i++;
	}
	cout<<result;
	return 0;
}
