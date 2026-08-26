#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>

using namespace std;

int cal_digit(int n) {
    int ans = 0;
    while(n > 0) {
        ans++;
        n /= 10;
    }
    return ans;
}

bool compare (int a, int b) {
    if(a == 0) return false;
    if(b == 0) return true;
    
    int d_a = cal_digit(a), d_b = cal_digit(b);
    
    int big_a = pow(10, d_b) * a + b;
    int big_b = pow(10, d_a) * b + a;
    return big_a > big_b;
    
}

string solution(vector<int> numbers) {
    string answer = "";
    sort(numbers.begin(), numbers.end(), compare);
    
    int n = numbers.size();
    for(int i = 0; i < n; i++) {
        answer.append(to_string(numbers[i]));
    }
    if(answer == string(answer.length(), '0'))
        return "0";
    return answer;
}