#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
vector<vector<int> >	alloc_mem(int n, int t)
{
	vector <vector<int>	>	adj;
	int						i;
	int						a;
	int						b;

	adj.resize(n + 1);
	i = -1;
	while (++i < t)
	{
		cin>>a>>b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	return (adj);
}

int	*create_map(int n)
{
	int	*map;
	int	i;

	map = new int [n + 1];
	i = -1;
	while (++i < n)
		map[i] = -1;
	return (map);
}

int	find_mem(int a, int b, vector <vector<int> > adj, int n)
{
	int			tmp;
	int			i;
	int			*map;
	bool		*visit;
	queue <int>	q;

	visit = new bool[n + 1];
	fill(visit, visit + n, false);
	q.push(a);
	map = create_map(n);
	map[a] = 0;
	while (!q.empty())
	{
		tmp = q.front();
		q.pop();
		visit[tmp] = true;
		i = -1;
		while (++i < adj[tmp].size())
		{
			if (!visit[adj[tmp][i]])
			{
				visit[adj[tmp][i]] = false;
				q.push(adj[tmp][i]);
				map[adj[tmp][i]] = map[tmp] + 1;
			}
		}
	}
	return (map[b]);
}

int	main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int	n;
	int	a, b;
	int	t;
	vector <vector<int> > adj;
	
	cin>>n>>a>>b>>t;
	adj = alloc_mem(n, t);
	cout<<find_mem(a, b, adj, n)<<"\n";
	return (0);
}
