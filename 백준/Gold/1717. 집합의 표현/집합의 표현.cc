/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 1717                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: duddls4552 <boj.kr/u/duddls4552>            +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/1717                           #+#        #+#      #+#    */
/*   Solved: 2024/10/05 12:56:47 by duddls4552    ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> n_set;

int find_parent(int a){
    if (n_set[a] != a)
        n_set[a] = find_parent(n_set[a]);
    return n_set[a];
}

void union_n(int a, int b)
{
    int a_p = find_parent(a), b_p = find_parent(b);
    if(a_p < b_p)
        n_set[b_p] = a_p;
    else
        n_set[a_p] = b_p;
}

void check_include(int a, int b)
{
    if (find_parent(a) == find_parent(b))
        cout << "YES\n";

    else
        cout << "NO\n";
}

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int m, cal, a, b;
    cin >> n >> m;
    n_set.resize(n + 1);
    for (int i = 0; i <= n; i++)
        n_set[i] = i;
    
    for (int i = 0; i < m; i++)
    {
        cin >> cal >> a >> b;
        if (cal == 0)
            union_n(a, b);
        else
            check_include(a, b);
    }

    return 0;
}