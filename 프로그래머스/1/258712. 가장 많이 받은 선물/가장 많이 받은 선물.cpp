#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>

using namespace std;

int solution(vector<string> friends, vector<string> gifts) {
    int answer = 0;
    unordered_map<string, int> um;
    int num_of_friends = friends.size();
    for(int i = 0; i < num_of_friends; i++)
    {
        um.insert(make_pair(friends[i], i));
    }
    int num_of_gifts = gifts.size();
    vector<vector<int> >v(num_of_friends, vector<int>(num_of_friends, 0));
    for(int i = 0; i < num_of_gifts; i++)
    {
        stringstream ss(gifts[i]);
        string s;
        ss >> s;
        int giver = um[s];
        ss >> s;
        int receiver = um[s];
        v[giver][receiver]++;
    }
    vector<int>gift_index(num_of_friends, 0);
    for(int g = 0; g < num_of_friends; g++)
    {
        int give = 0;
        for(int r = 0; r < num_of_friends; r++)
        {
            if(g == r) continue;
            give += v[g][r];
            give -= v[r][g];
        }
        gift_index[g] = give;
        
    }
    vector<int> num_gifts(num_of_friends, 0);
    for(int g = 0; g < num_of_friends; g++)
    {
        for(int r = g; r < num_of_friends; r++)
        {
            if(g==r) continue;
            int num_g = v[g][r];
            int num_r = v[r][g]; 
            if( num_g == num_r)
            {
                if(gift_index[g] > gift_index[r]) num_gifts[g]++;
                else if(gift_index[g] < gift_index[r]) num_gifts[r]++;
            }
            else
            {
                if(num_g > num_r) num_gifts[g]++;
                else num_gifts[r]++;
            }
        }
    }
    for(int i = 0; i < num_of_friends; i++)
    {
        if(num_gifts[i] > answer) answer = num_gifts[i];
    }
    
    return answer;
}