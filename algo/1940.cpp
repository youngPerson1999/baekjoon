#include<iostream>
#include<vector>

using namespace std;

int main(){
    
    int n,m;
    cin>>n>>m;
    
    vector<bool>ar(10000001,false);
    for(int i=0;i<n;i++){
       int t; cin>>t; ar[t]=true;
    }
    int ans = 0;
    for(int i=1;i<=m/2;i++){
        if(ar[i]&&ar[m-i]&&i!=m-i) {
            ans++; 
        }
    }
    cout<<ans;
    
    return 0;
}
