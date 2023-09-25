#include <iostream>
#include <vector>
#include <utility>
#include <deque>
#include <algorithm>

using namespace std;

deque<pair<int, int> > frames;
//first: num, second: count
int is_in_deque(int num)
{
    int size = frames.size();
    if(size == 0)
        return -1;
    for (int i = 0; i < size; i++)
    {
        if(frames[i].first == num)
            return i;
    }
    return -1;
}
int find_min_cnt()
{
    int size = frames.size(), min_cnt = 1001;
    for (int i = 0; i < size; i++)
        if(frames[i].second < min_cnt)
            min_cnt = frames[i].second;
    return min_cnt;
}
int main()
{
    int n, r, num;
    cin >> n >> r;
    for (int i = 0; i < r; i++){
        cin >> num;
        int idx_in_deque = is_in_deque(num);
        if (idx_in_deque != -1)
        {
            frames[idx_in_deque].second++;
            continue;
        }
        if(frames.size() < n)
            frames.push_back(make_pair(num, 1));
        else
        {
            int min_cnt = find_min_cnt();
            vector<int> min_nums;
            for (int j = 0; j < n; j++)
                if(frames[j].second == min_cnt)
                    min_nums.push_back(j);
            frames.erase(frames.begin() + min_nums[0]);
            frames.push_back(make_pair(num, 1));
        }
    }
    sort(frames.begin(), frames.end());
    for (int i = 0; i < frames.size(); i++)
        cout << frames[i].first << " ";
    cout << "\n";
    return 0;
}