#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <utility>
#define INF 300001

using namespace std;
int *d; bool*visited;
void dijkstra(int s,vector<pair<int,int> >g[]){
    d[s] = 0;
    visited[s] = true;
    priority_queue<pair<int,int> >pq;
    pq.push(make_pair(0,s));
    while(!pq.empty()){
        int dist = -pq.top().first;
        int curr = pq.top().second;
        pq.pop();
        if(d[curr]<dist) continue;
        visited[curr] = true;
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
int main()
{
    int v,e,s,u,ve,w;
    
    cin>>v>>e>>s;
    
    vector<pair<int,int> >g[v+1];
    d = new int[v+1]; visited = new bool[v+1];
    for(int i=1;i<=v;i++) d[i] = INF;
    for(int i=0;i<e;i++){
        cin>>u>>ve>>w;
        g[u].push_back(make_pair(w,ve));
    }
    dijkstra(s,g);
    for(int i=1;i<=v;i++) {
        if(d[i]!=INF) cout<<d[i]<<"\n";
        else cout<<"INF\n";
    }

    return 0;
}
