#include<iostream>
using namespace std;

void maximumSubarray(int Array[], int n)
{
	int max_so_far = 0, max_ends_here = 0;
	int beg = 0, end = 0;
	for(int i = 0; i < n; i++)
	{
		max_ends_here = max_ends_here + Array[i];
		
		if(max_ends_here < 0)
		{
			max_ends_here = 0;
			beg = i+1;
		}
		
		if(max_ends_here > max_so_far)
		{
			max_so_far = max_ends_here;
			end = i;
		}
	}
	cout<<"The corresponding sub-array is \n";
	for(int i = beg; i <= end; i++)
		cout<<Array[i]<<" ";
	cout<<endl;
	cout<<"And the corresponding sum is = "<<max_so_far;
}
int main()
{
	int size;
	cin>>size;
	int array[size];
	for(int i = 0; i < size; i++)
		cin>>array[i];
	maximumSubarray(array, size);
	return 0;
}
