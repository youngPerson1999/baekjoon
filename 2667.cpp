#include <iostream>
#include <istream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;

int	bfs(pair <int, int> xy, int **map, bool **t_map, int n)
{
	queue <pair <int, int> > q;
	int						x, y, num;

	x = xy.first;
	y = xy.second;
	t_map[x][y] = true;
	q.push(xy);
	num = 0;
	while (!q.empty())
	{
		x = q.front().first;
		y = q.front().second;
		q.pop();
		num++;
		if (x > 0 && map[x - 1][y] != 0 && !t_map[x - 1][y])
		{
			t_map[x - 1][y] = true;
			q.push(make_pair(x - 1, y));
		}
		if (x < n - 1 && map[x + 1][y] != 0 && !t_map[x + 1][y])
		{
			t_map[x + 1][y] = true;
			q.push(make_pair(x + 1, y));
		}
		if (y > 0 && map[x][y - 1] != 0 && !t_map[x][y - 1])
		{
			t_map[x][y - 1] = true;
			q.push(make_pair(x, y - 1));
		}
		if (y < n - 1 && map[x][y + 1] != 0 && !t_map[x][y + 1])
		{
			t_map[x][y + 1] = true;
			q.push(make_pair(x, y + 1));
		}
	}
	return (num);
}

vector <int>	solve_map(int n, int **map, bool **t_map)
{
	int				num, i, j;
	vector <int>	sol;

	num = 0;
	i = -1;
	while (++i < n)
	{
		j = -1;
		while (++j < n)
		{
			if (map[i][j] != 0 && !t_map[i][j])
			{
				sol.push_back(bfs(make_pair(i, j), map, t_map, n));
				num++;
			}
		}
	}
	cout<<num<<"\n";
	return (sol);
}

int	main()
{
	int				i, j, n;
	int				**map;
	char			*str;
	bool			**t_map;
	vector <int>	sol;

	cin>>n;
	map = new int *[n];
	t_map = new bool *[n];
	i = -1;
	while (++i < n)
	{
		cin.ignore();
		map[i] = new int[n];
		t_map[i] = new bool[n];
		str = new char[n];
		cin>>str;
		j = -1;
		while (++j < n)
		{
			map[i][j] = (int)(str[j] - '0');
			t_map[i][j] = false;
		}
	}
	sol = solve_map(n, map, t_map);
	sort(sol.begin(), sol.end());
	i = -1;
	j = sol.size();
	while (++i < j)
		cout<<sol[i]<<"\n";
	return (0);
}
