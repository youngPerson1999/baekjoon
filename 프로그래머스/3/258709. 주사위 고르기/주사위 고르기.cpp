#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> max_sol;
int max_win = 0;

vector<int> convert_to_hex(int num, int length) {
    vector<int> k(length, 0);
    while(length > 0)
    {
        k[length - 1] = num % 6;
        num /= 6;
        length--;
    }
    return k;
}

int sum_of_dices(vector<vector<int> > dices, vector<int> index, int n) {
    int sum = 0;
    for(int i = 0; i < n; i++)
        sum += dices[i][index[i]];
    return sum;
}

void compare_sum_of_dice(vector<int> dice, vector<int> other, int n, vector<vector<int> > dices) {
    vector<vector<int> > one_dices(n, vector<int>(6));
    vector<vector<int> > two_dices(n, vector<int>(6));
    int one_win = 0, two_win= 0;
    for(int i = 0; i < n; i++)
    {
        one_dices[i] = dices[dice[i]];
        two_dices[i] = dices[other[i]];
    }
    int total = 1, tmp = n;
    while(tmp > 0)
    {
        total *= 6;
        tmp--;
    }
    vector<int>one_index, two_index;
    
    vector<int> sum_ones(total), sum_twos(total);
    for(int i = 0; i < total; i++)
    {
        //제일 작은거부터 시작
        one_index = convert_to_hex(i, n);
        sum_ones[i] = sum_of_dices(one_dices, one_index, n);
    }
    for(int j = total - 1; j >= 0; j--)
    {
        //제일 큰거부터 시작
        two_index = convert_to_hex(j, n);
        sum_twos[j] = sum_of_dices(two_dices, two_index, n);
    }
    sort(sum_ones.begin(), sum_ones.end(), greater<int>());
    sort(sum_twos.begin(), sum_twos.end(), greater<int>());
    for(int i = 0; i < total; i++)
    {
        for(int j = 0; j < total; j++)
        {
            if(sum_ones[i] > sum_twos[j]) {
                one_win += total - j;
                break;
            }
            else if(sum_twos[j] > sum_ones[i]) two_win++;
        }
    }
    if(one_win > max_win){ max_sol = dice; max_win = one_win;}
    if(two_win > max_win) { max_sol = other; max_win = two_win;}
}

vector<int> valid_dices (vector<bool> selected, int n) {
    vector<int> dice;
    for(int i = 0; i < n; i++)
        if(selected[i]) dice.push_back(i);
    return dice;
}

void combination(int d, int i, int n, vector<vector<int> > dice, vector<bool> selected_dice) {
    //1번은 고정해도 됨
    if(d == n || i == n*2)
    {
        vector<int> cur_dices = valid_dices(selected_dice, n*2);
        if(cur_dices.size() != n) return;
        vector<int> other;
        for(int i = 0; i < n*2; i++)
            if(selected_dice[i]==false) other.push_back(i);
        compare_sum_of_dice(cur_dices, other, n, dice);

    }
    else
    {
        selected_dice[i] = true;
        combination(d+1, i+1, n, dice, selected_dice);
        selected_dice[i] = false;
        combination(d, i+1, n, dice, selected_dice);
    }
}

vector<int> solution(vector<vector<int> > dice) {
    vector<int> answer;
    int d_size = dice.size();
    for(int i = 0; i < d_size; i++)
        sort(dice[i].begin(), dice[i].end());
    vector<bool> selected(d_size, false);
    max_sol.resize(d_size/2);
    selected[0] = true;
    combination(1, 1, d_size/2,dice,  selected);
    answer.resize(d_size/2);
    for(int i = 0; i < d_size/2; i++)
        answer[i] = max_sol[i]+1;
    return answer;
}