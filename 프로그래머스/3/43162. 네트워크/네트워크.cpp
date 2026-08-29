#include <string>
#include <vector>
#include <queue>

using namespace std;

int next_com(int n, vector<bool> visited) {
    for(int i = 0; i < n; i++)
    {
        if(!visited[i]) return i;
    }
    return -1;
}

void bfs(int n, vector<vector<int>> computers, vector<bool> &visited, int s) {
    queue<int> q;
    q.push(s);
    visited[s] = true;
    
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        for(int j = 0; j < n; j++) {
            if(computers[cur][j] == 1 && !visited[j]) {
                q.push(j);
                visited[j] = true;
            }
        }
    }
    
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    vector<bool> visited(computers.size(), false);
    int i = next_com(n, visited);
    while(i >= 0) {
        answer++;
        bfs(n, computers, visited, i);        
        i = next_com(n, visited);
    }
    return answer;
}