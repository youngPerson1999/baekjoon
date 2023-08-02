#include <iostream>
#include <string>
#include <vector>

using namespace std;

int s, p, acgt[4];
string input;

bool check(vector<int> cnt){
    for (int i = 0; i < 4;i++){
        if (cnt[i] < acgt[i])
            return false;
    }
    return true;
}

int calSol(){
    int cnt = s - p + 1, l = input.length();
    int rst = 0;
    vector<vector<int> > ps_cnt(cnt, vector<int>(4, 0));
    for (int i = 0; i < p; i++)
    {
        if (input[i] == 'A')
            ps_cnt[0][0]++;
        else if (input[i] == 'C')
            ps_cnt[0][1]++;
        else if (input[i] == 'G')
            ps_cnt[0][2]++;
        else if (input[i] == 'T')
            ps_cnt[0][3]++;
    }
    if(check(ps_cnt[0]))
        rst++;
    for (int i = p; i < s; i++)
    {
        for (int j = 0; j < 4; j++){
            ps_cnt[i - p + 1][j] = ps_cnt[i - p][j];
        }
        if (input[i - p] == 'A')
            ps_cnt[i - p + 1][0]--;
        else if (input[i - p] == 'C')
            ps_cnt[i - p + 1][1]--;
        else if (input[i - p] == 'G')
            ps_cnt[i - p + 1][2]--;
        else if (input[i - p] == 'T')
            ps_cnt[i - p + 1][3]--;

        if (input[i] == 'A')
            ps_cnt[i - p + 1][0]++;
        else if (input[i] == 'C')
            ps_cnt[i - p + 1][1]++;
        else if (input[i] == 'G')
            ps_cnt[i - p + 1][2]++;
        else if (input[i] == 'T')
            ps_cnt[i - p + 1][3]++;
        if (check(ps_cnt[i - p + 1]))
            rst++;
    }
    return rst;
}

int main(){
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> s >> p >> input;
    for (int i = 0; i < 4; i++)
        cin >> acgt[i];
    cout << calSol() << "\n";

    return 0;
}