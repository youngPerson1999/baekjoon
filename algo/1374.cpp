#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<utility>
#include<queue>

using namespace std;
using lecture = pair<int, int>;

int main()
{
    int n,i;
    
    scanf("%d",&n);
    
    vector<lecture> lectures;
    priority_queue<lecture,vector<lecture>,greater<lecture> >pq;
    
    for(i=0;i<n;i++){
        int num,begin,end;
        scanf("%d %d %d",&num,&begin,&end);
        lectures.push_back(make_pair(begin,end));
        //num is just dummy value;
    }
    
    sort(lectures.begin(),lectures.end());
    
    int min_room = 0;
    
    for(i=0;i<n;i++){
        //printf("%d %d, ",lectures[i].first,lectures[i].second);
        if(pq.size()>0){
            if(lectures[i].first<pq.top().first){
                min_room++;
            }
            else{
                pq.pop();
            }
        }
        else{   //pq.size() = 0 -> first lecture
            min_room++;
        }
        lecture add;
        add.first = lectures[i].second;
        add.second = lectures[i].first;
        pq.push(add);
    }
    printf("%d",min_room);
    
    return 0;
}
