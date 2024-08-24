#include<iostream>

using namespace std;

int main(){
    
    int n;
    
    cin>>n;
    if(n==1) {
        cout<<1;
        return 0;
    }
    int *rect = new int[n+1];
    rect[0] = 0;
    rect[1] = 1;
    rect[2] = 3;
    for(int i=3;i<=n;i++){
        rect[i] = (rect[i-1] + 2*rect[i-2])%10007;
    }
    cout<<rect[n];
    
    return 0;
}
