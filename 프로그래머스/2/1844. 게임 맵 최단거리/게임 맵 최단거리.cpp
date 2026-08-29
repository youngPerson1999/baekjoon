#include<vector>
#include <queue>

using namespace std;

int bfs(vector<vector<int> > maps) {
    int n = maps.size(), m = maps[0].size();
    vector<vector<bool>> visited (n, vector<bool>(m, false));
    // ((x, y), dist)
    queue<pair<pair<int, int>, int>> q;
    q.push(make_pair(make_pair(0, 0), 1));
    visited[0][0] = true;
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    while(!q.empty()) {
        pair<int, int> cur = q.front().first;
        int dist = q.front().second;
        q.pop();
        if(cur.first == n - 1 && cur.second == m - 1)
        {
            return dist;
        }
        for(int i = 0; i < 4; i++)
        {
            int x = cur.first + dx[i];
            int y = cur.second + dy[i];
            if(x >= 0 && x < n && y >= 0 && y < m) {
                if(!visited[x][y] && maps[x][y] == 1) {
                    q.push(make_pair(make_pair(x, y), dist + 1));
                    visited[x][y] = true;
                }
            }
        }
    }
    return -1;
}

int solution(vector<vector<int> > maps)
{
    int answer = 0;
    answer = bfs(maps);
    return answer;
}