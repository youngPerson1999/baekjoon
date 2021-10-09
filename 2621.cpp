#include<iostream>
#include<vector>
#include<string>
#include<utility>
#include<algorithm>

using namespace std;

int main(){
    
    vector<pair<int,int> >cards;
    vector<pair<int,int> >r_cards;
    
    for(int i=0;i<5;i++){
        char a; int b;
        cin>>a>>b;
        int color;
        if(a=='B') color = 0;
        else if(a=='G') color = 1;
        else if(a=='R') color = 2;
        else color = 3;
        cards.push_back(make_pair(color,b));
        r_cards.push_back(make_pair(b,color));
    }
    
    stable_sort(cards.begin(),cards.end());
    stable_sort(r_cards.begin(),r_cards.end());
    int same_num[5] = {1, };
    int j=0;
    for(int i=1;i<5;i++){
        if(r_cards[i].first==r_cards[i-1].first) same_num[j]++;
        else {
            j++;
            if(i==4) break;
            same_num[j]++;
        }
    }
    //for(int i=0;i<5;i++) cout<<same_num[i]<<" ";
    //B->G->R->Y
    //for(int i=0;i<5;i++) cout<<cards[i].first<<cards[i].second<<"\n";
    //[0] = B, [1] = G, [2] = R, [3] = Y
    int score = 0;
    if(cards[0].first==cards[4].first&&cards[0].second==cards[4].second-4)
        score = 900+cards[4].second;
    else if(r_cards[0].first==r_cards[3].first||r_cards[1].first==r_cards[4].first)
        score = 800 + r_cards[1].first;
    else if(r_cards[0].first==r_cards[2].first&&r_cards[3].first==r_cards[4].first)
        score = 700 + r_cards[0].first*10 + r_cards[4].first;
    else if(r_cards[0].first==r_cards[1].first&&r_cards[2].first==r_cards[4].first)
        score = 700 + r_cards[4].first*10 + r_cards[0].first;
    else if(cards[0].first==cards[4].first)
        score = 600 + r_cards[4].first;
    else if(r_cards[0].first==r_cards[4].first-4)
        score = 500 + r_cards[4].first;
    else{
        int i=0;
        int doublec = 0;
        while(same_num[i]!=0){
            if(same_num[i]==3){ //6.
                score = 400 + r_cards[2+i].first;
                break;
            }
            if(same_num[i]==2){
                if(doublec==0){ //8.
                    score = 200 + r_cards[i].first;
                    doublec = r_cards[i].first;
                }
                else{   //7.
                    score = 300 + doublec + r_cards[i+1].first*10;
                }
            }
            i++;
        }
        if(score==0) score = 100 + r_cards[4].first;
    }
    cout<<score;
    
    return 0;
}
