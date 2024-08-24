#include<iostream>
#include<string>
#include<deque>

using namespace std;

int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    
    int t,n;
    string p,x;
    bool r_check,d_check;
    
    cin>>t;
    
    for(int i=0;i<t;i++){
        cin>>p>>n>>x;
        deque <int> num;
        int tmp = 0;
        r_check = false;
        d_check = false;
        for(int j=1;j<x.length();j++){
            if(x[j]>='0'&&x[j]<='9'){
                tmp *= 10;
                tmp += x[j]-'0';
            }
            else if(x[j]==','||x[j]==']'){
                num.push_back(tmp);
                tmp = 0;
            }
        }
        for(int j=0;j<p.length();j++){
            if(p[j]=='R'){
                if(r_check) r_check = false;
                else r_check = true;
            }
            else if(p[j]=='D'){
                if(n<1){
                    d_check =  true;
                    break;
                }
                if(r_check) num.pop_back();
                else num.erase(num.begin());
                n--;
            }
        }
        if(!d_check){
            cout<<"[";
            if(n<1) cout<<"";
            else if(!r_check){
                for(int j=0;j<num.size();j++){
                    cout<<num[j];
                    if(j<num.size()-1) cout<<",";
                }
            }
            else if(r_check){
                for(int j=num.size()-1;j>=0;j--){
                    cout<<num[j];
                    if(j>0) cout<<",";
                }
            }
            cout<<"]\n";
        }
        else cout<<"error\n";
    }

    
    return 0;
}
