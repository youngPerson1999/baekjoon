#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int t;
vector<pair<int, int> > books_num;

int is_possible(int end, int start, vector<bool> books)
{
    for (int i = start; i <= end; i++)
        if (books[i] == false)
            return i;
    return -1;
}

void greedy(int n, int m, int cnt)
{
    vector<bool> books(n + 1, false);
    for (int i = 0; i < m; i++)
    {
        int idx = is_possible(books_num[i].first, books_num[i].second, books);
        if (idx != -1)
        {
            books[idx] = true;
            cnt++;
        }
    }
    cout << cnt << "\n";
}
int main()
{
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int n, m, cnt = 0;
        cin >> n >> m;
        books_num.resize(m);
        int a, b;
        for (int j = 0; j < m; j++)
        {
            cin >> a >> b;
            books_num[j] = make_pair(b, a);
        }
        stable_sort(books_num.begin(), books_num.end());
        greedy(n, m, cnt);
    }
    return 0;
}