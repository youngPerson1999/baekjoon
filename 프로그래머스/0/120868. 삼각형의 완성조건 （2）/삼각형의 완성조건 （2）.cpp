#include <string>
#include <vector>

using namespace std;

int solution(vector<int> sides) {
    int answer = 0;
    int a = sides[0], b = sides[1];
    for(int i = 1; i < a + b; i++) {
        if((a + b > i) && (a + i > b) && (b + i > a)) answer++;
    }
    return answer;
}