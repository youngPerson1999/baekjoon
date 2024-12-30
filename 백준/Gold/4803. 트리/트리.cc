#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<bool> visited;
vector<int> parent;

bool bfs(vector<vector<int> > g, int n, int start) {
    queue<int> q;
    q.push(start);
    visited[start] = true;
    while(!q.empty()) {
        int curr = q.front();
        q.pop();
        int curr_size = g[curr].size();
        for(int i = 0; i < curr_size; i++)
        {
            int next = g[curr][i];
            if(visited[next]) {
                if(next == parent[curr]) continue;
                else return false;
            }
            q.push(next);
            visited[next] = true;
            parent[next] = curr;
        }
    }
    return true;
}

vector<vector<int> > input (int n, int m) {
    vector<vector<int> > graph(n);
    int a, b;
    for(int i = 0; i< m; i++) {
        cin>>a>>b;
        graph[a-1].push_back(b-1);
        graph[b-1].push_back(a-1);
    }
    visited.clear();
    parent.clear();
    visited.resize(n, false);
    parent.resize(n, 0);
    return graph;
}

int solve (vector<vector<int> > graph, int n) {
    int tree = 0;
    for(int i = 0; i< n; i++) {
        if(visited[i]) continue;
        if(bfs(graph, n, i)) tree++;
    }
    return tree;
}

int main(){
    int cnt = 0;
    while(1) {
        cnt++;
        int a, b;
        cin>>a>>b;
        if(a==0 && b== 0) break;
        int trees = solve(input(a, b), a);
        cout<<"Case "<<cnt<<": ";
        if(trees == 0) cout<<"No trees.";
        else if(trees == 1) cout<<"There is one tree.";
        else cout<<"A forest of "<<trees<<" trees.";
        cout<<'\n';
    }
    return 0;
}