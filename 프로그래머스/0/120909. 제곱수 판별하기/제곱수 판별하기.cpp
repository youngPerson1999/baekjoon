#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(int n) {
    int answer = 0;
    int r = sqrt(n);
    answer = r * r == n ? 1 : 2;
    return answer;
}