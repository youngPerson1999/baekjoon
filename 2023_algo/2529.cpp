#include <iostream>
#include <vector>

using namespace std;

int n;
vector<char> inequality;
vector<bool> num(10, false);
bool min_sol = false, max_sol = false;

void print_vector(vector<int> vec){
    for (int i = 0; i <= n; i++)
        cout << vec[i];
    cout << "\n";
}

bool check_inequal(int x, int y, char t){
    return t == '>' ? x > y : x < y;
}

void cal_min(int depth, vector<int> sol){
    if(min_sol)
        return;
    if (depth == n + 1)
    {
        print_vector(sol);
        min_sol = true;
    }
    for (int i = 0; i <= n;i++){
        if(num[i])
            continue;
        if(depth == 0 || check_inequal(sol[depth - 1], i, inequality[depth - 1])){
            num[i] = true;
            sol[depth] = i;
            cal_min(depth + 1, sol);
            num[i] = false;
        }
    }
}

void cal_max(int depth, vector<int> sol){
    if(max_sol)
        return;
    if (depth == n + 1)
    {
        print_vector(sol);
        max_sol = true;
    }
    for (int i = 9; i >= 0; i--)
    {
        if(num[i])
            continue;
        if(depth == 0 || check_inequal(sol[depth - 1], i, inequality[depth - 1])){
            num[i] = true;
            sol[depth] = i;
            cal_max(depth + 1, sol);
            num[i] = false;
        }
    }
}


int main(){

    cin >> n;

    inequality.resize(n);
    for (int i = 0; i < n; i++){
        cin >> inequality[i];
    }
    cal_max(0, vector<int>(10));
    cal_min(0, vector<int>(10));

    return 0;
}