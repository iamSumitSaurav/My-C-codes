#include<iostream>
using namespace std;

int BinarySearch(int arr[], int size, int x)
{
	int start = 0;
	int end = size - 1;
	while(start <= end)
	{
		int mid = (start + end)/2;
		if(arr[mid] == x)
		{
			cout<<"Found at index:"<<" ";
			return mid;
		}
		else if(x < arr[mid])
			end = mid - 1;
		else
			start = mid + 1;
	}
	cout<<"Not found !! Default status:"<<" ";
	return -1;
}

int main()
{
	int n, number;
	cin>>n;
	int array[n];
	for(int i = 0; i < n; i++)
		cin>>array[i];
	cin>>number;
	int result = BinarySearch(array, n, number);
	cout<<result;
	return 0;
}
