#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
int n,m,comb[9];
void n_m(int depth, int k){
    if(depth==m){
        for(int j=0;j<m;j++)
            cout<<comb[j]<<" ";
        cout<<"\n";
        return;
    }
    else{
        for(int i=k;i<=n;i++){
            comb[depth] = i;
            n_m(depth+1,i);
        }
    }
}

int main(){
    
    cin>>n>>m;
    n_m(0,1);
    
    return 0;
}
