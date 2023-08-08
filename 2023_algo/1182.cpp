#include <iostream>
#include <vector>

using namespace std;

int n, s, cnt = 0;
vector<int> num;
vector<bool> visited;

void cal_count(int depth, int idx){

    if(idx == n){
        int sum = 0;
        bool all_false = true;
        for (int i = 0; i < n; i++)
        {
            if(visited[i]){
                sum += num[i];
                all_false = false;
            }
        }
        if(sum==s && !all_false)
            cnt++;
        return;
    }
    else if(depth < n){
        visited[idx] = true;
        cal_count(depth + 1, idx + 1);
        visited[idx] = false;
        cal_count(depth, idx + 1);
    }
}

int main(){

    cin >> n >> s;
    num.resize(n);
    visited.resize(n, false);
    for (int i = 0; i < n; i++)
    {
        cin >> num[i];
    }
    cal_count(0, 0);
    cout << cnt << "\n";
    return 0;
}