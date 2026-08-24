#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(int n, int t) {
    int answer = 0;
    answer = pow(2, t) * n;
    return answer;
}