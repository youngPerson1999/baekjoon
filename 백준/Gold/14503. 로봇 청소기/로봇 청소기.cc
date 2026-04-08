#include <iostream>
#include <vector>

using namespace std;

// r,c -> robot's current loc
int n, m, cleaned = 0, d, r, c;
bool is_working = true;
vector<vector<int>> map;
//d = 0 north,1 east,2 south, 3 west
vector<int> dx = {-1, 0, 1, 0};
vector<int> dy = {0, 1, 0, -1};

// 1 = wall, 0 = unvisited, -1 = cleaned
void clean_map() {
    if(map[r][c] == 0)
    {    
        map[r][c] = -1;
        cleaned++;
    }
}


void yes_clean_map(){
    d--;
    if(d < 0)
        d = 3;
    // north -> west, east -> north
    int next_x = r + dx[d];
    int next_y = c + dy[d];
    if(next_x < 0 || next_x >= n || next_y < 0 || next_y >= m)
        return;
    if(map[next_x][next_y] != 0)
        return;
    r = next_x;
    c = next_y;
}

bool is_possible_clean(){
    for (int i = 0; i < 4; i++)
    {
        int next_x = r + dx[i];
        int next_y = c + dy[i];
        if (next_x < 0 || next_x >= n || next_y < 0 || next_y >= m)
            continue;
        if(map[next_x][next_y] == 0)
            return true;
    }
    return false;
}

bool move_possible_back(){
    int d_back = d > 1 ? d - 2 : d + 2;
    int next_x = r + dx[d_back];
    int next_y = c + dy[d_back];
    if(next_x < 0 || next_x >= n || next_y < 0 || next_y >= m)
        return false;
    if(map[next_x][next_y] == 1)
        return false;
    r = next_x;
    c = next_y;
    return true;
}

int main()
{
    cin >> n >> m;
    cin >> r >> c >> d;
    map.resize(n, vector<int>(m));

    for (int i = 0; i < n; i ++)
    {
        for (int j = 0; j < m; j++)
            cin >> map[i][j];
    }
    while(1) {
        // clean current location
        clean_map();
        if(!is_possible_clean())
        {
            // if there is no location to clean
            if (!move_possible_back())
                break;
        }
        else
        {
            yes_clean_map();
        }
    }
    cout << cleaned << '\n';
    return 0;
}