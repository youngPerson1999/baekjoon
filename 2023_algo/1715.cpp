#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n;
int main(){
    cin >> n;
    priority_queue<int, vector<int>, greater<int> > pq;
    for (int i = 0; i < n; i++){
        int tmp;
        cin >> tmp;
        pq.push(tmp);
    }
    int sol = 0;
    if (n == 1)
    {
        cout<<0<<"\n";
        return 0;
    }
    while (!pq.empty()){
        int a = pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();
        sol += a + b;
        if (pq.empty())
            break;
        pq.push(a + b);
    }
    cout << sol << "\n";
    return 0;
}