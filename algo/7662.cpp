#include<iostream>
#include<set>

using namespace std;

int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);
    
    int t,k,n;
    
    cin>>t;
    
    for(int i=0;i<t;i++){
        cin>>k;
        multiset<int> pq;
        char di;
        for(int j=0;j<k;j++){
            cin>>di>>n;
            if(di=='I') pq.insert(n);
            else if(di=='D'&&pq.size()>0){
                if(n<0) pq.erase(pq.begin());
                else pq.erase(--pq.end());
            }
        }
        if(pq.empty()) cout<<"EMPTY\n";
        else cout<<*--pq.end()<<" "<<*pq.begin()<<"\n";
    }
        
    return 0;
}
