/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 7490                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: duddls4552 <boj.kr/u/duddls4552>            +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/7490                           #+#        #+#      #+#    */
/*   Solved: 2025/03/19 16:01:56 by duddls4552    ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <vector>

using namespace std;

char op[3] = { ' ', '+', '-' };

void print_sol(vector<char> ops)
{
    int len = ops.size();
    for (int i = 1; i <= len; i++)
    {
        cout << i << ops[i - 1];
    }
    cout << len + 1;
    cout << '\n';
}

bool validate(vector<char> ops, int n)
{
    int prev_rst = 1;
    int rst = 0;
    for (int i = 2; i <= n; i++)
    {
        int cur_op = ops[i - 2];
        if(cur_op == ' ')
        {
            prev_rst *= 10;
            if(prev_rst >= 0)
                prev_rst += i;
            else
                prev_rst -= i;
        }
        else 
        {
            rst += prev_rst;
            if(cur_op == '+')
                prev_rst = i;
            else
                prev_rst = i * (-1);
        }
    }
    rst += prev_rst;

    return rst == 0;
}

void permutation (int d, int n, vector<char> ops)
{
    if(d == n)
    {
        if (validate(ops, n + 1))
            print_sol(ops);
        return;
    }
    for (int i = 0; i < 3; i++)
    {
        ops[d] = op[i];
        permutation(d + 1, n, ops);
    }
}


int main()
{
    int t, n;
    cin >> t;
    while (t > 0)
    {
        t--;
        cin >> n;
        vector<char> ops(n - 1);
        permutation(0, n - 1, ops);
        cout << '\n';
    }
}