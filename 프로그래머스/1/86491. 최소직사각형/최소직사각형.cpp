#include <string>
#include <vector>
#include <algorithm>

using namespace std;


int solution(vector<vector<int>> sizes) {
    int answer = 0, max_r = 0, max_h = 0;
    
    int s = sizes.size();
    for(int i = 0; i < s; i++)
    {
        if(sizes[i][0] < sizes[i][1]) {
            int tmp = sizes[i][0];
            sizes[i][0] = sizes[i][1];
            sizes[i][1] = tmp;
        }
        if(sizes[i][0] > max_r) max_r = sizes[i][0];
        if(sizes[i][1] > max_h) max_h = sizes[i][1];
    }
    answer = max_r * max_h;
    return answer;
}