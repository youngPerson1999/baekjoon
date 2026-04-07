#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, k;
vector<int> A, robs;

void sub_A(int i) {
    if(A[i] == 0)
        return;
    robs[i] = 1;
    A[i]--;
    if(A[i] == 0)
        k--;
}

void down_robot() {
    if (robs[n - 1] == 1)
        robs[n - 1] = 0;
}

void rotation() {
    int tmp = A[2 * n - 1];
    copy(A.begin(), A.end() - 1, A.begin() + 1);
    A[0] = tmp;

    copy(robs.begin(), robs.end() - 1, robs.begin() + 1);
    down_robot();
    robs[0] = 0;
}

void move_robots() {
    for (int i = n - 2; i >= 0; i--)
    {
        if(robs[i] == 0)
            continue;
        if (A[i + 1] > 0 && robs[i + 1] == 0)
        {
            sub_A(i + 1);
            robs[i] = 0;
        }
    }
    down_robot();
}

void add_robot(){
    sub_A(0);
}

int main()
{
    cin >> n >> k;

    A.resize(2 * n);
    // 최대 n개
    robs.resize(n, 0);

    for (int i = 0; i < 2 * n; i++)
        cin >> A[i];

    int sol = 0;
    while (k > 0)
    {
        sol++;
        rotation();
        move_robots();
        add_robot();
    }

    cout << sol << '\n';

    return 0;
}