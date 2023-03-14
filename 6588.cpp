#include <iostream>
#define MAX 1000000
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

	i = 3;
	j = n - 3;
	while (!is_prime[i] || !is_prime[j])
	{
		i += 2;
		j -= 2;
	}
	cout<<i<<" + "<<j;
}

int	main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);	
	int		n;
	bool	*is_prime;

	is_prime = eratos();
	while (1)
	{
		cin>>n;
		if (n == 0)
			break;
		cout<<n<<" = ";
		print_sum(n, is_prime);
		cout<<"\n";
	}
	return (0);
}
