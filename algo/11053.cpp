#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;

int main(){
    
    int n;
    
    cin>>n;
    
    int *a = new int[n];
    int *cnt =  new int[n];
    
    fill(cnt,cnt+n,1);
    
    int sol = 0;
    
    for(int i=0;i<n;i++){
        cin>>a[i];
        for(int j=0;j<=i;j++){
            if(a[j]<a[i]) cnt[i] = max(cnt[i],cnt[j]+1);
        }
        sol = max(cnt[i],sol);
    }
    
    cout<<sol;
    
    return 0;
}
