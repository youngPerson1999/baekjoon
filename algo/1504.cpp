#include<iostream>
#include<queue>
#include<algorithm>
#include<utility>
#include<vector>
#define INF 24000001

using namespace std;
int n,*d;
vector<pair<int,int> >g[801];
void dijkstra(int s){
    d = new int[n+1];
    for(int i=1;i<=n;i++) d[i] = INF;
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

    int m,v1,v2,u,v,w,d_1,d_2;

    cin>>n>>m;      
    
    for(int i=0;i<m;i++){
        cin>>u>>v>>w;
        g[u].push_back(make_pair(w,v));
        g[v].push_back(make_pair(w,u));
    }

    cin>>v1>>v2;

    dijkstra(1);
    if(d[v1]>=INF&&d[v2]>=INF){
        cout<<-1;
        return 0;
    }
    d_1 = d[v1]; d_2 = d[v2];
    delete d;

    dijkstra(v1);
    if(d[v2]>=INF){
        cout<<-1;
        return 0;
    }
    d_1 += d[v2]; d_2 += d[v2];
    delete d;

    dijkstra(v2);
    d_1 += d[n];
    delete d;
    dijkstra(v1);
    d_2 += d[n];

    if(d_1>=INF&&d_2>=INF) cout<<-1;
    else cout<<(d_1<d_2?d_1:d_2);
    
    return 0;
}
