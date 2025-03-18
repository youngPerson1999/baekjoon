/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 18405                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: duddls4552 <boj.kr/u/duddls4552>            +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/18405                          #+#        #+#      #+#    */
/*   Solved: 2025/03/18 21:24:21 by duddls4552    ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, k, s, x, y;
vector<vector<int> > map;
priority_queue < pair<int, pair<int, int> >, vector<pair<int, pair<int, int> > >, greater<pair<int, pair<int, int> > > > pq;
//type, <x, y>

pair<int, pair<int, int> > make_coor(int type, int i, int j) {
    return make_pair(type, make_pair(i, j));
}

void print_map() {
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << map[i][j] << ' ';
        cout << '\n';
    }
}

void bfs(){
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int> > > > tmp_pq;
    while(!pq.empty())
    {
        int type = pq.top().first;
        int t_x = pq.top().second.first;
        int t_y = pq.top().second.second;
        pq.pop();
        // left
        if(t_x > 0 && map[t_x-1][t_y] == 0)
        {
            map[t_x - 1][t_y] = type;
            tmp_pq.push(make_coor(type, t_x - 1, t_y));
        }
        //right
        if (t_x < n - 1 && map[t_x + 1][t_y] == 0)
        {
            map[t_x + 1][t_y] = type;
            tmp_pq.push(make_coor(type, t_x + 1, t_y));
        }
        //up
        if (t_y > 0 && map[t_x][t_y - 1] == 0)
        {
            map[t_x][t_y - 1] = type;
            tmp_pq.push(make_coor(type, t_x, t_y - 1));
        }
        //down
        if (t_y < n - 1 && map[t_x][t_y + 1] == 0)
        {
            map[t_x][t_y + 1] = type;
            tmp_pq.push(make_coor(type, t_x, t_y + 1));
        }
    }
    pq = tmp_pq;
}

int main() {
    cin >> n >> k;
    map.resize(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> map[i][j];
            if( map[i][j] != 0)
            {
                pq.push(make_pair(map[i][j], make_pair(i, j)));
            }
        }
    }
    cin >> s >> x >> y;
    while(s > 0)
    {
        s--;
        bfs();
        if(map[x-1][y-1]!=0)
            break;
    }
    cout << map[x - 1][y - 1];
    return 0;
}