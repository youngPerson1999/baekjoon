#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void program(){
    int m, mid;
    cin >> m;
    cout << m / 2 + 1 << "\n";
    vector<int> num(m / 2 + 1);
    //큰게 top
    priority_queue<int> minpq;
    //작은게 top
    priority_queue<int, vector<int>, greater<int> > maxpq;
    for (int i = 0; i < m; i++)
    {
        int tmp;
        cin >> tmp;
        if (i == 0)
            mid = tmp;
        else
        {
            if(mid > tmp)
                minpq.push(tmp);
            else
                maxpq.push(tmp);
        }
        if (i % 2 == 0)
        {
            if (maxpq.size() > minpq.size())
            {
                minpq.push(mid);
                mid = maxpq.top();
                maxpq.pop();
            }
            else if(minpq.size() > maxpq.size())
            {
                maxpq.push(mid);
                mid = minpq.top();
                minpq.pop();
            }
            num[i / 2] = mid;
        }
    }
    for (int i = 0; i < m / 2 + 1; i++)
    {
        if (i > 0 && i % 10 == 0)
            cout << "\n";
        cout << num[i] << " ";
    }
}

int main(){
    int t;
    cin >> t;
    for (int i = 0; i < t; i++){
        program();
        cout << "\n";
    }

    return 0;
}