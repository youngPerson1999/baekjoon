#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
vector<char>pw;
bool check_pw(vector<char>combi){
    int vowel = 0,conso=0;
    for(int k=0;k<combi.size();k++){
        if(combi[k]=='a'||combi[k]=='e'||combi[k]=='i'||combi[k]=='o'||combi[k]=='u')
            vowel++;
        else conso++;
        if(vowel>0&&conso>1) return false;
    }
    return true;
}
void combination(vector<char>combi,int l,int index, int depth){
    if(l==0){
        if(check_pw(combi)) return;
        for(int i=0;i<combi.size();i++) cout<<combi[i];
        cout<<"\n";
    }
    else if(depth==pw.size()) return;
    else{
        //pw[depth] 뽑은 case
        combi[index] =  pw[depth];
        //뽑을 alphabet l-1, next combi index -> index+1, pw[depth]뽑았으니 다음으로
        combination(combi,l-1,index+1,depth+1);
        //pw[depth] 안뽑은 case
        combination(combi,l,index,depth+1);
    }
}
int main(){
    
    int l,c,k;
    cin>>l>>c;
    
    for(k=0;k<c;k++){
        char t;
        cin>>t;
        pw.push_back(t);
    }
    sort(pw.begin(),pw.end());
    vector<char>combi(l);
    combination(combi,l,0,0);
    
    return 0;
}
