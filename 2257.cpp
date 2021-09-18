#include <iostream>
#include <stack>
#include <string>
#include <cstdlib>

using namespace std;

string cf;
stack <string> s;

int main()
{
    cin>>cf;
    
    int i = 0;
    //H==1 C==12 O==16
    while(i<cf.length()){
        string t(1,cf[i]);
        if(t=="("||t=="H"||t=="C"||t=="O"){
            s.push(t);
        }
        else if(t==")"){
            int tmp = 0;
            while(s.top()!="("){
                if(s.top()=="H") tmp += 1;
                else if(s.top()=="C") tmp += 12;
                else if(s.top()=="O") tmp += 16;
                else{   //the result of sum
                    tmp += stoi(s.top());
                }
                s.pop();
            }
            s.pop();
            s.push(to_string(tmp));
        }
        else if(t>"1"&&t<="9"){
            int tmp;
            if(s.top()=="H") tmp = 1;
            else if(s.top()=="C") tmp = 12;
            else if(s.top()=="O") tmp = 16;
            else tmp = stoi(s.top());
            s.pop();
            tmp = tmp*stoi(t);
            s.push(to_string(tmp));
        }
        i++;
    }
    
    int sum = 0;
    
    while(!s.empty()){
        if(s.top()=="H") sum += 1;
        else if(s.top()=="C") sum += 12;
        else if(s.top()=="O") sum += 16;
        else{   //the result of sum
            sum += stoi(s.top());
        }
        s.pop();
    }
    
    cout<<sum;
    
    return 0;
}
