#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> crane;
int* box;

int FindStarting(int c,int m){    //c is crane
    for(int i=0;i<m;i++){
        if(crane[c]>=box[i]&&box[i]>=0) return i;
    }
    return -1;
}


int main()
{
    int n,m,i,num;
    
    cin>>n;
    for(i=0;i<n;i++){
        cin>>num;
        crane.push_back(num);
    }
    
    cin>>m;
    box = new int[m];
    for(i=0;i<m;i++){
        cin>>box[i];
    }
    
    sort(crane.begin(),crane.end(),greater<int>());
    sort(box,box+m,greater<int>());
    
    if(crane.front()<box[0]){
        cout<<-1;
        return 0;
    }
    
    int box_num = 0;    //count the boxes
    int min_time = 0;
    int starting[n];
    while(box_num<m){
        for(i=0;i<n;i++){
            starting[i] = FindStarting(i,m);
            if(starting[i]==-1) break;
            box_num++;
            box[starting[i]]=-1;
        }
        min_time++;
    }
    cout<<min_time;
    
    return 0;
}
