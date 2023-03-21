#include <iostream>
#include <algorithm>
#define MIN 100001

using namespace std;

void	cal_min_sol(int n, int k, int *coin)
{
	int	*sol;
	int	i;
	int	j;

	sol = new int[k + 1];
	fill(sol, sol + k + 1, MIN);
	sol[0] = 0;
	i = 0;
	while (++i <= k)
	{
		j = -1;
		while (++j < n)
		{
			if (i - coin[j] < 0)
				continue;
			sol[i] = min(sol[i], sol[i - coin[j]] + 1);
		}
	}
	if (sol[k] >= MIN)
		cout<<"-1\n";
	else
		cout<<sol[k]<<"\n";
}

int	main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int	n;
	int	k;
	int	i;
	int	*coin;

	cin>>n>>k;
	coin = new int[n];
	i = -1;
	while (++i < n)
		cin>>coin[i];
	sort(coin, coin + n);
	cal_min_sol(n, k, coin);
	return (0);
}
