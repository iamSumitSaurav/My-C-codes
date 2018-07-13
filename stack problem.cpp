#include <iostream>
#include<stack>
using namespace std;

int main()
{
    stack <int> st;
    int T, result;
    string s;
    cin>>T;
    while(T--)
    {
        cin>>s;
        for(int i=0; i<s.length(); i++)
        {
            if(s[i] >= '0' && s[i] <= '9')
            st.push(s[i]);
            
            if(s[i]=='+' || s[i]=='-' || s[i]=='*' || s[i]=='/')
            {
                int k = st.top(); st.pop();
                int l = st.top(); st.pop();
                switch(s[i])
                {
                    case '+': result = l + k;
                              st.push(result);
                        
                    case '-': result = l - k;
                              st.push(result);
                        
                    case '*': result = l * k;
                              st.push(result);
                        
                    case '/': result = l / k;
                              st.push(result);
                }
                
            }
        }
        cout<<st.top()<<endl;
    }    
    return 0;
}
