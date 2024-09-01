#include <iostream>
#include <vector>

using namespace std;

int n, m, min_t=100000000, max_h;
vector<vector<int> > map;

void cal_t_h(int b, int t, int g)
{
    //substraction
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j<m; j++)
        {
            if(map[i][j] > g)
            {
                int subs = map[i][j] - g;
                b += subs;
                t += subs * 2;
            }
        }
    }
    // addition
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (map[i][j] < g)
            {
                int addi = g - map[i][j];
                b -= addi;
                t += addi;
            }
        }
    }
    if(b < 0) return;
    if (t < min_t)
    {
        min_t = t;
        max_h = g;
    }
}

int main(){
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int b, min = 256, max = 0;
    cin >> n >> m >> b;
    map.resize(n);
    for(int i = 0; i< n; i++)
    {
        map[i].resize(m);
        for(int j = 0; j < m; j++)
        {
            cin >> map[i][j];
            min = map[i][j] < min ? map[i][j] : min;
            max = map[i][j] > max ? map[i][j] : max;
        }
    }
    if(max != min)
    {
        for(int i = max; i >= min; i--)
        {
            //max부터 min까지 돌면서 max->전부더하는 방향임, min->전부 빼는 방방향임
            //가장 시간이 최소인 것을 고르면  됨.
            cal_t_h(b, 0, i);
        }
    }
    else
    {
        min_t = 0;
        max_h = max;
    }
    cout << min_t << ' ' << max_h << '\n';

    return 0;
}