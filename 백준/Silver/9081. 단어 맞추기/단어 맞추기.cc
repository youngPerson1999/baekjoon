#include <iostream>
#include <string>
#include <algorithm>

using namespace std;


string next_word(string s) {

    int len = s.length();
    int idx = 0;
    for (int i = len - 1; i > 0; i--)
    {
        if(s[i] > s[i - 1]){
            idx = i;
            break;
        }
    }
    char next = s[idx];
    int next_idx = idx;
    if (idx == 0)
        return s;
    for (int i = idx; i < len; i++)
    {
        if(s[i] > s[idx - 1] && s[i] < next){
            next = s[i];
            next_idx = i;
        }
    }
    s[next_idx] = s[idx - 1];
    s[idx - 1] = next;
    sort(s.begin() + idx, s.end());

    return s;
}

int main() {

    int t;
    string words[100];

    cin >> t;

    for (int i = 0; i < t; i++){
        cin >> words[i];
    }
    for (int i = 0; i < t; i++)
        cout << next_word(words[i]) << '\n';
    
    return 0;
}