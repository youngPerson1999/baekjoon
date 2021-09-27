#include<iostream>
#include<string>
#include<stack>
#include<sstream>

using namespace std;

string input;
stack<int> s;

int main(){
    
    cin>>input;
    
    int n = input.length();
    for(int i=0;i<n;i++){
        int c = input[i];
        if(c=='('||c=='[') s.push(c);
        else if(!s.empty()){
            if(c==')'&&s.top()=='(') s.pop();
            else if(c==']'&&s.top()=='[') s.pop();
            else{
                cout<<0;
                return 0;
            }
        }
        else if (s.empty() && (c==']' || c==')')){
            cout<<0;
            return 0;
        }
    }
    if(!s.empty()){
        cout<<0;
        return 0;
    }
    int i = 0; //it means the order of string input push stack
    int result = 0;
    while(i<n){
        if(input[i]=='(') s.push(-1);
        else if(input[i]=='[') s.push(-2);
        else if(!s.empty()&&input[i]==')'){
            if(s.top()==-1){
                s.pop();
                s.push(2);
            }
            else{   //case of number
                int tmp = 0;
                while(s.top()!=-1){
                    tmp += s.top();
                    s.pop();
                }
                s.pop();    //pop "("
                s.push(2*tmp);
            }
        }
        else if(!s.empty()&&input[i]==']'){
            if(s.top()==-2){
                s.pop();
                s.push(3);
            }
            else{   //case of number
                int tmp = 0;
                while(s.top()!=-2){
                    tmp += s.top();
                    s.pop();
                }
                s.pop();    //pop"["
                s.push(3*tmp);
            }
        }
        i++;
        //cout<<s.top()<<endl;
    }
    while(!s.empty()){
        result += s.top();
        s.pop();
    }
    if(s.empty()) cout<<result;
    else cout<<0;
    
    return 0;
}
