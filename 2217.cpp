#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    
    int n;
    
    cin>>n;
    
    vector<int>rope;
    
    for(int i=0;i<n;i++){
        int k;
        cin>>k;
        rope.push_back(k);
    }
    
    sort(rope.begin(),rope.end());
    
    int max = 0;
    
    for(int i=0;i<n;i++){
        int tmp_weight = rope[i]*(n-i);
        if(tmp_weight>max) max = tmp_weight;
    }
    cout<<max;
    
    return 0;
}
