#include <iostream>
#include<string>

using namespace std;

int main()
{
    string s;
    
    cin>>s;
    
    for(int i=0;i<s.length();){
        if(s[i]=='p'&&s[i+1]=='i'&&i+1<s.length()){
            i+=2;
        }
        else if(s[i]=='k'&&s[i+1]=='a'&&i+1<s.length()){
            i+=2;
        }
        else if(s[i]=='c'&&s[i+1]=='h'&&s[i+2]=='u'&&i+2<s.length()){
            i+=3;
        }
        else{
            cout<<"NO"; return 0;
        }
    }
    cout<<"YES";
    return 0;
}
