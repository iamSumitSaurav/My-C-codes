#include<iostream>
using namespace std;
/*
int arraySize(int arr[]){
	int a = sizeof(arr);
	int b = sizeof(arr[0]);
	cout<<"a="<<a<<" b="<<b<<endl;
	return a/b ;
}  */
void Merge(int left[], int leftSize, int right[], int rightSize, int arr[], int n)
{
	//int leftSize = arraySize(left);
	//int rightSize = arraySize(right);
	//cout<<"checkpoint 5"<<endl;
	int i, j, k;
	i = j = k = 0;
	while(i < leftSize && j < rightSize)
	{
		if(left[i] <= right[j])
		{
			arr[k] = left[i];
			i++;
			k++;
		}
		else
		{
			arr[k] = right[j];
			j++;
			k++;
		}
	}
	if(i < leftSize)
	{
		arr[k] = left[i];
		i++;
		k++;
	}
	if(j < rightSize)
	{
		arr[k] = right[j];
		j++;
		k++;
	}
	//cout<<"checkpoint 6"<<endl;
}

void MergeSort(int arr[], int n)
{
	//int n = arraySize(arr);
	//cout<<n;
	//cout<<"checkpoint 1"<<endl;
	if(n < 2) 
		return;
	int mid = n/2;
	int left[mid];
	int right[n-mid];
	for(int i = 0; i < mid; i++)
		left[i] = arr[i];
	for(int i = mid; i < n; i++)
		right[i-mid] = arr[i];
	MergeSort(left, mid);
	//cout<<"checkpoint 2"<<endl;
	MergeSort(right, n-mid);
	//cout<<"checkpoint 3"<<endl;
	Merge(left, mid, right, n-mid, arr, n);
	//cout<<"checkpoint 4"<<endl;
}

int main()
{
	int size;
	cin>>size;
	int array[size];
	for(int i = 0; i < size; i++)
		cin>>array[i];
	//int x = arraySize(array);
	//cout<<"x="<<x<<endl;
	//cout<<sizeof(array)<<endl;
	//cout<<sizeof(array[0])<<endl;
	MergeSort(array, size);
	cout<<"The sorted list is:"<<endl;
	for(int i = 0; i < size; i++)
		cout<<array[i]<<" ";
	return 0;
}
