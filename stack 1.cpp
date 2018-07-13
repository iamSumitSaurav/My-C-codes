#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;


int main()    
{
    stack <char> s,s1,s2;
    int Q, indicator,i,j,k,no,l=0;
    int choice;
    cin>>Q;
    while(Q--)
    {
        string str;        
        cin>>choice;
        switch(choice)
        {
            case 1: cin>>str;
                    i=0;
                    while(i<str.length())
                    {
                        s.push(str[i]);
                        i++;
                    }
                    indicator=1;
                    break;
                
            case 2: cin>>k;
                    j=1;
                    while(j<=k)
                    {
                        s1.push(s.top());
                        s.pop();
                        j++;
                    }
                    indicator=0;
                    break;
                
            case 3: cin>>no;
                    i=1;
                    while(i<(s.size()-no+1))
                    {    
                        s2.push(s.top());
                        s.pop();
                        i++;
                        l++;
                    }
                    cout<<s.top()<<endl;
                    if(l>0)
                        while(!s2.empty())
                        {
                            s.push(s2.top());
                            s2.pop(); 
                            l=0;
                        }
                    break;
                
            case 4: if(indicator==1)
                    {
                        j=0;
                        while(j<str.length())
                            s.pop();
                    indicator=0;
                    }
                    else if(indicator==0)
                    {
                        while(!s1.empty())
                        {
                            s.push(s1.top());
                            s1.pop();
                        }
                        indicator=1;
                    }
                    break;
        }
    }
    return 0;
}
