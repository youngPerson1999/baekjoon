/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 2467                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: duddls4552 <boj.kr/u/duddls4552>            +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/2467                           #+#        #+#      #+#    */
/*   Solved: 2024/11/10 20:22:13 by duddls4552    ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

int n, a, b, p_idx = -1;
vector<int> koi;
pair<int, int> p;

pair<long long, pair<int, int> > binary_search(int k){
    int low = k+1, high = n - 1;
    long long k_min = 25000000000;

    pair<int, int> tmp_p;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        long long sum = (long long)koi[mid] + (long long)koi[k];
        if(abs(sum) < k_min){
            tmp_p = make_pair(k, mid);
            k_min = abs(sum);
        }
        if (sum == 0)
            return make_pair(0, tmp_p);
        else if(sum > 0)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return make_pair(abs(k_min), tmp_p);
}

void find_comb(){
    long long min_sol = 25000000000;
    for (int i = 0; i < p_idx; i++)
    {
        pair<long long, pair<int, int> > tmp = binary_search(i);
        if(tmp.first < min_sol){
            p = tmp.second;
            min_sol = tmp.first;
            if(min_sol == 0)
                break;
        }
    }
    a = koi[p.first];
    b = koi[p.second];
}

int main(){
    cin >> n;
    koi.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> koi[i];
        if (p_idx < 0 && koi[i] > 0)
            p_idx = i;
    }
    if (p_idx < 0 || koi[n - 1] <= 0)
    {
        //전부 음수인 경우
        a = koi[n - 2];
        b = koi[n - 1];
    }
    else if (koi[0] >= 0 || n == 2)
    {
        //전부 양수, 0인 경우
        a = koi[0];
        b = koi[1];
    }
    else{
        find_comb();
    }
    cout << a<<' ' << b << '\n';
    return 0;
}