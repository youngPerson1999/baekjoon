#include <string>
#include <vector>
#define MAX 1000000

using namespace std;

int solution(int x, int y, int n) {
    int answer = 0;
    vector<int> dp(y+1, MAX);
    dp[x] = 0;
    for(int i = x+1; i <= y; i++)
    {
        int num_n = MAX, num_two = MAX, num_three = MAX;
        if(i - n >= x) num_n = dp[i-n];
        if(i % 2 == 0 && i / 2 >= x) num_two = dp[i/2];
        if(i % 3 == 0 && i / 3  >= x) num_three = dp[i/3];
        int cur = num_n < num_two ? num_n : num_two;
        cur = cur < num_three ? cur : num_three;
        if(cur < MAX) dp[i] = cur + 1;
    }
    answer = dp[y] >= MAX ? -1 : dp[y];
    
    return answer;
}