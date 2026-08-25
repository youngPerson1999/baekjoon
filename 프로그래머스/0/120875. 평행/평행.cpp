#include <string>
#include <vector>
#include <numeric>

using namespace std;

bool cal_same_incl(vector<int> x1, vector<int> x2, vector<int> y1, vector<int> y2) {
    int dx1 = x2[0] - x1[0], dy1 = x2[1] - x1[1];
    int dx2 = y2[0] - y1[0], dy2 = y2[1] - y1[1];
    //부호 다르면 평행 불가
    if(dx1 * dy1 > dx2 * dy2) return false;
    int gcd1 = gcd(dx1, dy1), gcd2 = gcd(dx2, dy2);
    dx1 /= gcd1;
    dy1 /= gcd1;
    dx2 /= gcd2;
    dy2 /= gcd2;
    if(dy1 / dx1 == dy2 / dx2 && dy1 % dx1 == dy2 % dx2) return true;
    return false;
}

int solution(vector<vector<int>> dots) {
    int answer = 0;
    //12, 34 - 13, 24 - 14, 23
    if(cal_same_incl(dots[0], dots[1], dots[2], dots[3])) {
        answer = 1;
    }
    else if(cal_same_incl(dots[0], dots[2], dots[1], dots[3])) {
        answer = 1;
    }
    else if(cal_same_incl(dots[0], dots[3], dots[2], dots[1])) {
        answer = 1;
    }
    return answer;
}