#include<iostream>
using namespace std;

int T, N;
int func(int x)
{
	if(x==1)
	   return 2;
	else if(x==2)
	   return 5;
	else if(x==3)
	   return 7;
	else 
	   return (2*func(x-3)+3*func(x-1));
}
int main()
{
	cin>>T;
	while(T--)
	{
		cin>>N;
		int result;
		result=func(N);
		cout<<result<<endl;
	}
	return 0;
}
