#include <iostream>
#include <queue>
#include <vector>
#include <utility>

using namespace std;

int main()
{
    int n, rst = 0;
    priority_queue<pair<int, int> >pq;
    cin>>n;
    for(int i = 0; i < n; i++)
    {
        pair<int, int> homework;
		//점수순으로 정렬
        cin>>homework.second>>homework.first;
        pq.push(homework);
    }
    vector<int>score(1001, 0);
    while(!pq.empty())
    {
        pair<int, int> cur = pq.top();
        pq.pop();
		//비어있으면 바로 넣어줌
        if(score[cur.second] == 0)
            score[cur.second] = cur.first;
        else
        {
            int j = cur.second;
			//넣을 수 있는 인덱스 찾기
            while(j > 0){
                if(score[j] >= cur.first)
                    j--;
                else
                    break;
            }
            score[j] = cur.first;
        }
    }
    for(int i = 1; i<=1000;i++){
        rst += score[i];
    }
    cout<<rst<<"\n";
    return 0;
}
