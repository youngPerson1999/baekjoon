#include<iostream>
#include<stack>
#include<string>

using namespace std;

int main(){
    
    stack<char>left;
    stack<char>right;
    
    string start;
    cin>>start;
    for(int i=0;i<start.length();i++) left.push(start[i]);
    
    int m;
    cin>>m;
    char order;
    for(int i=0;i<m;i++){
        cin>>order;
        if(order=='L'){
            if(!left.empty()){
                right.push(left.top());
                left.pop();
            }
        }
        else if(order=='D'){
            if(!right.empty()){
                left.push(right.top());
                right.pop();
            }
        }
        else if(order=='B'){
            if(!left.empty()) left.pop();
        }
        else if(order=='P'){
            char t;
            cin>>t;
            left.push(t);
        }
    }
    while(!left.empty()){
        right.push(left.top());
        left.pop();
    }
    while(!right.empty()){
        cout<<right.top();
        right.pop();
    }
    return 0;
}
