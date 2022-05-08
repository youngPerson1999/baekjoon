#include <iostream>
#include <vector>
#include <utility>
#include <tuple>
#include <queue>

using namespace std;
int n,m;
vector<tuple<int,int,int> >n_3;
int combi[3];
void Combi_Wall(int nn, int k, int d, int next){
    if(d==k){
        n_3.push_back(make_tuple(combi[0],combi[1],combi[2]));
        return;
    }
    for(int i=next;i<nn;i++){
        combi[d] = i;
        Combi_Wall(nn,k,d+1,i+1);
    }
}
void Infect_Map(vector<int>map[], vector<pair<int,int> >v, int v_cnt){
    //bfs
    queue<pair<int,int> > q;
    for(int i=0;i<v_cnt;i++) q.push(v[i]);

    while(!q.empty()){
        pair<int,int> curr = q.front();
        q.pop();
        int x = curr.first; int y = curr.second;
        if(x>0&&map[x-1][y]==0){  //up
            map[x-1][y]=2;
            q.push(make_pair(x-1,y));
        }
        if(x<n-1&&map[x+1][y]==0){  //down
            map[x+1][y]=2;
            q.push(make_pair(x+1,y));
        }
        if(y>0&&map[x][y-1]==0){  //left
            map[x][y-1] = 2;
            q.push(make_pair(x,y-1));
        }
        if(y<m-1&&map[x][y+1]==0){  //right
            map[x][y+1] = 2;
            q.push(make_pair(x,y+1));
        }
    }
}
int Get_Safety_Zone(vector<int>map[]){
    int s_zone = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(map[i][j]==0) s_zone++;
        }
    }
    return s_zone;
}
void Copy_Map(vector<int>map[],vector<int>copy[]){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
            copy[i].push_back(map[i][j]);
    }
}
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);

    int w_cnt=0,v_cnt=0;

    cin>>n>>m;

    vector<int>map[n];
    vector<pair<int,int> >wall(n*m);
    vector<pair<int,int> >virous(10);

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++) {
            int x;
            cin>>x;
            map[i].push_back(x);
            if(map[i][j]==0) {
                wall[w_cnt] = make_pair(i,j);
                w_cnt++;
            }
            else if(map[i][j]==2){
                virous[v_cnt] = make_pair(i,j);
                v_cnt++;
            }
        }
    }
    Combi_Wall(w_cnt,3,0,0);
    int max_szone = 0;
    for(int i=0;i<n_3.size();i++){
        vector<int>tmap[n];
        Copy_Map(map,tmap);
        tmap[wall[get<0>(n_3[i])].first][wall[get<0>(n_3[i])].second] = 1;
        tmap[wall[get<1>(n_3[i])].first][wall[get<1>(n_3[i])].second] = 1;
        tmap[wall[get<2>(n_3[i])].first][wall[get<2>(n_3[i])].second] = 1;
        Infect_Map(tmap,virous,v_cnt);
        int s_cnt = Get_Safety_Zone(tmap);
        if(s_cnt>max_szone) max_szone = s_cnt;
    }
    cout<<max_szone;
    return 0;
}
