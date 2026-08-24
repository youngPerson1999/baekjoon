#include <string>
#include <vector>

using namespace std;

string solution(string my_string) {
    string answer = "";
    
    int len_s = my_string.length();
    for(int i = 0; i < len_s; i++) {
        char c = my_string[i];
        if(c >= 'a' && c <= 'z')
        {
            answer.append(1, c + 'A' - 'a');
        }
        else
        {
            answer.append(1, c + 'a' - 'A');
        }
    }
    return answer;
}