#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;
int a, b;
vector<int>palin;
bool find_palin(string str)
{
    int l = str.length();
    for (int i = 0; i < l / 2; i++)
    {
        if (str[i] != str[l - i - 1])
            return false;
    }
    return true;
}


bool is_prime(int n){
    int rt = sqrt(n);
    for (int i = 2; i <= rt; i++)
        if (n % i == 0)
            return false;
    return true;
}

int main()
{
    cin >> a >> b;
    for (int i = a; i <= b; i++)
    {
        //짝수는 미리 전부 걸러서 실행시간 줄이기
        if (i % 2 == 1 && find_palin(to_string(i)) && is_prime(i))
            cout << i << "\n";
    }
    cout << "-1\n";
    return 0;
}