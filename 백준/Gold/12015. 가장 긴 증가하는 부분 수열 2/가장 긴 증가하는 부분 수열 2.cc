/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 12015                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: duddls4552 <boj.kr/u/duddls4552>            +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/12015                          #+#        #+#      #+#    */
/*   Solved: 2024/11/13 00:35:13 by duddls4552    ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> Ai;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    Ai.resize(n);
    for (int i = 0; i < n; i++)
        cin >> Ai[i];
    int length = 0;
    vector<int> LIS;
    LIS.push_back(0);
    for (int i = 0; i < n; i++)
    {
        if(LIS.back() < Ai[i])
        {
            LIS.push_back(Ai[i]);
        }
        else
        {
            int left = 0, right = LIS.size();
            while(left<right)
            {
                int mid = (left + right) / 2;
                if(LIS[mid]<Ai[i])
                {
                    left = mid + 1;
                }
                else
                {
                    right = mid;
                }
            }
            LIS[right] = Ai[i];
        }
    }
    cout << LIS.size() - 1 << '\n';
    return 0;
}