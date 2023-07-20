#include <iostream>
#include <string>
#include <vector>

using namespace std;

string code;
int l;

vector<int> calSol(){
    vector<int> sol(l, 0);
    if(code[0] != '0')
        sol[0] = 1;
    
    for (int i = 1; i < l; i++){
        //2개
        string subStr = code.substr(i - 1, 2);
        int two = stoi(subStr);
        int one = code[i] - '0';
        if(one > 0){
            sol[i] += sol[i - 1];
        }
        if(two > 9 && two < 27 && i > 1){
            sol[i] += sol[i - 2];
        }
        if(i == 1 && two > 9 && two < 27)
            sol[i]++;
        sol[i] %= 1000000;
    }
    return sol;
}

int main(){

    cin >> code;

    l = code.length();
    vector<int> sol = calSol();

    cout << sol[l - 1] << "\n";
    return 0;
}