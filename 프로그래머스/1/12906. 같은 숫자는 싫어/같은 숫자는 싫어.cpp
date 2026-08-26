#include <vector>
#include <iostream>
#include <queue>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;

    queue<int> s;
    
    s.push(arr[0]);
    int l = arr.size();
    
    for(int i = 1; i < l; i++) {
        if(s.back() != arr[i]) s.push(arr[i]);
    }
    
    while(!s.empty()) {
        answer.push_back(s.front());
        s.pop();
    }

    return answer;
}