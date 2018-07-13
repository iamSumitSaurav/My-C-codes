#include<bits/stdc++.h>
using namespace std;

int indexCalculator(int number, vector<int> A)
{
    int position;
    for(int i = 0; i < A.size(); i++)
        if(number == A[i])
        {
            position = i;
            break;
        }
    return position;
}

void maximumGap(const vector<int> A) {
    
    int n = A.size();
    //if(n == 1)
       // return 0;
        
    int array[n], index[n];
    
    for(int i = 0; i < n; i++)
        array[i] = A[i];
        
    sort(array, array+n);
    
    for(int i = 0; i < n; i++)
        index[i] = indexCalculator(array[i], A);
    
    for(int i = 0; i < n; i++)
        cout<<index[i]<<" ";
    
}


int main()
{
	vector<int> A;
	int temp, size;
	cout<<"Enter size";
	cin>>size;
	for(int i = 0; i < size; i++)
	{
		cout<<"Enter element "<<i+1<<":";
		cin>>temp;
		A.push_back(temp);
	}
	
	maximumGap(A);
}
