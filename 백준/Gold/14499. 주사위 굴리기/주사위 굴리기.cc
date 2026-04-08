#include <iostream>
#include <vector>

using namespace std;

int n, m, x, y;
vector<vector<int>> map;
// east, west, north, south
vector<int> dx = {0, 0, -1, 1};
vector<int> dy = {1, -1, 0, 0};
//바닥은 6 윗면은 1번째
vector<int> dice(6, 0);

bool is_movable(int d)
{
    int n_x = x + dx[d];
    int n_y = y + dy[d];
    if (n_x < 0 || n_x >= n || n_y < 0 || n_y >= m)
        return false;
    return true;
}

void roll_dice(int d)
{
    int t0 = dice[0];
    //0,1 -> 1,4유지
    if (d == 0)
    {
        dice[0] = dice[3];
        dice[3] = dice[5];
        dice[5] = dice[2];
        dice[2] = t0;
    }
    else if(d==1)
    {
        dice[0] = dice[2];
        dice[2] = dice[5];
        dice[5] = dice[3];
        dice[3] = t0;
    }
    //2,3 -> 2,3유지
    else if(d == 2)
    {
        dice[0] = dice[4];
        dice[4] = dice[5];
        dice[5] = dice[1];
        dice[1] = t0;
    }
    else
    {
        dice[0] = dice[1];
        dice[1] = dice[5];
        dice[5] = dice[4];
        dice[4] = t0;
    }
}

void cal_next_loc(int d)
{
    roll_dice(d);
    x += dx[d];
    y += dy[d];
}

void write_dice_map()
{
    if(map[x][y] == 0)
    {
        map[x][y] = dice[5];
    }
    else
    {
        dice[5] = map[x][y];
        map[x][y] = 0;
    }
}

int cal_upper_dice(int d)
{
    if(!is_movable(d))
    {
        return -1;
    }
    cal_next_loc(d);
    write_dice_map();
    return dice[0];
}

int main()
{
    int k, d;
    cin >> n >> m >> x >> y >> k;
    map.resize(n, vector<int>(m));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> map[i][j];
        }
    }
    for (int i = 0; i < k; i++)
    {
        cin >> d;
        int upper_dice = cal_upper_dice(d - 1);
        if(upper_dice < 0)
            continue;
        cout << upper_dice << '\n';
    }
    return 0;
}