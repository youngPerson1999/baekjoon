/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 1707                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: duddls4552 <boj.kr/u/duddls4552>            +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/1707                           #+#        #+#      #+#    */
/*   Solved: 2025/03/19 20:40:22 by duddls4552    ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

bool bfs(vector<vector<int> >g, int v){
    vector<int> visited(v + 1, 0);
    for (int i = 1; i <= v; i++)
    {
        if(visited[i] > 0)
            continue;
        queue<int> q;
        q.push(i);
        visited[i] = 1;
        while (!q.empty())
        {
            int cur = q.front();
            q.pop();
            int e_size = g[cur].size();
            for (int j = 0; j < e_size; j++)
            {
                int next = g[cur][j];
                if(visited[next] == 0)
                {
                    if(visited[cur] == 1)
                        visited[next] = 2;
                    else
                        visited[next] = 1;
                    q.push(next);
                }
                if(visited[cur] == visited[next])
                    return false;
            }
        }
    }
    return true;
}

int main() {

    int t, v, e;
    cin >> t;
    while(t > 0)
    {
        
        t--;
        cin >> v >> e;
        vector<vector<int> > graph(v + 1);
        for (int i = 0; i < e; i++)
        {
            int a, b;
            cin >> a >> b;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        cout << (bfs(graph, v) == true ? "YES" : "NO") << '\n';
    }
    return 0;
}