#include<iostream>
#include<stack>
#include<string>

using namespace std;

bool ps_tf(string input){

    stack<char>ps;

    for(int j=0;j<input.length();j++){
            if(input.length()%2==1||input[0]==')'||input[input.length()-1]=='('){
                return false;
            }
            if(input[j]=='('){
                ps.push('(');
            }
            else if(input[j]==')'){ 
                if(ps.empty())  return false;
                ps.pop();       
            }
    }
    return ps.empty();
}

int main(){

    int n,i;
    string input;

    cin>>n;

    for(i=0;i<n;i++){

        cin>>input;
        
        if(ps_tf(input))  cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }

    return 0;
}