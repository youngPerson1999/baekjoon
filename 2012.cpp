#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int main(){
    
    int n;
    
    cin>>n;
    
    vector <int> grade;
    
    for(int i=0;i<n;i++){
        int tmp;
        cin>>tmp;
        grade.push_back(tmp);
    }
    
    sort(grade.begin(),grade.end());
    
    long long min=0;
    
    for(int i=1;i<=n;i++)
        min += abs(grade[i-1]-i);
    
    cout<<min;
    
    return 0;
}
