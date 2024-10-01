/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 17144                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: duddls4552 <boj.kr/u/duddls4552>            +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/17144                          #+#        #+#      #+#    */
/*   Solved: 2024/10/01 11:11:01 by duddls4552    ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <vector>

using namespace std;

int r, c, t;
vector<pair<int, int> > air_purifier;

vector<vector<int> > purifier(vector<vector<int> > map)
{
    vector<vector<int> > map_copy(r, vector<int>(c, 0));
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            map_copy[i][j] = map[i][j];
    // up
    pair<int, int> air = air_purifier[0];
    map_copy[air.first][1] = 0;
    for (int j = 2; j < c; j++)
        map_copy[air.first][j] = map[air.first][j - 1];
    for (int i = air.first - 1; i >= 0; i--)
        map_copy[i][c - 1] = map[i + 1][c - 1];
    for (int j = c - 2; j >= 0; j--)
        map_copy[0][j] = map[0][j + 1];
    for (int i = 1; i < air.first; i++)
        map_copy[i][0] = map[i - 1][0];
    //down
    air = air_purifier[1];
    map_copy[air.first][1] = 0;
    for (int j = 2; j < c; j++)
        map_copy[air.first][j] = map[air.first][j - 1];
    for (int i = air.first + 1; i < r; i++)
        map_copy[i][c - 1] = map[i - 1][c - 1];
    for (int j = c - 2; j >= 0; j--)
        map_copy[r - 1][j] = map[r - 1][j + 1];
    for (int i = r - 2; i > air.first; i--)
        map_copy[i][0] = map[i + 1][0];
    return map_copy;
}

vector<vector<int> > spread(vector<vector<int> > map)
{
    vector<vector<int> > map_copy(r, vector<int>(c, 0));
    for (int i = 0; i < r; i++)
    {
        bool up = i > 0, down = i < r - 1;
        for (int j = 0; j < c; j++)
        {
            if(map[i][j] <= 0)
            {
                if (map[i][j] < 0)
                    map_copy[i][j] = map[i][j];
                continue;
            }
            bool left = j > 0, right = j < c - 1;
            int sp = map[i][j] / 5;
            if (up && map[i - 1][j] >= 0)
            {
                map_copy[i - 1][j] += sp;
                map[i][j] -= sp;
            }
            if (down && map[i + 1][j] >= 0)
            {
                map_copy[i + 1][j] += sp;
                map[i][j] -= sp;
            }
            if (left && map[i][j - 1] >= 0)
            {
                map_copy[i][j - 1] += sp;
                map[i][j] -= sp;
            }
            if (right && map[i][j + 1] >= 0)
            {
                map_copy[i][j + 1] += sp;
                map[i][j] -= sp;
            }
            map_copy[i][j] += map[i][j];
        }
    }
    return map_copy;
}

int main()
{
    cin >> r >> c >> t;
    vector<vector<int> > map(r, vector<int>(c));
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
        {
            cin >> map[i][j];
            if (map[i][j] == -1)
                air_purifier.push_back({i, j});
        }
    for (int i = 0; i < t; i++)
        map = purifier(spread(map));
    int sum = 0;
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            if(map[i][j] > 0)
                sum += map[i][j];
    cout << sum << '\n';
    return 0;
}
