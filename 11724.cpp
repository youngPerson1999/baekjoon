#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<algorithm>

using namespace std;

int cc,n;

int c_check(bool check[]){
    for(int i=1;i<=n;i++){
        if(check[i]==false) return i;
    }
    return -1;
}
void bfs(int start,vector<int>g[],bool check[]){
    queue<int> q;
    
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
            }
        }
    }
    
}

int main(){
    
    int m;
    
    cin>>n>>m;
    
    bool check[n+1];
    
    vector<int>graph[n+1];  //row is dynamic
    
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    
    for(int i=1; i<=n; i++){
		sort(graph[i].begin(), graph[i].end());
	}
	
	cc = 0;
    
    fill(check,check+n+1,false);
    while(c_check(check)!=-1){
        int s = c_check(check);
        bfs(s,graph,check);
        cc++;
    }
    cout<<cc;
    return 0;
}
