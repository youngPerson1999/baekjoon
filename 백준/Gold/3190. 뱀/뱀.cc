#include <iostream>
#include <deque>
#include <vector>

using namespace std;

int n, k, l;
vector<vector<int> > map;
deque<pair<int, char> > dirs;

pair<char, pair<int, int> > make_coor(pair<int, int> coor, char d) {
    return make_pair(d, coor);
}

char cal_next_dir (char dir, char l) {
    if(dir == 'R'){
        if(l == 'D') return 'B';
        else return 'T';
    }
    else if(dir == 'B'){
        if(l == 'D') return 'L';
        else return 'R';
    }
    else if(dir == 'L'){
        if(l == 'D') return 'T';
        else return 'B';
    }
    else if(dir == 'T'){
        if (l == 'D') return 'R';
        else return 'L';
    }
}

pair<int, int> cal_next_coor (pair<int, int> coor, char d) {
    if(d=='R') {
        if(coor.second == n-1) return make_pair(-1, -1);
        return make_pair(coor.first, coor.second + 1);
    }
    else if(d=='L') {
        if(coor.second == 0) return make_pair(-1, -1);
        return make_pair(coor.first, coor.second - 1);
    }
    else if(d=='T') {
        if(coor.first == 0) return make_pair(-1, -1);
        return make_pair(coor.first - 1, coor.second);
    }
    else {
        if(coor.first == n - 1) return make_pair(-1, -1);
        return make_pair(coor.first + 1, coor.second);
    }
}

int solve() {
    deque<pair<char, pair<int, int> > >dq, dq_copy;
    int cur_time = 0;
    dq.push_back(make_coor(make_pair(0, 0), 'R'));
    map[0][0] = 2;
    while(1){
        pair<int, int> curr_coor = dq.front().second;
        char curr_dir = dq.front().first;
        char next_dir;
        //다음 머리 위치
        if(!dirs.empty() && dirs.front().first == cur_time) {
            pair<int, char> dir = dirs.front();
            next_dir = cal_next_dir(curr_dir, dir.second);
            dirs.pop_front();
        }
        else {
            next_dir = curr_dir;
        }
        cur_time++;
        pair<int, int> next_coor = cal_next_coor(curr_coor, next_dir);
        if(next_coor.first == -1 || next_coor.second == -1) break;
        if(map[next_coor.first][next_coor.second] == 2) break;
        dq.push_front(make_coor(next_coor, next_dir));
        if(map[next_coor.first][next_coor.second] != 1){
            map[dq.back().second.first][dq.back().second.second] = 0;
            dq.pop_back();
        }
        map[next_coor.first][next_coor.second] = 2;
    }
    return cur_time;
}

int main(){
    cin>>n>>k;
    map.resize(n, vector<int>(n, 0));
    for(int i = 0; i < k; i++)
    {
        int x, y;
        cin>>x>>y;
        map[x-1][y-1] = 1;
    }
    cin>>l;
    dirs.resize(l);
    for(int i = 0; i < l; i++)
    {
        int a;
        char b;
        cin>>a>>b;
        dirs[i] = make_pair(a, b);
    }
    int rst = solve();
    cout<<rst<<'\n';
    
    return 0;
}