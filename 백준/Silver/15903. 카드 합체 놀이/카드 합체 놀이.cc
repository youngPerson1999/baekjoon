/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 15903                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: duddls4552 <boj.kr/u/duddls4552>            +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/15903                          #+#        #+#      #+#    */
/*   Solved: 2024/10/31 19:40:58 by duddls4552    ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n, m;

int main(){
    cin >> n >> m;
    priority_queue<long long, vector<long long>, greater<long long>> q;
    int in;
    for (int i = 0; i < n; i++)
    {
        cin >> in;
        q.push(in);
    }
    for (int i = 0; i < m; i++)
    {
        long long min1 = q.top();
        q.pop();
        long long min2 = q.top();
        q.pop();
        q.push(min1 + min2);
        q.push(min1 + min2);
        }
    long long sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += q.top();
        q.pop();
    }
    cout << sum << '\n';
    return 0;
}