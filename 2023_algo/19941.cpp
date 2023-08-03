#include <iostream>
#include <vector>
#include <string>

using namespace std;

int n, k;
string table;

int calSol(){
    vector<int> greedy(n, 0);
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if(table[i]=='H')
            continue;
        int min = i - k >= 0 ? i - k : 0;
        int max = i + k < n - 1 ? i + k : n - 1;
        for (int j = min; j <= max; j++)
        {
            if (table[j] == 'H' && greedy[j] == 0)
            {
                count++;
                greedy[j] = 1;
                break;
            }
        }
    }
    return count;
}

int main(){
    cin >> n >> k;
    cin >> table;
    cout << calSol() << "\n";
    return 0;
}