#include<iostream>
#include<vector>

using namespace std;

int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);
    
    int n,m,t,tmp;
    cin>>t;
    
    
    for(int i=0;i<t;i++){
        cin>>n>>m;
        int rst =tmp= 0;
        for(int j=n;j<=m;j++){
            tmp=j;
            if(tmp==0) {
                rst++;  continue;
            }
            while(tmp>0){
                if(tmp%10==0) rst++;
                tmp/=10;
            }
        }
        cout<<rst<<"\n";
    }
    
    
    return 0;
}
