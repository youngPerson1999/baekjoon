#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    sort(lost.begin(), lost.end());
    sort(reserve.begin(), reserve.end());
    vector<int> cloths(n + 1, 1);
    for(int i = 0; i < lost.size(); i++)
    {
        cloths[lost[i]]--;
    }
    for(int i = 0; i < reserve.size(); i++)
    {
        cloths[reserve[i]]++;
    }  
    for(int i = 1; i <= n; i++) {
        if(cloths[i] == 0) {    
            if(cloths[i - 1] == 2) {
                cloths[i - 1]--;
                cloths[i]++;
            }
            else if(i < n && cloths[i + 1] == 2) {
                cloths[i + 1]--;
                cloths[i]++;
            }
        }
        if(cloths[i] > 0) answer++;
    }

    return answer;
}