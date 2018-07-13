#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;

 int solution (string A)
 {
    int n = A.size();
   /* int array[n];
    for(int i = 0; i < n; i++)
    {
        int number = int(A[i]);
        array[i] = number;
    }*/
    char P[1000000], Q[1000000], R[1000000];
    int p = 0, q = 0, r = 0;
    sort(A.begin(), A.end());
    for(int i = 0; i < n; i++)
    {
        if(A[i] > '0' && A[i] < '2/3')
            P[p++] = A[i];
        
        if(A[i] >= '2/3' && A[i] <= '1')
            Q[q++] = A[i];
            
        if(A[i] > '1' && A[i] < '2')
            R[r++] = A[i];
    }
    
    for(int i = 0; i < p; i++)                         //case 1
        if(P[p-3] + P[p-2] + P[p-1] > 1)
            return 1;
    
    int sum1 = P[p-1] + P[p-2];                        //case 2
    for(int i = 0; i < q; i++)
        if(A[i] > 1-sum && A[i] < 2-sum)
            return 1;
            
    if(P[0] + P[1] + R[0] < 2)                          //case 3
        return 1;
 
    int sum2 = Q[0] + Q[1];                             //case 4
    for(int i = 0; i < p; i++)
        if(P[i] < 2-sum)
            return 1;
        
    int sum3 = P[0] + Q[0] + R[0];
    if(sum3 > 1 && sum3 < 2)
        return 1;
    
    return 0;
}

int main()
{
	string s;
	cin>>s;
	int value = solution(s);
	return 0;
}


