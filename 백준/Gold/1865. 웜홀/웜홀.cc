/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 1865                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: duddls4552 <boj.kr/u/duddls4552>            +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/1865                           #+#        #+#      #+#    */
/*   Solved: 2024/09/15 01:12:42 by duddls4552    ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <vector>
#include <tuple>
#define MAX 114748364

using namespace std;

int n, m, w, e_size;
vector<tuple<int, int, int> > edges;

bool bellman_ford()
{
    vector<int> bellman(n, MAX);
    bellman[0] = 0;
    bool isUpdate = false;
    for (int i = 0; i < n; i++)
    {
        isUpdate = false;
        for (int j = 0; j < e_size; j++)
        {
            //first -> from second -> to
            tuple<int, int, int> edge = edges[j];
            int from = get<0> (edge);
            int to = get<1> (edge);
            int cost = get<2> (edge);
            if (bellman[to] > bellman[from] + cost)
            {
                if (i == n - 2)
                    return true;
                bellman[to] = bellman[from] + cost;
                isUpdate = true;
            }
        }
        if(!isUpdate)
            return false;
    }

}

int main()
{
    int tc, s, e, t;
    cin >> tc;
    for (int i = 0; i < tc; i++)
    {
        e_size = 0;
        cin >> n >> m >> w;
        for (int j = 0; j < m; j++)
        {
            cin >> s >> e >> t;
            edges.push_back(make_tuple(s - 1, e - 1, t));
            edges.push_back(make_tuple(e - 1, s - 1, t));
        }
        for (int j = 0; j < w; j++)
        {
            cin >> s >> e >> t;
            edges.push_back(make_tuple(s - 1, e - 1, -t));
        }
        e_size = edges.size();
        if (bellman_ford())
            cout << "YES\n";
        else
            cout << "NO\n";
        edges.resize(0);
    }
    return 0;
}