#include <iostream>
#include <vector>

using namespace std;

int n;
vector<vector<int> > g;

void calSol(){
    //플로이드 워샬 알고리즘
    for (int k = 0; k < n; k++){
        //k -> 거쳐가는 노드
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j ++){
                //만약 i->k->j있으면 경로 존재
                if(g[i][k] + g[k][j] > 1)
                    g[i][j] = 1;
            }
        }
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++)
            cout << g[i][j] << " ";
        cout << "\n";
    }
}

int main(){

    cin >> n;

    for (int i = 0; i < n; i++){
        vector<int> row(n, 0);
        for (int j = 0; j < n; j++){
            cin >> row[j];
        }
        g.push_back(row);
    }
    calSol();
    return 0;
}