#include<iostream>
#include<vector>

using namespace std;

int main(){
    
    int n;
    
    cin>>n;
    
    if(n==1) return 0;
    
    int *num = new int[n+1];
    vector<int> prime;
    for(int i = 2;i<=n;i++) num[i] = i;
    for(int i=2;i<=n;i++){
        if(num[i]==0) continue;
        prime.push_back(i);
        for(int j=i+i;j<=n;j+=i) num[j] = 0;
    }
    
    for(int i=0;n>1;){
        if(n%prime[i]==0){
            cout<<prime[i]<<endl;
            n /= prime[i];
            continue;
        }
        i++;
    }
    
    return 0;
}
