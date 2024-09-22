/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 10830                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: duddls4552 <boj.kr/u/duddls4552>            +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/10830                          #+#        #+#      #+#    */
/*   Solved: 2024/09/21 12:19:18 by duddls4552    ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>

using namespace std;

int n;
long long b;
vector<vector<int> > a;
vector<vector<vector<int> > > twosmat(38);

int mat_multi(vector<vector<int> > mat1,vector<vector<int> > mat2, int x, int y)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += mat1[x][i] * mat2[i][y];
    return sum % 1000;
}

vector<vector<int> > mat_sqr(vector<vector<int> > mat1, vector<vector<int> > mat2)
{
    vector<vector<int> > rst(n, vector<int>(n));
    for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                rst[i][j] = mat_multi(mat1, mat2, i, j);
    return rst;
}

void init_mat()
{
    twosmat[1] = a;
    for (int i = 2; i <= 37; i++)
        twosmat[i] = mat_sqr(twosmat[i - 1], twosmat[i - 1]);
}

void print_sol(vector<vector<int> > rst)
{
    for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++)
            {
                cout << rst[i][j] % 1000;
                if (j < n - 1)
                    cout << ' ';
            }
            cout << '\n';
    }
}

void sol()
{
    long long cnt = 0;
    int rest;
    bool is_first = true;
    vector<vector<int> > rst;
    while (b > 0)
    {
        rest = b % 2;
        b /= 2;
        cnt++;
        if (rest == 1)
        {
            if(is_first)
            {
                is_first = false;
                rst = twosmat[cnt];
            }
            else
                rst = mat_sqr(rst, twosmat[cnt]);
        }
    }
    print_sol(rst);
}

int main()
{
    cin >> n >> b;
    a.resize(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];
    if(b==1)
        print_sol(a);
    else
    {
        init_mat();
        sol();
    }
    return 0;
}