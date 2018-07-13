#include<iostream>
using namespace std;

void swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
	return;
}

int Partition(int A[], int start, int end)
{
	int pIndex = start;
	int pivot = A[end];
	for(int i = start; i < end; i++)
		{
			if(A[i] <= pivot)
			{
				swap(A[i], A[pIndex]);
				pIndex++;
			}
		}
	swap(A[end], A[pIndex]);
	return pIndex;
}

void QuickSort(int A[], int start, int end)
{
	if(start >= end)
		return;
	
	int pIndex = Partition(A, start, end);
	QuickSort(A, start, pIndex-1);
	QuickSort(A, pIndex+1, end);
}

int main()
{
	int arr[10];
	int n;
	cin>>n;
	for(int i = 0; i < n; i++)
	cin>>arr[i];
	cout<<"The sorted list is :" <<endl;
	QuickSort(arr, 0, n-1);
	for(int i = 0; i < n; i++)
	cout<<arr[i]<<" ";
	return 0;
}
