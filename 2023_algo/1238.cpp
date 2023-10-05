#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#define INF 10000001

using namespace std;

int n, m, x;
vector<int> get_min_weight(int start, vector<vector<int> >town)
{
    vector<bool> visited(n + 1, false);
    vector<int> dist(n + 1, INF);
    dist[start] = 0;
    priority_queue<pair<int, int>, vector<pair<int,int> >, greater<pair<int,int> > > pq;
    pq.push(make_pair(start, 0));
    while(!pq.empty())
    {
        int curr = pq.top().first;
        int c_dist = pq.top().second;
        pq.pop();
        if(dist[curr] < c_dist)
            continue;
        for (int i = 1; i <= n; i++)
        {
            if(i == curr)
                continue;
            int n_dist = c_dist + town[curr][i];
            if(n_dist < dist[i])
            {
                dist[i] = n_dist;
                pq.push(make_pair(i, n_dist));
            }
        }
    }
    return dist;
}
int main()
{
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m >> x;
    vector<vector<int> > town(n + 1, vector<int>(n + 1, INF));
    vector<vector<int> > reverse_town(n + 1, vector<int>(n + 1, INF));
    ;
    for (int i = 0; i < m; i++)
    {
        int s, e, t;
        cin >> s >> e >> t;
        //단방향
        town[s][e] = t;
        reverse_town[e][s] = t;
    }
    int max = 0;
    vector<int> to = get_min_weight(x, town);
    vector<int> from = get_min_weight(x, reverse_town);
    for (int i = 1; i <= n; i++)
    {
        int tmp = to[i] + from[i];
        max = tmp > max ? tmp : max;
    }
    cout << max << "\n";

    return 0;
}