#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main(){
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    stack<int> s;
    vector<int> v(n, -1);
    for (int i = 0; i < n; i++)
    {
        int cur;
        cin >> cur;
        int j = 1;
        //현재보다 스택 위가 작으면 해당 인덱스에 cur을 넣어줌(top이 클때까지)
        while (!s.empty() && s.top() < cur)
        {
            s.pop();
            //만약 이미 값이 들어갔다면 인덱스 찾아줘야함
            while(v[i-j] != -1)
                j++;
            v[i - j] = cur;
            j++;
        }
        s.push(cur);
    }
    for (int i = 0; i < n; i++)
    {
        cout << v[i] << " ";
    }
    cout << "\n";
    return 0;
}