#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer(1, 0);
    stack<int> s;
    for(int i = 0; i < speeds.size(); i++)
    {
        int pr = progresses[i], sp = speeds[i];
        int d = (100 - pr) % sp > 0 ? (100 - pr) / sp + 1: (100 - pr) / sp;
        if(s.empty()) {
            s.push(d);
            answer[answer.size() - 1]++;
        }
        else {
            if(s.top() >= d) answer[answer.size() - 1]++;
            else {
                s.pop();
                answer.push_back(1);
                s.push(d);
            }
        }
    }
    //5 10 1 1 20 1
    return answer;
}