#include <iostream>
#include <vector>
#include<utility>
#include<cmath>
#include<algorithm>

using namespace std;
int d(pair<int,int>a,pair<int,int>b){
    return pow((a.first-b.first),2)+pow((a.second-b.second),2);
}
int main()
{
    int t,x,y;
    
    cin>>t;
    
    for(int i=0;i<t;i++){
        vector<pair<int,int> >a;
        for(int i=0;i<4;i++){
            cin>>x>>y;
            a.push_back(make_pair(x,y));
        }
        stable_sort(a.begin(),a.end());
        if(d(a[0],a[1])==d(a[0],a[2])&&d(a[3],a[1])==d(a[3],a[2])&&d(a[0],a[3])==d(a[1],a[2])){
            cout<<1;
        }
        else cout<<0;
        cout<<"\n";
    }
    
    return 0;
}
