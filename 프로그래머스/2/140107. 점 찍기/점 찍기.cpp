#include <string>
#include <vector>
#include <cmath>

using namespace std;

long long power(long long n) {
    return n*n;
}

long long solution(int k, int d) {
    long long answer = 0;
    long long power_d = power(d);
    long long n = d / k + 1;
    // answer += (n*(n+1))/2;
    for(long long x = 0; x <= d; x += k)
    {
        long long h = sqrt(power(d) - x*x) / k;
        answer += h + 1;
    }
    
    return answer;
}