#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solve(int n, vector<int> logs){
    vector<int> circle(n);
    for (int i = 0; i < n; i++)
    {
        int idx = i / 2;
        if (i % 2 == 1){
            idx = n - 1 - i / 2;
        }
        circle[idx] = logs[i];
    }
    int max = circle[n - 1] - circle[0];
    for (int i = 1; i < n;i++){
        int tmp = abs(circle[i] - circle[i - 1]);
        if (tmp > max)
            max = tmp;
    }
    return max;
}

int main(){
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    for (int i = 0; i < t;i++){
        int n;
        cin >> n;
        vector<int> logs(n);
        for (int j = 0; j < n;j++){
            cin >> logs[j];
        }
        sort(logs.begin(), logs.end());
        cout << solve(n, logs) << "\n";
    }
        return 0;
}