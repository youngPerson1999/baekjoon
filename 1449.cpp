#include <iostream>
#include<vector>
#include<utility>
#include<algorithm>


using namespace std;


int main()
{
    int n, l;
    
    cin>>n>>l;
    
    vector<int> hole;
    
    for(int i=0;i<n;i++){
        int tmp;
        cin>>tmp;
        hole.push_back(tmp);
    }
    sort(hole.begin(),hole.end());
    
    int start = hole.at(0); //start at first hole
    int tapes = 1;          //the number of tapes
    for(int i=0;i<n;i++){
        if(hole.at(i)<start+l){
            continue;
        }
        start = hole.at(i);
        tapes++;
    }
    cout<<tapes;
    
    return 0;
}
