#include <string>
#include <vector>
#include <numeric>

using namespace std;

vector<int> solution(int numer1, int denom1, int numer2, int denom2) {
    vector<int> answer;
    int gcd_denom = gcd(denom1, denom2);
    int big_denom = denom1 * denom2 / gcd_denom;
    int new_nu = (numer1 * denom2 + numer2 * denom1)/ gcd_denom;
    
    int last_denom = gcd(new_nu, big_denom);
    
    answer.push_back(new_nu / last_denom);
    answer.push_back(big_denom / last_denom);
    return answer;
}