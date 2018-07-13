#include<iostream>
#include<string.h>
#include<sstream>
using namespace std;
int main()
{
	int num;
	cin>>num;
	ostringstream str1;
	str1<<num;
	string geek = str1.str();
	cout<<geek;
}
