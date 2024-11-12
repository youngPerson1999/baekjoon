/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 2473                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: duddls4552 <boj.kr/u/duddls4552>            +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/2473                           #+#        #+#      #+#    */
/*   Solved: 2024/11/13 00:01:50 by duddls4552    ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <stdlib.h>
#include <tuple>
#include<algorithm>
#define MIN 60000000000
#define MAX_IDX 6000
using namespace std;

int n, a, b, c, p_idx = -1;
vector<int> koi;
long long min_sol = MIN;

int binary_search(int k, int f_idx){
    int low = k + 1, high = n - 1, mid, sol = MAX_IDX;
    long long tmp_sum = koi[k] + koi[f_idx];

    while (low <= high)
    {
        mid = (low + high) / 2;
        long long sum = (long long)koi[mid] + tmp_sum;
        if (abs(sum) < min_sol)
        {

            // cout << koi[f_idx] << ' ' << koi[k] << ' ' << koi[mid] << ' ' <<abs (sum) << '\n';
            min_sol = abs(sum);
            sol = mid;
        }
        if (sum == 0)
            return mid;
        else if(sum > 0)
            high = mid - 1;
        else
            low = mid + 1;
    }

    return sol;
}

void find_comb(){
    for (int i = 0; i < n - 2; i++)
    {
        for (int j = i + 1; j < n; j++){
            int tmp = binary_search(j, i);
            if (tmp < MAX_IDX)
            {
                a = koi[i];
                b = koi[j];
                c = koi[tmp];
                if (min_sol == 0)
                    break;
            }
        }
    }
}

int main(){
    cin >> n;
    koi.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> koi[i];
        if (p_idx < 0 && koi[i] >= 0)
            p_idx = i;
    }
    sort(koi.begin(), koi.end());
    if (koi[n - 1] <= 0)
    {
        //전부 음수인 경우
        a = koi[n - 3];
        b = koi[n - 2];
        c = koi[n - 1];
    }
    else if (koi[0] >= 0 || n == 3)
    {
        //전부 양수, 0인 경우
        a = koi[0];
        b = koi[1];
        c = koi[2];
    }
    else{
        find_comb();
    }
    cout << a << ' ' << b << ' ' << c << '\n';
    return 0;
}