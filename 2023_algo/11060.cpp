#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

int n;
vector<int> maze(1001, 0);
vector<bool> visited(1001, false);

int calSol(){
    int rst = -1;
    queue<pair<int, int> > q;
    // index, the number of jump
    q.push(make_pair(0, 0));
    while(!q.empty()){
        int cur_i = q.front().first;
        int cur_c = q.front().second;
        q.pop();
        if(cur_i >= n)
            continue;
        if(cur_i == n - 1){
            rst = cur_c;
            break;
        }
        //insert biggest value -> to calculate minimum number of jump
        //biggest value means jumping to furthest maze
        for (int i = maze[cur_i]; i > 0; i--)
        {
            if (cur_i + i < n && !visited[cur_i + i])
            {
                visited[cur_i + i] = true;
                q.push(make_pair(cur_i + i, cur_c + 1));
            }
        }
    }
    return rst;
}

int main(){

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> maze[i];
    }

    cout << calSol() << "\n";

    return 0;
}