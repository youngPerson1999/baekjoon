#include <iostream>
#include <vector>
#include <string>
#include <algorithm>    

using namespace std;

bool compare(string &a, string &b){
    return a.size()>b.size() ? true : false;
}

int main(){
    
    int i,j,n;
    int alpha[26] = { 0, };
    vector<string> words;
    
    cin>>n;
    
    for(i=0;i<n;i++){
        string tmp;
        cin>>tmp;
        words.push_back(tmp);
    }
    sort(words.begin(),words.end(),compare);    //long~short
    //for(j=0;j<n;j++) cout<<words[j]<<endl;
    int max = words[0].size();
    //cout<<"max : "<<max<<endl;
    for(i=0;i<max;i++){
        for(j=0;j<n;j++){
            if(words[j].size()<max-i) break;
            int index = i-max+words[j].size();
            //cout<<"i : "<<i<<" char : "<<words[j].at(index)<<endl;
            alpha[words[j].at(index)-'A']++;
        }
        for(j=0;j<26;j++) alpha[j] *= 10;
    }
    sort(alpha,alpha+26,greater<int>());
    i=9;    int sol = 0;
    for(j=0;j<26;j++) {
        if(alpha[j]==0) continue;
        alpha[j] /= 10;
        //cout<<alpha[j]<<endl;
        sol += alpha[j]*i;
        i--;
    }
    cout<<sol<<endl;
    return 0;
}
