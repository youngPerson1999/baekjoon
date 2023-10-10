#include <iostream>
#include <vector>

using namespace std;

long long n, max_n;
vector<int> dice(6);
vector<int> min_n(3);
// A B C D E F
void combi(int r, int i, int d, vector<int> c, vector<int> idx)
{
    if(r == 0)
    {
        int size = c.size(), min = 0;
        for (int i = 0; i < size; i++)
        {
            min += c[i];
            for (int j = 0; j < size; j++)
            {
                if(idx[i] + idx[j] == 5)
                    return;
            }
        }
        min_n[size - 1] = min_n[size - 1] < min ? min_n[size - 1] : min;
    }
    else if(d == 6)
        return;
    else
    {
        c[i] = dice[d];
        idx[i] = d;
        combi(r - 1, i + 1, d + 1, c, idx);
        combi(r, i, d + 1, c, idx);
    }
}
int main()
{
    //(C,D) (E,B) (A,F)
    //정육면체로 쌓으면 됨
    min_n[0] = 50, min_n[1] = 100, min_n[2] = 150, max_n = 0;
    cin >> n;
    for (int i = 0; i < 6; i++)
    {
        cin >> dice[i];
        min_n[0] = min_n[0] < dice[i] ? min_n[0] : dice[i];
        max_n = max_n < dice[i] ? dice[i] : max_n;
    }
    if(n == 1)
    {
        int sum = 0;
        for (int i = 0; i < 6; i++)
            sum += dice[i];
        cout << sum - max_n << "\n";
        return 0;
    }
    vector<int> comb(2);
    vector<int> idx(2);
    combi(2, 0, 0, comb, idx);
    comb.resize(3);
    idx.resize(3);
    combi(3, 0, 0, comb, idx);
    long long sol = 4 * min_n[2];
    sol += min_n[1] * 4 * (2 * n - 3);
    sol += min_n[0] * (long long)((n - 2) * (5 * n - 6));
    cout << sol << "\n";
    return 0;
}