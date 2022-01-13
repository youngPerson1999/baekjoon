#include <iostream>
#include<map>
#include<string>

using namespace std;

int main()
{
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);
    
    int n;
    string name;
    cin>>n;
    
    multimap<string,int>mara;
    for(int i=0;i<n;i++){
        cin>>name;
        mara.insert(make_pair(name,mara.count(name)));
    }
    for(int i=0;i<n-1;i++){
        cin>>name;
        mara.erase(mara.find(name));
    }
    cout<<mara.begin()->first;
    
    return 0;
}
