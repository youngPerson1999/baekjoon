#include <iostream>
#define MAX 10000
using namespace	std;

bool	*eratos(void)
{
	bool	*nums;
	int		i, j;

	nums = new bool[MAX + 1];
	i = 1;
	while (++i <= MAX)
		nums[i] = true;
	i = 2;
	while (i * i <= MAX)
	{
		j = i * i;
		if (nums[i])
			while (j <= MAX)
			{
				nums[j] = false;
				j += i;
			}
		i++;
	}
	return (nums);
}

void	print_sum(int n, bool *is_prime)
{
	int	i, j;

	if (n / 2 % 2 == 1)
	{
		i = n / 2;
		j = n / 2;
	}
	else if (n > 4)
	{
		i = n / 2 + 1;
		j = n / 2 - 1;
	}
	else
	{
		cout<<"2 2";
		return ;
	}
	while (!is_prime[i] || !is_prime[j])
	{
		i += 2;
		j -= 2;
	}
	cout<<j<<" "<<i;
}

int	main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int		n, i;
	bool	*is_prime;

	is_prime = eratos();
	cin>>i;
	while (i-- > 0)
	{
		cin>>n;
		print_sum(n, is_prime);
		cout<<"\n";
	}
	return (0);
}
