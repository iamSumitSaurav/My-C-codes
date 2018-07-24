#include<bits/stdc++.h>

using namespace std;
int main()
{
	map <int, string> customer;
	int n, key;
	string value;
	cout<<"How many key-value pairs do you want to enter?\n";
	cin>>n;
	for(int i = 0; i < n; i++)
	{
		cout<<"Key "<<i+1<<":"<<endl;
		cin>>key;
		cout<<"Value "<<i+1<<":"<<endl;
		cin>>value;
		customer.insert(pair <int, string> (key, value));
	}
	map <int, string>::iterator p;
	p = customer.begin();
	while(p != customer.end())
	{
		cout<<p->first<<"--->"<<p->second<<endl;
		p++;
	}
	return 0;
}

