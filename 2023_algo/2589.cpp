#include <iostream>
#include <vector>
#include <utility>
#include <queue>

using namespace std;

int h, w;
vector<vector<char> > map;

int find_long(pair<int, int> loc, vector<vector<bool> > v){
    int max_dist = 0;
    queue<pair<pair<int, int>,int> > q;
    q.push(make_pair(loc,0));
    v[loc.first][loc.second] = true;
    while (!q.empty())
    {
        int y = q.front().first.first;
        int x = q.front().first.second;
        int cur_dist = q.front().second;
        q.pop();
        if (y > 0 && map[y - 1][x] == 'L' && !v[y-1][x]){
            q.push(make_pair(make_pair(y - 1, x), cur_dist + 1));
            v[y - 1][x] = true;
            max_dist = max_dist < cur_dist + 1 ? cur_dist + 1 : max_dist;
        }
        // down
        if(y < h - 1 && map[y + 1][x] == 'L' && !v[y+1][x]){
            q.push(make_pair(make_pair(y + 1, x), cur_dist + 1));
            v[y + 1][x] = true;
            max_dist = max_dist < cur_dist + 1 ? cur_dist + 1 : max_dist;
        }
        // left
        if(x > 0 && map[y][x - 1]=='L' && !v[y][x-1]){
            q.push(make_pair(make_pair(y, x - 1), cur_dist + 1));
            v[y][x - 1] = true;
            max_dist = max_dist < cur_dist + 1 ? cur_dist + 1 : max_dist;
        }
        // right
        if(x < w - 1 && map[y][x + 1]=='L' && !v[y][x+1]){
            q.push(make_pair(make_pair(y, x + 1), cur_dist + 1));
            v[y][x + 1] = true;
            max_dist = max_dist < cur_dist + 1 ? cur_dist + 1 : max_dist;
        }
    }
    return max_dist;
}

int main()
{

    cin >> h >> w;
    map.resize(h, vector<char>(w));
    vector<vector<bool> > visited(h, vector<bool>(w));

    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++){
            cin >> map[i][j];
            visited[i][j] = map[i][j] == 'W';
        }

    int max = 0;
    for (int i = 0; i < h; i++)
    {
        int tmp;
        for (int j = 0; j < w; j++)
        {
            if(map[i][j]=='W')
                continue;
            tmp = find_long(make_pair(i, j), visited);
            max = tmp > max ? tmp : max;
        }
    }
    cout << max << "\n";
    return 0;
}