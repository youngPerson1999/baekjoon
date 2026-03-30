#include <iostream>
#include <regex>
#include <string>

using namespace std;

int main() {
    int t;
    cin >> t;
    string s;
    regex r("(100+1+|01)+");
    for (int i = 0; i < t; i++)
    {
        cin >> s;
        if(regex_match(s, r)) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }
}