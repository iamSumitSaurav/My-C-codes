#include <iostream>
#include<stack>
#include <string>
using namespace std;

void display(char b)
{
    cout<<b;
}
int precedence(char a)
{
    if(a == '+' || a == '-')
    return 1;
    else if(a == '*')
    return 2;
    else if(a == '/')
    return 3;
    else if(a == '^')
    return 4;
    else return 0;
}
int main() {
    stack <char> s;
    string str;
    int T;
    cin>>T;
    while(T--)
    {
        cin>>str;
        for(int j=0; j<str.length(); j++)
        {
            if(str[j] == '(')   
                s.push(str[j]);
                
            if((str[j] >= 'A' && str[j] <= 'Z') || (str[j] >= 'a' && str[j] <= 'z'))
                display(str[j]);
                
            if(str[j] == '*' || str[j] == '/' || str[j] == '+' || str[j] == '-' || str[j] == '^')
            {
            	if(s.empty())
                	s.push(str[j]);
            	else{
            	    
                    if(precedence(str[j]) <= precedence(s.top()))
                    {
                        while((!s.empty()) && precedence(str[j]) <= precedence(s.top()) ){
                            display(s.top());
                            s.pop();
                        }
                        s.push(str[j]);
                    }
                    else
                        s.push(str[j]);
                        
            	}
            }
            
            if(str[j] == ')')
            {
                while(s.top()!='('){
                    display(s.top());
                    s.pop();
                }
                s.pop();
            }
            
        }
        while(!s.empty()){
            display(s.top());
            s.pop();
        }
        
        cout<<endl;
    }
	return 0;
}
