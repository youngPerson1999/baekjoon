/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 15686                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: duddls4552 <boj.kr/u/duddls4552>            +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/15686                          #+#        #+#      #+#    */
/*   Solved: 2024/09/28 00:14:18 by duddls4552    ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>

using namespace std;

int n, m, num_c, min_d=10000000;
vector<vector<int> > map;
vector<pair<int, int> > house;
vector<pair<int, int> > chicken;


int cal_distance(pair<int, int> a, pair<int, int> b){
    int x = a.first > b.first ? a.first - b.first : b.first - a.first;
    int y = a.second > b.second ? a.second - b.second : b.second - a.second;

    return x + y;
}

void brute_force(vector<pair<int, int> >c)
{
    int num_h = house.size();
    int sum_dist = 0;
    vector<int> house_dist(num_h, 1000000);
    for (int i = 0; i < num_h; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int dist = cal_distance(house[i], c[j]);
            house_dist[i] = house_dist[i] > dist ? dist : house_dist[i];
        }
    }
    for (int i = 0; i < num_h;i++)
        sum_dist += house_dist[i];
    min_d = min_d > sum_dist ? sum_dist : min_d;
}

void combination (int depth, int next, vector<pair<int, int> >v)
{
    if(depth == m){
        brute_force(v);
        return;
    }
    for(int i = next; i < num_c; i++){
        v[depth] = chicken[i];
        combination(depth + 1, i + 1, v);
    }
}



int main()
{
    cin >> n >> m;
    map.resize(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            {
                cin >> map[i][j];
                if (map[i][j] == 1)
                    house.push_back({i, j});
                if(map[i][j]==2)
                    chicken.push_back({i, j}); 
            }
    num_c = chicken.size();
    vector<pair<int, int> > v(m);
    combination(0, 0, v);
    cout << min_d << '\n';
    return 0;
}