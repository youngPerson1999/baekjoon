#include<iostream>
#include<vector>

using namespace std;

int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);
    
    int t,n;
    vector<int>num(1000001);
    num[0]=1;num[1]=1;num[2]=2;
    for(int j=3;j<=1000001;j++) num[j] = ((num[j-1]+num[j-2])%1000000009+ num[j-3])%1000000009;
    
    cin>>t;
    
    for(int i=0;i<t;i++){
        cin>>n;
        cout<<num[n]<<"\n";
    }
    
    return 0;
}
