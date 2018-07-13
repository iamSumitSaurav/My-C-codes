#include<iostream>
using namespace std;
int main()
{
	int n, k, i;
	cin>>n;
	int array[n][n], v[2*n-1][n];
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			cin>>array[i][j];
	
	int c = 0,j;
	while(c <= 2*n-1)
	{
		k = 0;
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
				if(i+j == c)
					v[c][k++] = array[i][j];
		c++;
	}
    for(i = 0; i < n; i++)
    {
    	int p = i+1;
    	for(int j = 0; j < p; j++)
    	{
			cout<<v[i][j]<<" ";
	    }
    	cout<<endl;
	}
	
	for(int m = i; m < 2*n-1; m++)
    {
    	int p = i-1;
    	for(int j = 0; j < p; j++)
    	{
			cout<<v[m][j]<<" ";
	    }
    	cout<<endl;
    	i--;
	}
	return 0;
}
