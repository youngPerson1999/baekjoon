#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>

using namespace std;

string instr(int n){
    switch(n){
        case 0:
            return "zero";
        case 1:
            return "one";
        case 2:
            return "two";
        case 3:
            return "three";
        case 4:
            return "four";
        case 5:
            return"five";
        case 6:
            return "six";
        case 7:
            return "seven";
        case 8:
            return "eight";
        case 9:
            return "nine";
    }
}
int main(){
    
    int m,n;
    
    cin>>m>>n;
    
    vector<pair<string,int> >num(n-m+1);
    
    for(int i=m;i<=n;i++){
        if(i>=10){
            string tmp=instr(i/10);
            tmp += instr(i%10);
            num[i-m]=make_pair(tmp,i);
        }
        else num[i-m]=make_pair(instr(i),i);
    }
    sort(num.begin(),num.end());
    for(int i=0;i<=n-m;i++){
        cout<<num[i].second<<" ";
        if(i>0&&i%10==9) cout<<"\n";
    }
    
    
    return 0;
}
