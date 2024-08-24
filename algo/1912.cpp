#include<iostream>
#include<cmath>

using namespace std;

int main(){
    
    int n;
    
    cin>>n;
    
    int *num = new int[n];
    int max_n = -1000;
    for(int i=0;i<n;i++) {
        cin>>num[i];
        max_n = max(max_n,num[i]);
    }
    if(max_n<=0){
        cout<<max_n;
        return 0;
    }
    for(int i=1;i<n;i++){
        num[i] = max(num[i],num[i]+num[i-1]);
        max_n = max(max_n,num[i]);
    }
    cout<<max_n;
    return 0;
}
