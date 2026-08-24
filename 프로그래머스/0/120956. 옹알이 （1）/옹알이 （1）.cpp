#include <string>
#include <vector>

using namespace std;

bool is_bab(string babb) {
    if(babb.length() == 0) return true;
    
    string maye = babb.substr(0, 2);
    string ayawoo = babb.substr(0, 3);
    
    if(maye.compare("ma") == 0 || maye.compare("ye") == 0) {
        return is_bab(babb.substr(2));
    }
    else if(ayawoo.compare("aya") == 0 || ayawoo.compare("woo") == 0) {
        return is_bab(babb.substr(3));
    }
    return false;
}

int solution(vector<string> babbling) {
    int answer = 0;
    for(int i = 0; i < babbling.size(); i++){
        answer += is_bab(babbling[i]) == true ? 1 : 0;
    }
    return answer;
}