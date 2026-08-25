#include <string>
#include <vector>
#include<unordered_set>
#include <algorithm>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    int c_s = completion.size();
    
    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());
    
    for(int i = 0; i < c_s; i++) {
        if(participant[i] != completion[i])
        {
            answer = participant[i];
            break;
        }
    }
    if(answer.length() == 0) answer = participant[c_s];
    return answer;
}