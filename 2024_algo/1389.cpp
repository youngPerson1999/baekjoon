#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<vector<bool> > map;
int n;

void init_map()
{
    map.resize(n);
    for (int i = 0; i < n; i++)
        map[i].resize(n, false);
}

int cal_kevin_bacon(int start)
{
    //{person, dist}
    queue<pair<int, int> > q;
    vector<bool> visited(n, false);
    int kevin_bacon = 0;
    q.push({start, 0});
    visited[start] = true;
    while(!q.empty())
    {
        pair<int, int> q_top = q.front();
        q.pop();
        kevin_bacon += q_top.second;
        for (int i = 0; i < n; i++)
        {
            //push when not visited and friend
            if(!visited[i] && map[q_top.first][i]){
                q.push({i, q_top.second + 1});
                visited[i] = true;
            }
        }
    }
    return kevin_bacon;
}

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int m, r1, r2, min, min_per;
    cin >> n >> m;

    init_map();
    for (int i = 0; i < m; i++)
    {
        cin >> r1 >> r2;
        map[r1 - 1][r2 - 1] = true;
        map[r2 - 1][r1 - 1] = true;
    }
        min = 50000000;
    for (int i = 0; i < n; i++)
    {
        int kevin_cal = cal_kevin_bacon(i);
        if(kevin_cal < min)
        {
            min_per = i;
            min = kevin_cal;
        }
    }
    cout << min_per + 1 << '\n';

    return 0;
}