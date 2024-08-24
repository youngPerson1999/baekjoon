#include<iostream>
#include<vector>
#include<queue>
#include<utility>

using namespace std;

int main(){
    
    int t,n,m,tmp,sol;
    
    cin>>t;
    
    for(int i=0;i<t;i++){
        cin>>n>>m;
        queue<pair<int,int> > q;
        priority_queue<int> pq;
        sol=0;
        for(int j=0;j<n;j++){
            cin>>tmp;
            q.push(make_pair(j,tmp));
            pq.push(tmp);
        }
        while(!q.empty()){
            if(q.front().second<pq.top()){
                q.push(q.front());
                q.pop();
            }
            else if(q.front().second==pq.top()){
                int idx = q.front().first;
                q.pop(); pq.pop();
                sol++;
                if(idx==m) break;
            }
        }
        cout<<sol<<"\n";
    }
    
    return 0;
}
