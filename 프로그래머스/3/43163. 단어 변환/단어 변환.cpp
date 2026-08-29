#include <string>
#include <vector>

using namespace std;

bool is_changable(string in, string out) {
    int l = in.length(), cnt = 0;
    for(int i = 0; i < l; i++) {
        if(in[i] != out[i]) cnt++;
    }
    return cnt <= 1;
}

// d depth
void dfs(string b, string t, vector<string> w, vector<bool> visited, int &a, int dist) {
    if(b == t) {
        if(a < 0) {a = dist;}
        else {
            a = dist < a ? dist : a;
        }
        return;
    }
    for(int i = 0; i < w.size(); i++) {
        if(!visited[i] && is_changable(b, w[i])) {
            visited[i] = true;
            dfs(w[i], t, w, visited, a, dist + 1);
        }
    }
    return;
}

int solution(string begin, string target, vector<string> words) {
    int answer = -1;
    vector<bool> visited(words.size(), false);
    dfs(begin, target, words, visited, answer, 0);
    if(answer < 0) answer = 0;
    return answer;
}