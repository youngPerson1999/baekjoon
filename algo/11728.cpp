#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    
    int n,m,t;
    
    cin>>n>>m;
    
    vector <int> arr(n+m);
    
    for(int i=0;i<n+m;i++){
        cin>>t;
        arr[i]=t;
    }
    
    sort(arr.begin(),arr.end());
    
    for(int i=0;i<n+m;i++) cout<<arr[i]<<" ";
    
    return 0;
}
