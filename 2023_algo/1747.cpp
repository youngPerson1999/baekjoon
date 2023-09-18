#include <iostream>
#include <string>
#include <cmath>
#define MAX 100000000
using namespace std;

bool find_palin(string str){
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
int return_prime(int n){

    if (n == 1)
        return 2;
    for (int i = n; i < MAX; i++)
    {
        string str = to_string(i);
        if (!find_palin(str))
            continue;
        if(is_prime(i))
            return i;
    }
    return -1;
}
int main(){    
    int n;
    cin >> n;
    cout << return_prime(n) << "\n";
    return 0;
}