#include <iostream>
#include <utility>
#include <queue>

using namespace std;

int n;
vector<int> num;
vector<vector<int> > list;

vector<int> copy_vector(vector<int>input){
    vector<int> tmp(input);
    return tmp;
}

void find_min(){
    for (int i = 2; i <= n; i++){
        num[i] = num[i - 1] + 1;
        list[i] = copy_vector(list[i - 1]);
        if (i % 2 == 0 && num[i / 2] + 1 < num[i])
        {
            num[i] = num[i / 2] + 1;
            list[i] = copy_vector(list[i / 2]);
        }
        if (i % 3 == 0 && num[i / 3] + 1 < num[i])
        {
            num[i] = num[i / 3] + 1;
            list[i] = copy_vector(list[i / 3]);
        }
        list[i].push_back(i);
    }
}

int main(){

    cin >> n;

    num.resize(n + 1);
    list.resize(n + 1, vector<int>(1, 1));
    num[1] = 0;
    find_min();
    int size = list[n].size();
    cout << num[n] << "\n";
    for (int i = size - 1; i >= 0; i--)
        cout << list[n][i] << " ";
    cout << "\n";
    return 0;
}