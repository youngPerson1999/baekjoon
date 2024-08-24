#include<iostream>
#define ll long long

using namespace std;

int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);
    
    ll n;
    
    cin>>n;
    
    ll ans = 1;
    for(int i=1;i<=n;i++){
        ans*=i;
        ans%=10000000000000;
        while(ans%10==0) ans/=10;
    }
    
    cout<<ans%10;
    
    return 0;
}
