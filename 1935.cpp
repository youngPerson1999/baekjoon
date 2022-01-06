#include<stack>
#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main(){
    cout << fixed;
    cout.precision(2);
    
    string in;
    int n;
    
    cin>>n>>in;
    
    vector<double>num(n);
    for(int i=0;i<n;i++)cin>>num[i];
    
    stack<double>s;
    
    for(int i=0;i<in.length();i++){
        if(in[i]>='A'&&in[i]<='Z'){
            s.push(num[in[i]-'A']);
        }
        else{
            double b=s.top(); s.pop(); double a=s.top(); s.pop();
            if(in[i]=='+') s.push(a+b);
            else if(in[i]=='-') {s.push(a-b);}
            else if(in[i]=='*') s.push(a*b);
            else if(in[i]=='/') s.push(a/b);
        }
    }
    
    cout<<s.top();
    
    return 0;
}
