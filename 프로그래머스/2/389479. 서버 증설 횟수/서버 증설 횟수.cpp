#include <string>
#include <vector>
#include <deque>

using namespace std;

int solution(vector<int> players, int m, int k) {
    int answer = 0;
    //시간
    deque<int> dq;
    for(int i = 0; i < 24; i++) {
        //오래된것부터 빠짐
        while(!dq.empty() && i - dq.front() >= k) dq.pop_front();
        while(players[i] >= (dq.size() + 1) * m) {
            dq.push_back(i);
            answer++;
        }
    }
    return answer;
}