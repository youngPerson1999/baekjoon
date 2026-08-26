#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int sol(vector<int> array, vector<int> command) {
    vector<int> a(array.begin() + command[0] - 1, array.end() - array.size() + command[1]);
    sort(a.begin(), a.end());
    return a[command[2] - 1];
}

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    for(int i = 0; i < commands.size(); i++) {
        answer.push_back(sol(array, commands[i]));
    }
    return answer;
}