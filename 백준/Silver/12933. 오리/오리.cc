#include <iostream>
#include <string>
#define duck "quack"

using namespace std;

bool is_valid_str (string str, int idx, int duck_idx) {
    if(str[idx] != duck[duck_idx])
        return false;
    return true;
}

int main() {
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    string str;
    int cnt = 0;

    cin >> str;
    if(str[0] != 'q') {
        cout << -1 << '\n';
        return 0;
    }
    while(true) {
        int duck_idx = 0;
        int len = str.length();
        for (int i = 0; i < len; i++) {
            if(is_valid_str(str, i, duck_idx)) {
                duck_idx++;
                str = str.substr(0, i) + str.substr(i + 1);
                i--;
                len--;
                if (duck_idx == 5)
                {
                    duck_idx = 0;
                }
            }
        }
        cnt++;
        if(str.length() % 5 != 0 || duck_idx != 0) {
            cout << -1 << '\n';
            return 0;
        }
        if(str.length() == 0) {
            cout << cnt << '\n';
            break;
        }
    }

    return 0;
}