#include <iostream>
#include <vector>

using namespace std;


long long cal_cat(int n){
    if(n<=1) return 1;

    vector<unsigned long long> cat(31);
    cat[0]=cat[1]=1;
    for(int i=2;i<=n;i++){
        cat[i]=0;
        for(int j=0;j<i;j++) cat[i] += cat[j]*cat[i-j-1];
    }
    return cat[n];
    
}

int main(){
    // ios_base :: sync_with_stdio(false);
    // cin.tie(NULL); cout.tie(NULL); 
    vector<unsigned long long> catalan(31);
    for(int i=1;i<=30;i++) catalan[i] = cal_cat(i);
    int t,c=0;
    while(c<1000){
        cin>>t;
        if(t!=0) cout<<catalan[t]<<"\n";
        c++;
        if(t==0||c>=1000) break;
    }
    
    return 0;
}
