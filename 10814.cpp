#include<iostream>
#include<vector>
#include<string>
#include<utility>
#include<algorithm>

using namespace std;

int main(){
    
    int n;
    cin>>n;
    
    vector<pair<int,int> >mem;
    vector<string>names;
    //<order,age,name>
    for(int i=0;i<n;i++){
        int age; string name;
        cin>>age>>name;
        mem.push_back(make_pair(age,i));
        names.push_back(name);
    }
    
    stable_sort(mem.begin(),mem.end());
    
    for(int i=0;i<n;i++) cout<<mem[i].first<<" "<<names[mem[i].second]<<"\n";
    
    return 0;
}
