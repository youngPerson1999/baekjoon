#include <string>
#include <vector>
#include <cmath>

using namespace std;

bool is_finish(string name, vector<bool>visited) {
    int l = name.length();
    for(int i = 0; i < l; i++) {
        if(visited[i] == false && name[i] != 'A') return false;
    }
    return true;
}

int solution(string name) {
    int answer = 0, l = name.length();
    vector<int> no_a;
    for(int i = 0; i < name.length(); i++) {
        if(name[i] != 'A') {
            if(name[i] > 'N' && name[i] <= 'Z') {
                answer += 'Z' - name[i] + 1;
            }
            else if(name[i] >= 'A' && name[i] <= 'N') {
                answer += name[i] - 'A';
            }
            no_a.push_back(i);
            
        }
    }
    if(l == 1 || answer == 0) return answer;
    //이동 최적화
    int min_d = 1000;
    for(int i = 0; i < no_a.size(); i++){
        //no_a[i]에서 꺾음(왼->오, 오->왼 거리 비교)
        //오른쪽 가다가 왼쪽 꺾기
        vector<bool> visited(name.length(), false);
        visited[0] = true;
        int d = 0;
        //오른쪽으로 이동하면서 전부 true및 거리 증가
        bool is_f = false;
        for(int j = 1; j <= no_a[i]; j++) {
            is_f = is_finish(name, visited);
            if(is_f) break;
            visited[j] = true;
            d++;
        }
        is_f = is_finish(name, visited);
        // 마지막 노드면 오른쪽으로 전부 간거라 굳이 더 안세봐도됨.
        if(is_f == false && no_a[i] != name.length() - 1) {
            for(int j = no_a[i] - 1; is_f == false; j--) {
                if(j < 0) j += l;
                visited[j] = true;
                d++;
                is_f = is_finish(name, visited);
            }
        }
        min_d = d < min_d ? d : min_d;        
    }
    //왼으로 가다가 오른쪽
    for(int i = 0; i < no_a.size(); i++){
        vector<bool> visited(name.length(), false);
        visited[0] = true;
        bool is_f = false;
        int d = 0;
        for(int j = l - 1; d < l - no_a[i]; j--) {
            if(j < 0) j += l;
            is_f = is_finish(name, visited);
            if(is_f) break;
            visited[j] = true;
            d++;
        }
        is_f = is_finish(name, visited);
        if(is_f == false && no_a[i] != 1) {
            for(int j = no_a[i] + 1; is_f == false; j++) {
                if(j >= l) j -= l;
                visited[j] = true;
                d++;
                is_f = is_finish(name, visited);
            }
        }
        min_d = d < min_d ? d : min_d;  
    }
    return answer + min_d;
}