#include <iostream>
#include <deque>

using namespace std;

deque<int> dq;
int dq_size, first_fruit, second_fruit, diff_pos;
int find_diff_position(int start)
{
    for (int i = start + 1; i < dq_size; i++)
    {
        if(dq[i] != dq[i - 1])
            return i;
    }
    return dq_size;
}
int cal_diff_pos_of_fruit(int start, int first, int second)
{
    //find position of not 1st and 2nd
    int i;
    for (i = start; i < dq_size; i++)
    {
        if(dq[i] != first && dq[i] != second)
            return i;
    }
    return i;
}
int cal_end_pos_2nd(int end)
{
    //find position of fruit right before diff pos
    int end_fruit = dq[end - 1];
    for (int i = end - 1; i >= 0; i--)
    {
        if(dq[i] != end_fruit)
            return i + 1;
    }
    return -1;
}
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, fruit, i, max = 0;

    cin >> n;
    dq.resize(n);
    dq_size = dq.size();
    for (i = 0; i < n; i++)
    {
        cin >> fruit;
        dq[i] = fruit;
    }
    //find first second position
    int first_pos = 0;
    first_fruit = dq[first_pos];
    int second_pos = find_diff_position(first_pos);
    second_fruit = dq[second_pos];

    if (second_pos >= n - 1)
        //if uniform dq return size
        max = dq_size;
    else{
        diff_pos = cal_diff_pos_of_fruit(first_pos, first_fruit, second_fruit);
        second_pos = cal_end_pos_2nd(diff_pos);
        while(diff_pos <= n)
        {
            int num = diff_pos - first_pos;
            max = num > max ? num : max;
            first_pos = second_pos;
            second_fruit = dq[diff_pos];
            first_fruit = dq[second_pos];
            if(diff_pos == n)
                break;
            diff_pos = cal_diff_pos_of_fruit(first_pos, first_fruit, second_fruit);
            second_pos = cal_end_pos_2nd(diff_pos);
        }
    }
        
    cout << max << '\n';

    return 0;
}