#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

int n;
vector<vector<int> > area;

vector<vector<bool> >fill_rain_area(int rain){
    vector<vector<bool> > safe(n, vector<bool>(n, true));
    for (int i = 0; i < n;i++){
        for (int j = 0; j < n; j++){
            if(area[i][j] <= rain)
                safe[i][j] = false;
        }
    }
    return safe;
}

vector<vector<bool> >find_safe_area(int x, int y, vector<vector<bool> > safe){
    queue<pair<int, int> > q;
    q.push(make_pair(x, y));
    while(!q.empty()){
        pair<int, int> curr = q.front();
        int i = curr.first, j = curr.second;
        q.pop();
        // up
        if (i > 0 && safe[i - 1][j]){
            q.push(make_pair(i - 1, j));
            safe[i - 1][j] = false;
        }
        // down
        if (i < n - 1 && safe[i + 1][j]){
            q.push(make_pair(i + 1, j));
            safe[i + 1][j] = false;
        }
        //left
        if (j > 0 && safe[i][j - 1]){
            q.push(make_pair(i, j - 1));
            safe[i][j - 1] = false;
        }
        // right
        if (j < n - 1 && safe[i][j + 1]){
            q.push(make_pair(i, j + 1));
            safe[i][j + 1] = false;
        }
    }
    return safe;
}

int cal_safe_area(int rain){
    vector<vector<bool> > safe = fill_rain_area(rain);
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++){
            if(safe[i][j]){
                safe = find_safe_area(i, j, safe);
                cnt++;
            }
        }
    }
    // cout<<"cnt = " << cnt << "\n";
    return cnt;
}

int main(){
    cin >> n;

    area.resize(n, vector<int>(n));
    int max = 0, safe_area = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++){
            cin >> area[i][j];
            if(area[i][j] > max)
                max = area[i][j];
        }
    }
    
    for (int i = 0; i <= max; i++){
        int t_safe = cal_safe_area(i);
        if(t_safe > safe_area)
            safe_area = t_safe;
    }
    cout << safe_area << "\n";
    return 0;
}