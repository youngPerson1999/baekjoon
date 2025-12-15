#include <iostream>
#include <cmath>

using namespace std;


int cal_next(int n) {
    if(n == 1)
        return 1;
    if (n % 2 == 0)
        return n / 2;
    else
        return (n + 1) / 2;
}

int main () {
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n, kim, lim, round = 0;
    cin >> n >> kim >> lim;

    while(n > 0) {
        round++;
        int gap = abs(kim / 2 - lim / 2);
        if (gap==1 && abs(kim - lim) == 1)
            break;
        kim = cal_next(kim);
        lim = cal_next(lim);
        n = cal_next(n);
    }
    cout << round << '\n';
    return 0;
}