#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;


int main() {
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    string str;
    cin >> str;
    int len = str.length();

    unordered_set<string> subs;

    for (int i = 0; i < len; i++) {
        for (int j = i; j < len; j++) {
            subs.insert(str.substr(i, j - i + 1));
        }
    }
    cout << subs.size() << '\n';
    return 0;
}