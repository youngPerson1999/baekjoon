#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int n, max_val = -1000000001, min_val = 1000000001;
char oper_show(int oper) {
    if(oper == 0)
        return '+';
    else if(oper ==1 )
        return '-';
    else if(oper==2)
        return '*';
    return '/';
}

int cal_oper(int a, int b, int oper) {
    if(oper == 0)
        return a + b;
    else if(oper == 1)
        return a - b;
    else if(oper == 2)
        return a * b;
    else
        return a / b;
}

void cal(int d, vector<int> oper, vector<int> A) {
    if(d == n) {
        if(A[n - 1] > max_val)
        max_val = A[n - 1];
        if (A[n - 1] < min_val)
            min_val = A[n - 1];
        return;
    }
    else {
        int A_cp = A[d];
        for (int i = 0; i < 4; i++)
        {
            if(oper[i] == 0)
                continue;
            oper[i]--;
            A[d] = cal_oper(A[d - 1], A[d], i);
            cal(d + 1, oper, A);
            oper[i]++;
            A[d] = A_cp;
        }
    }
}

int main()
{
    
    vector<int> A;
    cin >> n;
    A.resize(n);
    for (int i = 0; i < n; i++)
        cin >> A[i];
    // + - * /
    vector<int> oper(4);
    for (int i = 0; i < 4; i++)
        cin >> oper[i];
    cal(1, oper, A);
    cout << max_val << '\n'
         << min_val << '\n';
    return 0;
}