#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer, n(3, 0);
    int l = answers.size();
    for(int i = 0; i < l; i++) {
        if(answers[i] % 5 == (i + 1) % 5) n[0]++;
        if(i % 2 == 0) {if(answers[i] == 2) n[1]++;}
        else {
            if(i % 8 == 1 && answers[i] == 1) n[1]++;
            else if(i % 8 == 3 && answers[i] == 3) n[1]++;
            else if(i % 8 == 5 && answers[i] == 4) n[1]++;
            else if(i % 8 == 7 && answers[i] == 5) n[1]++;
        }
        if(i % 10 < 2) {
            if(answers[i] == 3) n[2]++;
        }
        else if (i % 10 < 4) {
            if(answers[i] == 1) n[2]++;
        }
        else if (i % 10 < 6) {
            if(answers[i] == 2) n[2]++;
        }
        else if (i % 10 < 8) {
            if(answers[i] == 4) n[2]++;
        }
        else {
            if(answers[i] == 5) n[2]++;
        }
    }
    
    int s = n[0];
    if(n[1] > s) s = n[1];
    if(n[2] > s) s = n[2];
    if(s == n[0]) answer.push_back(1);
    if(s == n[1]) answer.push_back(2);
    if(s == n[2]) answer.push_back(3);
    
    return answer;
}