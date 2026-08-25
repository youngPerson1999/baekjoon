#include <string>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

bool compareLength(const string& a, const string& b) {
    if (a.length() == b.length()) {
        return a < b; // 길이가 같으면 사전 순서(알파벳 순)
    }
    return a.length() > b.length(); // 길이 순서
}

bool solution(vector<string> phone_book) {
    bool answer = true;
    sort(phone_book.begin(), phone_book.end(), compareLength);
    vector<unordered_set<string>> s(21);
    
    int pb = phone_book.size();
    
    for(int i = 0; i < pb; i++) {
        string cur_ph = phone_book[i];
        int cur_s = phone_book[i].length();
        if(s[cur_s].find(cur_ph) != s[cur_s].end()) {
            answer = false;
            break;
        }
        for(int j = 1; j <= cur_s; j++)
        {
            s[j].insert(cur_ph.substr(0, j));
        }
    }
    return answer;
}