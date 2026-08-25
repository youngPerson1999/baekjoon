#include <vector>

using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    vector<bool> visited(200001, false);
    int n = nums.size();
    
    for(int i = 0; i < n; i++)
    {
        if(visited[nums[i]] == false) {
            visited[nums[i]] = true;
            answer++;
        }
    }
    if(answer > n / 2) answer = n / 2;
    return answer;
}