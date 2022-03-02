#include<iostream>
#include<queue>
#include<algorithm>
#include<utility>
#include<vector>
#define INF 2147483640

using namespace std;
int *d;
void dijkstra(int s,vector<pair<int,int> >g[]){
    d[s] = 0;
    priority_queue<pair<int,int> >pq;
    pq.push(make_pair(0,s));
    while(!pq.empty()){
        int dist = -pq.top().first;
        int curr = pq.top().second;
        pq.pop();
        if(d[curr]<dist) continue;
        for(int i=0;i<g[curr].size();i++){
            int next = g[curr][i].second;
            int nDist = g[curr][i].first + dist;
            if(nDist<d[next]){
                d[next] = nDist;
                pq.push(make_pair(-nDist,next));
            } 
        }
    }
}
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);

    int n,m,s,e,u,v,w;

    cin>>n>>m;

    vector<pair<int,int> >info[n+1];
    d = new int[n+1];
    for(int i=1;i<=n;i++) d[i] = INF;
    
    for(int i=0;i<m;i++){
        cin>>u>>v>>w;
        info[u].push_back(make_pair(w,v));
    }
    cin>>s>>e;
    dijkstra(s,info);
    cout<<d[e];
    
    return 0;
}
