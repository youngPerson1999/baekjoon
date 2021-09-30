#include<iostream>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;

int main(){
    
    string str;
    
    cin>>str;
    
    vector<string> word;
    
    for(int i=0;i<str.length();i++){
        word.push_back(str.substr(i));
    }
    
    sort(word.begin(),word.end());
    
    for(int i=0;i<str.length();i++) cout<<word[i]<<"\n";
}
