#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int n;
vector<string> words;

bool cmp(string a, string b)
{
    return a.length() < b.length();
}

int solve(){
    vector<string> subset;
    for (int i = 0; i < n; i++)
    {
        string curr = words[i];
        int cur_leng = curr.length();
        bool isSub = false;
        for (int j = i + 1; j < n; j++)
        {
            string tmp = words[j];
            tmp = tmp.substr(0,cur_leng);
            
            // 0이면 접두사임
            isSub = tmp.compare(curr) == 0;
            if(isSub)
                break;
        }
        if(!isSub)
            subset.push_back(curr);
    }
    return subset.size();
}

int main(){
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    words.resize(n);
    for (int i = 0; i < n; i++){
        cin >> words[i];
    }
    sort(words.begin(), words.end(), cmp);
    cout << solve() << "\n";
    return 0;
}