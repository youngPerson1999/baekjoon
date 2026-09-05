#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>
#include <cmath>

using namespace std;

bool is_movable(vector<vector<int>> maps, int x, int y) {
    if(x < 0 || y < 0 || x >= maps.size() || y >= maps[0].size()) return false;
    if(maps[x][y] == -1) return false;
    return true;
}


pair<int, int> init(vector<string> board, vector<vector<int>> &maps) {
    int n = board.size(), m = board[0].length();
    pair<int, int> s;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            char c = board[i][j];
            if(c == 'D') maps[i][j] = -1;
            else if(c == 'R') {
                maps[i][j] = 1;
                s.first = i;
                s.second = j;
            }
            else if(c == 'G') maps[i][j] = 2;
        }
    }
    return s;
}

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int bfs(vector<vector<int>> maps, pair<int, int> s) {
    queue<pair<pair<int, int>, int>> q;
    //방문  1, stoppable로 방문 2
    vector<vector<int>> visited(maps.size(), vector<int>(maps[0].size(), 0));
    
    q.push(make_pair(s, 0));
    visited[s.first][s.second] = 1;
    while(!q.empty()) {
        pair<int, int> curr = q.front().first;
        int dist = q.front().second;
        q.pop();
        if(visited[curr.first][curr.second] == 1) {
            if(maps[curr.first][curr.second] == 2)  return dist;
        }
        for(int i = 0; i < 4; i++)
        {
            int nx = curr.first, ny = curr.second;
            int nd = dist;
            while(is_movable(maps, nx + dx[i], ny + dy[i])) {
                nx += dx[i];
                ny += dy[i];
            }
            if((nx == curr.first && ny == curr.second) || visited[nx][ny] == 1) continue;
            visited[nx][ny] = 1;
            q.push(make_pair(make_pair(nx, ny), dist + 1));
            
        }
    }
    return -1;
}

int solution(vector<string> board) {
    int answer = 0;
    vector<vector<int>> maps(board.size(), vector<int>(board[0].length(), 0));
    pair<int, int> s = init(board, maps);
    answer = bfs(maps, s);
    return answer;
}

