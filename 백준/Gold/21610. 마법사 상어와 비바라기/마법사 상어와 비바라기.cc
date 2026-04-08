#include <iostream>
#include <vector>
#include <deque>
#include <cmath>

using namespace std;

int n;
vector<vector<int>> A;
vector<pair<int, int>> dirs = {{0, -1}, {-1, -1}, {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}};

//방향 {0, -1}, {-1, -1}, {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}
pair<int, int> move_cloud(pair<int, int>cloud, int d, int s)
{
    int dr = dirs[d - 1].first, dc = dirs[d - 1].second;
    int r = cloud.first + dr * s;
    int c = cloud.second + dc * s;
    if(r < 0)
    {
        r += (n * (abs((r + 1) / n) + 1));
    }
    else if(r >= n)
    {
        r -= (n * (r / n));
    }
    if(c < 0)
    {
        c += (n * (abs((c + 1) / n) + 1));
    }
    else if(c >= n)
    {
        c -= (n * (c / n));
    }
    return make_pair(r, c);
}

void rain_bucket(deque<pair<int, int>> clouds)
{
    int num_clouds = clouds.size();
    for (int i = 0; i < num_clouds; i++)
    {
        int r = clouds[i].first, c = clouds[i].second;
        A[r][c]++;
    }
}


void copy_water_magic(pair<int, int> cloud){
    // dirs에서 1, 3, 5, 7
    int add_water = 0;
    for (int i = 1; i < 8; i += 2)
    {
        int r = cloud.first + dirs[i].first;
        int c = cloud.second + dirs[i].second;
        if (r >= 0 &&r < n &&c >= 0 &&c < n &&A[r][c] > 0)
        {
            add_water++;
        }
    }
    A[cloud.first][cloud.second] += add_water;
}

deque<pair<int, int>> create_clouds(vector<vector<bool>> is_cloud)
{
    deque<pair<int, int>> clouds;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(A[i][j] >= 2 && !is_cloud[i][j])
            {
                clouds.push_back(make_pair(i, j));
                A[i][j] -= 2;
            }
        }
    }
    return clouds;
}

int sum_water()
{
    int sol = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            sol += A[i][j];
        }
    }
    return sol;
}

void show_map()
{
    cout << "-----------------------------\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << A[i][j] << ' ';
        }
        cout << '\n';
    }
}

int main()
{
    int m, d, s;
    cin >> n >> m;
    A.resize(n, vector<int>(n));
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cin >> A[i][j];
    }
    deque<pair<int, int>> clouds = {{n - 1, 0}, {n - 1, 1}, {n - 2, 0}, {n - 2, 1}};

    for (int i = 0; i < m; i++)
    {
        cin >> d >> s;
        //move clouds
        int num_clouds = clouds.size();
        vector<vector<bool>> is_cloud(n, vector<bool>(n, false));
        for (int j = 0; j < num_clouds; j++)
        {
            pair<int, int> next_cloud = move_cloud(clouds[0], d, s);
            is_cloud[next_cloud.first][next_cloud.second] = true;
            clouds.push_back(next_cloud);
            clouds.pop_front();
        }
        // add water to bucket under clouds
        rain_bucket(clouds);
        for (int j = 0; j < num_clouds; j++)
        {
            copy_water_magic(clouds[j]);
        }
        clouds = create_clouds(is_cloud);
    }

    cout << sum_water() << '\n';

    return 0;
}