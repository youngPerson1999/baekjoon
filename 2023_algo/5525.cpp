#include <iostream>
#include <string>
#include <vector>

using namespace std;

int n, m;
string input;

int calSol(){
    int rst = 0, tmp = 0;
    vector<int> io;
    if(input[0]=='I')
        tmp++;
    for (int i = 1; i < m; i++)
    {
        if (tmp == 0 && input[i] == 'I')
        {
            tmp++;
            continue;
        }
        if ((input[i - 1] == 'O' && input[i] == 'I') || (input[i - 1] == 'I' && input[i] == 'O'))
            tmp++;
        else
        {
            if (tmp != 0 && tmp >= 2 * n + 1)
                io.push_back(tmp);
            if (input[i] == 'I')
                tmp = 1;
            else
            tmp = 0;
            // cout << i<<": " << tmp << ", ";
        }
    }
    if (tmp != 0 && tmp >= 2 * n + 1)
        io.push_back(tmp);
    // cout << "\n";
    int l = io.size();
    for (int i = 0; i < l; i++)
    {
        // cout << io[i] << " ";
        rst += (io[i] - 1) / 2 - n + 1;
    }
    return rst;
}

int main()
{

    cin >> n >> m;
    cin >> input;

    cout << calSol() << "\n";

    return 0;
}