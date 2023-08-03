#include <iostream>

using namespace std;

int n, m;
char A[50][50];
char B[50][50];

bool check_same()
{
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if(A[i][j] != B[i][j])
                return false;
        }
    }
    return true;
}

void reverse(int x, int y){
    for (int i = x; i < x + 3; i++)
    {
        for (int j = y; j < y + 3; j++){
            if(A[i][j] == '0')
                A[i][j] = '1';
            else if(A[i][j] == '1')
                A[i][j] = '0';
        }
    }

}

int cal_sol(){
    int count = 0;
    for (int i = 0; i <= n - 3; i++)
    {
        for (int j = 0; j <= m - 3; j++)
        {
            if(A[i][j] != B[i][j]){
                reverse(i, j);
                count++;
            }
            if (check_same()){
                return count;
            }
        }
    }
    if (check_same()){
        return count;
    }
    return -1;
}

int main(){

    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m;j++)
            cin >> A[i][j];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m;j++)
            cin >> B[i][j];
    }
    if(n < 3 || m < 3){
        if(check_same())
            cout << "0\n";
        else
            cout << "-1\n";
    }
    else
        cout << cal_sol() << "\n";
    return 0;
}