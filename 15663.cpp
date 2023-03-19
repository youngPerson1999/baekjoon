#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector <int>			num;
vector <int>			list;
vector <bool>			used;

void	ft_putnum(int m)
{
	int	i;

	i = -1;
	while (++i < m)
	{
		cout<<list[i];
		if (i != m - 1)
			cout<<" ";
		else
			cout<<"\n";
	}
}

void	ft_cal_comb(int n, int m)
{
	int	i;
	int	l;

	if (list.size() == m)
		ft_putnum(m);
	else
	{
		i = -1;
		l = 0;
		while (++i < n)
		{
			if (!used[i] && num[i] != l)
			{
				used[i] = true;
				list.push_back(num[i]);
				l = list[list.size() - 1];
				ft_cal_comb(n, m);
				list.pop_back();
				used[i] = false;
			}
		}
	}
}

void	ft_print_comb(int n, int m)
{
	int				i;
	int				k;

	i = -1;
	while (++i < n)
	{
		cin>>k;
		num.push_back(k);
		used.push_back(false);
	}
	sort(num.begin(), num.end());
	ft_cal_comb(n, m);
}

int	main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int	m;
	int	n;

	cin>>n>>m;
	ft_print_comb(n, m);
	return (0);
}

