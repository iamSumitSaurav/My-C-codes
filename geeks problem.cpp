#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
	int T;
	cin>>T;
	while(T--)
	{
	    int Q;
	    cin>>Q;
	    while(Q--)
	    {
	        long long int L, R, arr[abs(R-L+1)], index = 0;
	        cin>>L>>R;
	        if(L <= R)
	        {
	            for(int num = L; num <= R; num++)
	            {
	                int rem;
	                string s;
	                while(num)
	                {
	                    num = num/2;
	                    rem = num%2;
	                    s += to_string(rem);
	                }
	                int count = 0;
	                for(int i = 0; i < s.length(); i++)
	                {
	                    if(s[i] == '1')
	                        count++;
	                }
	                arr[index++] = count;
	            }
	        }
	        else
	        {
	            for(int num = R; num <= L; num++)
	            {
	                int rem;
	                string s;
	                while(num) 
	                {
	                    num = num/2;
	                    rem = num%2;
	                    s += to_string(rem);
	                }
	                int count = 0;
	                for(int i = 0; i < s.length(); i++)
	                {
	                    if(s[i] == '1')
	                        count++;
	                }
	                arr[index++] = count;
	            }
	        }
	        int result = 0;
	        for(int i = 0; i < index; i++)
	        {
	            if(arr[i] <= 3)
	                result++;
	        }
	        cout<<result;
	    }
	}
	return 0;
}
