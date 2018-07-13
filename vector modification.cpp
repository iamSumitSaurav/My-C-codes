#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int solution(int A[], int n){
    int checker, num1, num2;
    int array[n];
	int k = 0;
    for(int i = 0; i < n; i++)
    {
        array[i] = A[i];
    }
    sort(array, array+n);
    
    for(int i = 0; i < n-1; i++)
    {
        checker = array[i+1] -array[i];
        if(checker == 0)
            num1 = array[i];
        if(checker == 2)
        {
		    num2 = array[i] + 1;
		    k++;
		}
    }
    if(k == 0)
    {
    	cout<<num1<<" "<<array[n-1]+1;
	}
	else
		cout<<num1<<" "<<num2;
    
}
int main()
{
	int n;
	cin>>n;
	int array[n];
	for(int i = 0; i < n; i++)
	{
		cin>>array[i];
	}
	solution(array, n);
	return 0;
}
