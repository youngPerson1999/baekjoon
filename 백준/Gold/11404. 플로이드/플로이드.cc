/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 11404                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: duddls4552 <boj.kr/u/duddls4552>            +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/11404                          #+#        #+#      #+#    */
/*   Solved: 2024/09/07 19:25:45 by duddls4552    ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <vector>
#define MAX 10000001

using namespace std;

int n, m;
vector<vector<int> > city;

void floyd()
{
    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                city[i][j] = min(city[i][j], city[i][k] + city[k][j]);        
}

int main()
{
    cin >> n >> m;
    city.resize(n, vector<int>(n, MAX));
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        city[a - 1][b - 1] = min(city[a - 1][b - 1], c);
    }
    for (int i = 0; i < n; i++)
        city[i][i] = 0;
    floyd();
    for (int i = 0; i < n;i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << (city[i][j] < MAX ? city[i][j] : 0);
            if (j < n - 1)
                cout << ' ';
        }

        if (i < n - 1)
            cout << '\n';
    }
    return 0;
}