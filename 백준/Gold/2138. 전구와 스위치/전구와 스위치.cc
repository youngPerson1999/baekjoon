/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 2138                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: duddls4552 <boj.kr/u/duddls4552>            +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/2138                           #+#        #+#      #+#    */
/*   Solved: 2024/11/03 21:30:57 by duddls4552    ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#define INF 1000000000

using namespace std;

int n, cnt = 0;

vector<char> goal;
vector<char> need_to_chagne;

char swap(char c){
    return c == '0' ? '1' : '0';
}

bool validation(vector<char> v){
    for (int i = 0; i < n; i++){
        if(v[i] != goal[i])
            return false;
    }
    return true;
}

int greedy(vector<char> curr, int sol){
    for (int i = 1; i < n; i++)
    {
        if(curr[i - 1] != goal[i - 1]){
            sol++;
            curr[i - 1] = swap(curr[i - 1]);
            curr[i] = swap(curr[i]);
            if(i < n - 1)
                curr[i + 1] = swap(curr[i + 1]);
        }
    }
    if(validation(curr))
        return sol;
    else
        return INF;
}

int main()
{
    cin >> n;
    vector<char> curr(n);
    goal.resize(n);
    for (int i = 0; i < n; i++)
        cin >> curr[i];
    for (int i = 0; i < n; i++)
        cin >> goal[i];
    int sol1 = greedy(curr, 0);
    curr[0] = swap(curr[0]);
    curr[1] = swap(curr[1]);
    int sol2 = greedy(curr, 1);
    int min_sol = sol1 < sol2 ? sol1 : sol2;
    min_sol = min_sol == INF ? -1 : min_sol;
    cout << min_sol << '\n';

    return 0;
}