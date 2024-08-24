#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<algorithm>

using namespace std;

int n;

void bfs(int start,vector<int>g[],bool check[]){
    queue<int> q;
    int p_node[n+1];
    fill(p_node,p_node+n+1,-1);
    
    q.push(start);
    check[start] = true;
    
    while(!q.empty()){
        int curr = q.front();
        q.pop();
        for(int i=0;i<g[curr].size();i++){
            int next = g[curr][i];
            if(check[next]==false){
                q.push(next);
                check[next] = true;
                p_node[next] = curr;
            }
        }
    }
    for(int i=2;i<=n;i++) cout<<p_node[i]<<"\n";
}

int main(){
    
    int m;
    
    cin>>n;
    
    bool check[n+1];
    
    vector<int>graph[n+1];  //row is dynamic
    
    for(int i=1;i<n;i++){
        int a,b;
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    
    for(int i=2; i<=n; i++){
		sort(graph[i].begin(), graph[i].end());
	}
    
    fill(check,check+n+1,false);
    bfs(1,graph,check);

    return 0;
}
