#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int r, c;
vector<pair<int, int> > islands;
bool globalWarming(char **map, int x, int y){
    int cnt = 0;
    if (x == 0 && y == 0)
    { // 왼쪽위
        if (r == 1 || c == 1)
            return true;
        if (map[x + 1][y] == '.' || map[x][y + 1] == '.')
            return true;
    }
    else if(x==0&&y==c-1){  //오른쪽위
        if (r == 1 || c == 1)
            return true;
        if (map[x + 1][y] == '.' || map[x][y - 1] == '.')
            return true;
    }
    else if(x==r-1&&y==0){  //왼쪽 아래
        if(map[x-1][y]=='.'|| map[x][y+1]=='.')
            return true;
    }
    else if(x==r-1&&y==c-1){    //오른쪽 아래
        if(map[x-1][y]=='.'|| map[x][y-1]=='.')
            return true;
    }

    else if(x==0){          //맨윗줄
        cnt = 1;
        if (r==1)
            cnt++;
        else if (r > 1 && map[x + 1][y] == '.')
            cnt++;
        if(map[x][y + 1] == '.')
            cnt++;
        if(map[x][y - 1] == '.')
            cnt++;
    }
    else if(x==r-1){        //맨 아랫줄
        cnt = 1;
        if (map[x - 1][y] == '.')
            cnt++; 
        if(map[x][y + 1] == '.')
            cnt++;
        if(map[x][y - 1] == '.')
            cnt++;
    }
    else if(y==0){      //맨 왼쪽 줄
        cnt = 1;
        if (c==1)
            cnt++;
        else if (c > 1 && map[x - 1][y] == '.')
            cnt++;
        if(map[x + 1][y] == '.')
            cnt++;
        if(map[x][y + 1] == '.')
            cnt++;
    }
    else if(y==c-1){    //맨 오르쪽줄
        cnt = 1;
        if (map[x - 1][y] == '.')
            cnt++;
        if(map[x + 1][y] == '.')
            cnt++;
        if(map[x][y - 1] == '.')
            cnt++;
    }
    else{
        if(map[x-1][y]=='.')
            cnt++;
        if(map[x+1][y]=='.')
            cnt++;
        if(map[x][y-1]=='.')
            cnt++;
        if(map[x][y+1]=='.')
            cnt++;
    }
    if(cnt >= 3)
        return true;
    return false;
}

bool check_row(char *row, int l){
    for (int i = 0; i < l; i++)
        if (row[i]=='X')
            return false;
    return true;
}

bool check_column(char **map, int l, int t){
    for (int i = 0; i < l;i++)
        if(map[i][t]=='X')
            return false;
    return true;
}

void print_map(char **map){
    int min_x = 0, min_y = 0;
    // 윗줄
    for (int i = 0; i < r; i++){
        if(check_row(map[i], c))
            min_x++;
        else
            break;
    }
    //아랫줄
    for (int i = r - 1; i >= 0; i--){
        if(check_row(map[i], c))
            r--;
        else
            break;
    }
    //왼쪽줄
    for (int i = 0; i < c; i++){
        if(check_column(map, r, i))
            min_y++;
        else
            break;
    }
    //오른쪽줄
    for (int i = c - 1; i >= 0; i--){
        if(check_column(map, r, i))
            c--;
        else
            break;
    }
    for (int i = min_x; i < r; i++){
        for (int j = min_y; j < c;j++)
            cout << map[i][j];
        cout<<"\n";
    }
}

int main(){    

    cin >> r >> c;

    char **map = new char*[r], **new_map = new char*[r];

    for (int i = 0; i < r; i++){
        map[i] = new char[c];
        new_map[i] = new char[c];
        for (int j = 0; j < c; j++)
        {
            cin >> map[i][j];
            new_map[i][j] = map[i][j];
            if (map[i][j] == 'X')
                islands.push_back(make_pair(i, j));
        }
    }

    int num = islands.size();
    for (int i = 0; i < num; i++){
        int x = islands[i].first, y = islands[i].second;
        if (globalWarming(map, x, y))
            new_map[x][y] = '.';
    }
    
    print_map(new_map);

    return 0;
}