#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<algorithm>

using namespace std;

void dfs(int start,vector<int>g[],bool check[]){
    stack<int> s;
    
    s.push(start);
    check[start] = true;
    
    cout<<start<<" ";
    
    while(!s.empty()){
        int curr = s.top();
        s.pop();
        for(int i=0;i<g[curr].size();i++){
            int next = g[curr][i];
            if(check[next]==false){
                cout<<next<<" ";
                check[next] = true;
                s.push(curr);
                s.push(next);
                break;
            }
        }
        
    }
    
}
void bfs(int start,vector<int>g[],bool check[]){
    queue<int> q;
    
    q.push(start);
    check[start] = true;
    
    while(!q.empty()){
        int curr = q.front();
        cout<<curr<<" ";
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
    
    int n,m,s;
    
    cin>>n>>m>>s;
    
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
    
    
    fill(check,check+n+1,false);
    dfs(s,graph,check);
    cout<<"\n";
    fill(check,check+n+1,false);
    bfs(s,graph,check);
    
    return 0;
}
