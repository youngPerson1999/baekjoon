#include<iostream>
#include<algorithm>
#include<vector>
#include<utility>

using namespace std;

bool cmp(const pair<int, int> &a, const pair<int, int> &b)
{
    return a.second < b.second;
}
int main(){
    
    int n;
    
    cin>>n;
    
    vector<pair<int,int> >coordi;
    vector<pair<int,int> >copy;
    
    for(int i=0;i<n;i++){
        int num;
        cin>>num;
        coordi.push_back(make_pair(i,num));
    }
    
    sort(coordi.begin(),coordi.end(),cmp);
    
    int i = 0;
    int order = 0;
    
    while(i<n){
        if(i>0&&coordi[i].second==coordi[i-1].second){
            copy.push_back(make_pair(coordi[i].first,order-1));
        }
        else{
            copy.push_back(make_pair(coordi[i].first,order));
            order++;
        }
        i++;
    }
    sort(copy.begin(),copy.end());
    for(int i=0;i<n;i++){
        cout<<copy[i].second<<" ";
    }
    return 0;
}
