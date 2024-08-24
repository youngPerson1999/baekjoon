#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>

using namespace std;

int main()
{   
    int N;
    
    cin>>N;
    
    vector<pair<int,int> > meeting;
    
    for(int i=0;i<N;i++){
        int begin, end;
        cin>>begin>>end;
        meeting.push_back(make_pair(end,begin));
    }
    sort(meeting.begin(),meeting.end());
    
    int max = 0; int fast_end = 0;
    for(int i=0;i<meeting.size();i++){
        int tmp_begin = meeting[i].second;
        int tmp_end = meeting[i].first;
        if(tmp_begin>=fast_end){
            max++;
            fast_end = tmp_end;
        }
    }
    
    cout<<max;
  
    return 0;
}
