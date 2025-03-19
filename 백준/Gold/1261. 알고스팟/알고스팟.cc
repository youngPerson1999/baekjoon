/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 1261                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: duddls4552 <boj.kr/u/duddls4552>            +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/1261                           #+#        #+#      #+#    */
/*   Solved: 2025/03/19 18:54:50 by duddls4552    ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <string>
#include <vector>
#include <deque>

using namespace std;

int n, m;
vector<vector<int> > map;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void bfs() {
    deque<pair<int, pair<int, int> > > dq;
    dq.push_back(make_pair(0, make_pair(0, 0)));
    while (!dq.empty())
    {
        int c = dq.front().first;
        int x = dq.front().second.first;
        int y = dq.front().second.second;
        if (x == n - 1 && y == m - 1)
        {
            cout << c;
            return;
        }
        dq.pop_front();
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx >= n || nx < 0 || ny >= m || ny < 0)
                continue;
            if(map[nx][ny] == 0)
            {
                dq.push_front(make_pair(c, make_pair(nx, ny)));
            }
            else if(map[nx][ny] == 1)
            {
                dq.push_back(make_pair(c + 1, make_pair(nx, ny)));
            }
            map[nx][ny] = -1;
        }
    }
}

int main(){

    cin >> m >> n;
    map.resize(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        for (int j = 0; j < m; j++)
            map[i][j] = str[j] - '0';
    }
        bfs();
}