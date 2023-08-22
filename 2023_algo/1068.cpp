#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> tree;
vector<bool> visited;
int n;

void bfs(int d)
{
    queue<int> q;
    q.push(d);
    tree[d] = -2;
    visited[d] = true;
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        for (int i = 0; i < n; i++)
        {
            if(tree[i] > -2 && tree[i] == cur){
                q.push(i);
                tree[i] = -2;
                visited[i] = true;
            }
        }
    }
}

int main(){
    
    cin >> n;
    tree.resize(n, -1);
    visited.resize(n, false);
    for (int i = 0; i < n; i++)
    {
        cin >> tree[i];
    }

    int del, cnt = 0;
    cin >> del;
    bfs(del);

    for (int i = 0; i < n; i++)
        if(tree[i] > -1)
            visited[tree[i]] = true;

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
            cnt++;
    }
    cout << cnt << "\n";
    return 0;
}