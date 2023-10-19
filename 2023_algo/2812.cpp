#include <iostream>
#include <string>

using namespace std;

int n, k;
string num, sol = "";
void solve(){
    int size = n - k;
    for (char digit : num)
    {
        while(k && !sol.empty() && sol.back() < digit){
            sol.pop_back();
            k--;
        }
        sol.push_back(digit);
    }
    sol.resize(size);
}
int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> k;
    cin >> num;
    solve();
    cout << sol << "\n";
    return 0;
}