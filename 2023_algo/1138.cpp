#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int main(){

    int n;

    cin >> n;

    vector<int> num(n);
    vector<int> order(n, 11);

    for (int i = 0; i < n; i++){
        int h;
        cin >> h;
        num[i] = h;
    }
    for (int i = 1; i <= n; i++){
        int cnt = 0;
        for (int j = 0; j < n; j++)
        {
            if(cnt >= num[i-1] && order[j] == 11){
                order[j] = i;
                break;
            }
            if(order[j] > i)
                cnt++;
        }
    }
    for (int i = 0; i < n; i++){
        cout << order[i]<<" ";
    }

        return 0;
}