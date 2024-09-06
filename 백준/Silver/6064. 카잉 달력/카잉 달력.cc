/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 6064                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: duddls4552 <boj.kr/u/duddls4552>            +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/6064                           #+#        #+#      #+#    */
/*   Solved: 2024/09/06 17:26:11 by duddls4552    ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

using namespace std;

int M, N, x, y;

int LSM(int a, int b)
{
    int lsm = a * b;
    int c;
    while(b!=0)
    {
        c = a % b;
		a = b;
		b = c;
    }
    return lsm / a;
}

int cal_cain_year()
{
    int max_year = LSM(M, N);
    for (int cur_year = x; cur_year <= max_year; cur_year += M)
    {
        int cur_y = cur_year % N == 0 ? N : cur_year % N;
        if(cur_y==y)
            return cur_year;
    }
    return -1;
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n;i++)
    {
        cin >> M >> N >> x >> y;
        cout << cal_cain_year() << '\n';
    }
    return 0;
}