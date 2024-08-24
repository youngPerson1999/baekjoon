#include<iostream>
#include<vector>
#include<tuple>
#include<algorithm>
#include<string>

using namespace std;

int main(){
    
    vector<tuple<int, int, int, string> >gys;
    
    int n;
    
    cin>>n;
    
    for(int i=0;i<n;i++){
        string t;
        cin>>t;
        int a,b,c;
        cin>>a>>b>>c;
        gys.push_back(make_tuple(-a,b,-c,t));
    }
    stable_sort(gys.begin(),gys.end());
    for(int i=0;i<n;i++){
        cout<<get<3>(gys[i])<<"\n";
    }
    
    
    
    return 0;
}
