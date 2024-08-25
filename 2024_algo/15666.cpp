#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<int> v;
vector<int> num;

void back_tracking(int idx, int depth, vector<int> arr)
{
    //if last value == 0 then i don't think it is proper result
    if(depth == m && arr[depth - 1] > 0)
    {
        for (int i = 0; i < m; i++)
            cout << arr[i]<<' ';
        cout << '\n';
    }
    else
    {
        if (idx < n && arr[depth - 1] <= num[idx])
        {
            //add current value again
            arr[depth] = num[idx];
            back_tracking(idx, depth + 1, arr);
            //jump to next index not including current value
            arr[depth] = num[idx + 1];
            back_tracking(idx + 1, depth, arr);
        }
        else
            return;
    }
}

void print_array()
{
    for (int i = 0; i < n; i++)
    {
        vector<int> arr(m, 0);
        arr[0] = num[i];
        back_tracking(i, 1, arr);
    }
}

int main(){
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    v.resize(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    //sort by asc ex: 1 2 3 4 5
    sort(v.begin(), v.end());
    //remove duplicate values
    for (int i = 0; i < n;i++)
    {
        if (i > 0 && v[i - 1] == v[i])
            continue;
        num.push_back(v[i]);
    }
    n = num.size();
    print_array();

    return 0;
}