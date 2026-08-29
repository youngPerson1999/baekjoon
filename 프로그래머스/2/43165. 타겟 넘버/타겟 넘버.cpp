#include <string>
#include <vector>

using namespace std;

void dfs(vector<int> cals, vector<int> numbers, int target, int depth, int idx, int &answer)
{
    if(depth == numbers.size() || idx == numbers.size())
    {
        int rst = 0;
        for(int i = 0; i < numbers.size(); i++){
            rst += cals[i] * numbers[i];
        }
        if(rst == target) answer++;
        return;
    }
    dfs(cals, numbers, target, depth + 1, idx + 1, answer);
    cals[idx] = -1;
    dfs(cals, numbers, target, depth + 1, idx + 1, answer);
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    vector<int> cals(numbers.size(), 1);
    dfs(cals, numbers, target, 0, 0, answer);
    return answer;
}