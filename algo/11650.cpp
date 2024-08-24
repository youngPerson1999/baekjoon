#include<iostream>
#include<utility>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    
    int n;
    
    cin>>n;
    
    vector<pair<int,int> >coor;
    
    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        coor.push_back(make_pair(x,y));
    }
    
    stable_sort(coor.begin(),coor.end());
    
    for(int i=0;i<n;i++) cout<<coor[i].first<<" "<<coor[i].second<<"\n";
    
    return 0;
}
