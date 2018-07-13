#include<iostream>
#include<math.h>
using namespace std;
int main()
{
	int n, arr[20];
	cin>>n;
	int q = 1, c = 0, r, i, sum = 0, k = 1;
	while(k < n)
	{
		i = c = 0;
		int originalk = k;
		while(q)
		{
			r = k % 10;
			q = k / 10;
			arr[i++] = r;
			k = q;
			c++;	
		}
	
		for(int j = 0; j < c; j++)
			sum += pow(arr[j], c);
		if(sum == originalk)
			cout<<sum<<" ";
		k = ++originalk;
	}
	return 0;
}
