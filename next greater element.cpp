#include <iostream>
#include<stack>
using namespace std;

int main()
{
    stack <int> s;
    int T, N, A[1000], j=1, flag=0;
    cin>>T;
    while(T--)
    {
        cin>>N;
        for(int i=0; i<N; i++)
        cin>>A[i];
        s.push(-1);
        for(int k=N-j-1; k>=0; j++)
        {
            int baseIndex=k;
            int base=A[k];
            while(baseIndex < N-1)
            {
                baseIndex++;
                if(A[baseIndex] > base)
                {
                    flag++;
                    break;
                }
                if(flag > 0)
                s.push(A[baseIndex]);
                else
                s.push(-1);
            }
        }
        while(!s.empty())
        {
            cout<<s.top()<<" ";
            s.pop();
        }
        cout<<endl;
    }
}
