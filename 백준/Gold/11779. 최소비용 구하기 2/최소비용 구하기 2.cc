/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 11779                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: duddls4552 <boj.kr/u/duddls4552>            +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/11779                          #+#        #+#      #+#    */
/*   Solved: 2024/09/19 23:13:38 by duddls4552    ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <deque>
#include <queue>
#define INF 100000000

using namespace std;

int n, m, s_city, e_city, n_cities = 0;
vector<vector<pair<int, int> > > edges;
vector<int> dist;
vector<bool> visited;
vector<int> path;

int find_smallest_city()
{
    int min_dist = INF;
    int min_idx = -1;
    for (int i = 1; i <= n; i++)
    {
        if (visited[i] == true)
        	continue;
        if (dist[i] < min_dist)
        {
        	min_dist = dist[i];
            min_idx = i;
        }
    }
    return min_idx;
}

void dijkstra()
{
    priority_queue<pair<int, int> > pq;
    dist[s_city] = 0;
    visited[s_city] = true;
    pq.push(make_pair(0, s_city));
    while(!pq.empty())
    {
        int curr_city = pq.top().second;
        int curr_dist = pq.top().first;
        pq.pop();
        //이미 업데이트 된 도시는 방문하지 않겟다
        if (dist[curr_city] != curr_dist) continue;
        for (int i = 0; i < edges[curr_city].size(); i++)
        {
            int next_city = edges[curr_city][i].first;
            int next_value = edges[curr_city][i].second;
            if(dist[next_city] > dist[curr_city] + next_value)
            {
                dist[next_city] = dist[curr_city] + next_value;
                path[next_city] = curr_city;
                pq.push(make_pair(dist[curr_city] + next_value, next_city));
            }
        }
    }
}
void print_path()
{
    cout << dist[e_city] << '\n';

    int cur_city = e_city;
    deque<int> route;
    while(cur_city != -1)
    {
        route.push_front(cur_city);
        cur_city = path[cur_city];
    }
    cout << route.size()<<'\n';
    for (int i = 0; i < route.size(); i++)
        cout << route[i] << ' ';
}

int main()
{
    cin >> n >> m;
    dist.resize(n + 1, INF);
    visited.resize(n + 1, false);
    edges.resize(n + 1);
    path.resize(n + 1, -1);
    for (int i = 0; i < m; i++)
    {
        int s, e, v;
        cin >> s >> e >> v;
        edges[s].push_back({e, v});
    }
    cin >> s_city >> e_city;
    dijkstra();
    // for (int i = 1; i <= n;i++)
    //     cout << path[i] << ' ';
    print_path();
    return 0;
}