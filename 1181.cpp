#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

bool compare(string n1,string n2){

    if(n1.length() < n2.length())     return true;
    else if(n1.length() > n2.length())return false;
    else{
        if(n1.compare(n2)<0)    return true;
        else    return false;
    }
}

int main(){

    int n;
    
    cin>>n;

    string *words = new string[n];

    for(int i = 0;i<n;i++){
        cin>>words[i];
    }
    
    sort(words,words+n,compare);

    for(int i = 0;i<n;i++){
        if(i>0&&words[i].compare(words[i-1])==0) continue;
        cout<<words[i]<<endl;
    } 

    return 0;
}