/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 2143                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: duddls4552 <boj.kr/u/duddls4552>            +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/2143                           #+#        #+#      #+#    */
/*   Solved: 2024/10/07 20:48:29 by duddls4552    ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include<iostream>
#include <vector>
#include <algorithm>

using namespace std;

int t, n, m;
long long case_num = 0;
vector<vector<int> > sum_A, sum_B;
vector<int> arr_A, arr_B;

int find_num_number(int goal)
{
    auto start_pos = lower_bound(arr_B.begin(), arr_B.end(), goal);
    auto end_pos = upper_bound(arr_B.begin(), arr_B.end(), goal);
    return end_pos - start_pos;
}

void cal_sum_AB()
{
    int a_size = arr_A.size(), b_size = arr_B.size();
    for (int i = 0; i < a_size; i++)
    {
        case_num += find_num_number(t - arr_A[i]);
    }
}

int main()
{
    vector<int> A, B;
    cin >> t;
    cin >> n;
    A.resize(n);
    sum_A.resize(n + 1);
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
        sum_A[i + 1].resize(n - i, 0);
        sum_A[1][i] = A[i];
        arr_A.push_back(A[i]);
    }
    cin >> m;
    B.resize(m);
    sum_B.resize(m + 1);
    for (int i = 0; i < m; i++)
    {
        cin >> B[i];
        sum_B[i + 1].resize(m - i, 0);
        sum_B[1][i] = B[i];
        arr_B.push_back(B[i]);
    }
    for (int i = 2; i <= n; i++)
        for (int j = 0; j <= n - i; j++)
        {
            sum_A[i][j] = sum_A[i - 1][j] + sum_A[1][i + j - 1];
            arr_A.push_back(sum_A[i][j]);
        }
    for (int i = 2; i <= m; i++)
        for (int j = 0; j <= m - i; j++)
        {
            sum_B[i][j] = sum_B[i - 1][j] + sum_B[1][i + j - 1];
            arr_B.push_back(sum_B[i][j]);
        }
    sort(arr_A.begin(), arr_A.end());
    sort(arr_B.begin(), arr_B.end());
    cal_sum_AB();
    cout << case_num << '\n';
    return 0;
}