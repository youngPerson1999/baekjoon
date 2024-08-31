#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;
vector<pair<int, int> >ladder, snake;
vector<int>map(101, 0);
queue<pair<int, int> >q;

int find_ladder(int pos)
{
    if(map[pos] == 2)
    {
        for(int i = 0; i < n; i++)
        {
            if(ladder[i].first == pos)
                return ladder[i].second;
        }
        
    }
    return pos;
}

int find_snake(int pos)
{
    if(map[pos] == -1)
    {
        for(int i = 0; i < m; i++)
        {
            if(snake[i].first == pos)
                return snake[i].second;
        }
    }
    return pos;
}

void push_queue(int pos, int dist) {
    for(int i = 6; i >= 1; i--)
    {
        int curr = pos + i;
        if(curr > 100 || map[curr] == 1) continue;
        int next = curr;
        if(map[next] == 2) next = find_ladder(next);
        else if(map[next] == -1) next = find_snake(next);
        q.push({next, dist + 1});
        map[next] = 1;
    }
}

void nonrandom_dice() 
{
    q.push({1, 0});
    //visited 1
    map[1] = 1;
    int pos = 1;
    while(!q.empty())
    {
        pair<int, int> front = q.front();
        int dist = front.second;
        pos = front.first;
        if(pos == 100){
            cout<<dist<<'\n';
            return;
        }
        q.pop();
        push_queue(pos, dist);
    }
    return;
}

int main()
{
    pair<int, int> input;
    cin>>n>>m;
    ladder.resize(n);
    snake.resize(m);
    
    for(int i = 0; i < n; i++)
    {
        cin>>input.first>>input.second;
        //ladder 2
        map[input.first] = 2;
        ladder[i] = input;
    }
    for(int i = 0; i< m; i++)
    {
        cin>>input.first>>input.second;
        //snake -1
        map[input.first] = -1;
        snake[i] = input;
    }
    nonrandom_dice();
    return 0;
}