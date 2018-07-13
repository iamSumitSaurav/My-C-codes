#include<iostream>
#include<string>
#include<string.h>
using namespace std;
int main()
{
	string s1, s2;
	cout<<"Enter first string \n";
	getline(cin, s1);
	cout<<"Enter second string \n";
	getline(cin, s2);
	int result = s1.compare(s2);
	cout<<result;
	return 0;
}
