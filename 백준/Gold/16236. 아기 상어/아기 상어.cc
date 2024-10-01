/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 16236                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: duddls4552 <boj.kr/u/duddls4552>            +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/16236                          #+#        #+#      #+#    */
/*   Solved: 2024/10/01 13:41:12 by duddls4552    ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <deque>

using namespace std;

int n, eat_time = 0;
vector<vector<int> > space;
//1~6, num of fish
pair<int, int> start;

int bfs(pair<int, int> curr, pair<int, int> next, int size)
//먹을 수 있는 가장 가까운 물고기를 찾아가는 함수
//먹고 나면 0으로 바꾸자
{
    queue<pair<int, int> > q;
    vector<vector<int> > map(n, vector<int>(n, 0));
    q.push(curr);
    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        if (x == next.first && y == next.second)
            break;
        // up
        if (x > 0 && space[x - 1][y] <= size && map[x - 1][y] == 0)
        {
            map[x - 1][y] = map[x][y] + 1;
            q.push({x - 1, y});
        }
        //left
        if (y > 0 && space[x][y - 1] <= size && map[x][y - 1] == 0)
        {
            map[x][y - 1] = map[x][y] + 1;
            q.push({x, y - 1});
        }
        //down
        if (x < n - 1 && space[x + 1][y] <= size && map[x + 1][y] == 0)
        {
            map[x + 1][y] = map[x][y] + 1;
            q.push({x + 1, y});
        }
        //right
        if (y < n - 1 && space[x][y + 1] <= size && map[x][y + 1] == 0)
        {
            map[x][y + 1] = map[x][y] + 1;
            q.push({x, y + 1});
        }
    }
    return map[next.first][next.second] > 0 ? map[next.first][next.second] : -1;
}

deque<pair<pair<int, int>, int > > is_eatable(int size, pair<int, int> curr)
{
    int num = 0;
    deque<pair<pair<int, int>, int> > fish;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if(space[i][j] > 0 && space[i][j] < size)
                {
                    int dist = bfs(curr, {i, j}, size);
                    if(dist > 0)
                        fish.push_back({{i, j}, dist});
                }
    sort(fish.begin(), fish.end(), [](const pair<pair<int, int>, int>& a, const pair<pair<int, int>, int>& b) {
        // 첫 번째로 두 번째 int를 비교
        if (a.second != b.second) {
            return a.second < b.second;
        }
        // 두 번째로 첫 번째 pair의 first를 비교
        if (a.first.first != b.first.first) {
            return a.first.first < b.first.first;
        }
        // 마지막으로 첫 번째 pair의 second를 비교
        return a.first.second < b.first.second;
    });
    return fish;
}

int cal_dinner_time()
{
    int size = 2, dinner_time = 0;
    pair<int, int> curr = start;
    deque<pair<pair<int, int>, int> > fish = is_eatable(size, curr);
    int curr_eaten = 0;
    while (fish.size() > 0)
    {
        curr_eaten++;
        if (curr_eaten == size)
        {
            size++;
            curr_eaten = 0;
        }
        curr = fish.front().first;
        dinner_time += fish.front().second;
        space[curr.first][curr.second] = 0;
        fish.pop_front();
        fish = is_eatable(size, curr);
    }
    return dinner_time;
}

int main()
{
    bool isEatbale = false;
    cin >> n;
    space.resize(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            cin >> space[i][j];
            if (space[i][j] == 9)
                start = make_pair(i, j);
        }
    space[start.first][start.second] = 0;
    if (is_eatable(2, start).size() < 1)
        cout << 0 << '\n';
    else
        cout << cal_dinner_time() << '\n';
    return 0;
}