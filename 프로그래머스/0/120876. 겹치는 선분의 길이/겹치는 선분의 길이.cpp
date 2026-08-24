#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> lines) {
    int answer = 0;
    vector<int> v(201, 0);
    int l = lines.size();
    for(int i = 0; i < l; i++) {
        for(int j = lines[i][0]; j < lines[i][1]; j++) {
            v[j + 100]++;
        }
    }
    for(int i = 0; i <= 200; i++)
        answer += v[i] > 1;
    return answer;
}