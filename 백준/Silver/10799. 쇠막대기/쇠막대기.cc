#include <iostream>
#include <stack>
#include <string>

using namespace std;

string str;
int len;

bool is_laser (int n) {
    return n < len && str[n] == '(' && str[n + 1] == ')';
}

int main() {
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int pieces = 0;

    getline(cin, str);

    len = str.length();
    stack<char> s;

    for (int i = 0; i < len; i++) {
        if(is_laser(i)) {
            pieces += s.size();
            i++;
            continue;
        }
        if(str[i] == '(') {
            s.push('(');
        }
        else {
            pieces++;
            s.pop();
        }
    }

    cout << pieces << '\n';

    return 0;
}