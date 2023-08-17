#include <iostream>
#include <vector>
#include <utility>
#include <queue>

using namespace std;

int n, m;
vector<vector<int> > map;
vector<vector<int> > dists;

void print_dists(){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m;j++){
            cout << dists[i][j] << " ";
        }
        cout << "\n";
    }
}

void find_dists(pair<int, int> goal){
    queue<pair<pair<int, int>, int> > q;
    q.push(make_pair(goal, 0));
    while(!q.empty()){
        int x = q.front().first.first;
        int y = q.front().first.second;
        int dist = q.front().second;
        q.pop();
        //up
        if(x > 0 && map[x-1][y] == 1 && dists[x-1][y] == 0){
            dists[x - 1][y] = dist + 1;
            q.push(make_pair(make_pair(x - 1, y), dist + 1));
        }
        // down
        if (x < n - 1 && map[x + 1][y]==1 && dists[x + 1][y] == 0)
        {
            dists[x + 1][y] = dist + 1;
            q.push(make_pair(make_pair(x + 1, y), dist + 1));
        }
        // left
        if (y > 0 && map[x][y - 1] == 1 && dists[x][y - 1] == 0)
        {
            dists[x][y - 1] = dist + 1;
            q.push(make_pair(make_pair(x, y - 1), dist + 1));
        }
        //right
        if(y < m - 1 && map[x][y+1]==1 && dists[x][y+1]==0){
            dists[x][y + 1] = dist + 1;
            q.push(make_pair(make_pair(x, y + 1), dist + 1));
        }
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m;j++)
            if(map[i][j]==1&&dists[i][j]==0)
                dists[i][j] = -1;
    print_dists();
}

int main()
{
    cin >> n >> m;
    map.resize(n, vector<int>(m));
    dists.resize(n, vector<int>(m, 0));
    pair<int, int> goal;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m;j++){
            cin >> map[i][j];
            if(map[i][j]==2)
                goal = make_pair(i, j);
        }
    find_dists(goal);
    return 0;
}