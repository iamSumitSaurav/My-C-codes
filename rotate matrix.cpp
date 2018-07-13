#include<bits/stdc++.h>
using namespace std;

int k = 0;
void RotateMatrix(int A[][3], int n)
{
	int array[n*3];
	for(int j = 0; j < 3; j++)
		for(int i = n-1; i >= 0; i--)
			array[k++] = A[i][j];
	
	k = 0;
			
	for(int i = 0; i < n; i++)
		for(int j = 0; j < 3; j++)
		{
			A[i][j] = array[k];
			k++;
		}
}

int main()
{
	int n;
	cin>>n;
	int A[n][3];
	for(int i = 0; i < n; i++)
		for(int j = 0; j < 3; j++)
			cin>>A[i][j];
			
	RotateMatrix(A, n);
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < 3; j++)
			cout<<A[i][j]<<" ";
			
		cout<<endl;
	}
	return 0;
}
