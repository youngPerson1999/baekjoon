#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer(2);
    int sum = 0, len = sequence.size(), j=0;
    answer[0] = 0;
    answer[1] = len - 1;
    for(int i = 0; i < len; i++)
    {
        sum += sequence[i];
        if(sum > k)
        {
            while(sum > k)
            {
                sum -= sequence[j];
                j++;
            }
        }
        if(sum == k)
        {
            if(answer[1] - answer[0] > i - j){
                answer[0] = j;
                answer[1] = i;
            }
        }
        
    }
    return answer;
}