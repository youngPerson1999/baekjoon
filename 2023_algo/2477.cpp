#include <iostream>
#include <vector>
#include <utility>
#include <cmath>

using namespace std;

vector<pair<int, int> >coor(6);

int cal_small_rect()
{
	int sum = 0;
	for (int i = 0; i < 6; i++)
	{
		if(i < 5)
			sum += coor[i].first * coor[i + 1].second;
		else
			sum += coor[i].first * coor[0].second;
		if(i > 0)
			sum -= coor[i].first * coor[i - 1].second;
		else
			sum -= coor[i].first * coor[5].second;
		// cout << sum << " ";
	}
	sum /= 2;
	return abs(sum);
}

int main(){
	int k;
	cin >> k;

	for (int i = 0; i < 6; i++)
	{
		int direct, dist;
		cin >> direct >> dist;
		
		if (direct == 1 || direct == 2)
		{
			coor[i].first = coor[i - 1].first + pow(-1, direct % 2) * dist;
			coor[i].second = coor[i - 1].second;
		}
		else
		{
			coor[i].first = coor[i - 1].first;
			coor[i].second = coor[i - 1].second + pow(-1, direct % 2) * dist;
		}
		// cout<<"\n" << coor[i].first << ", " << coor[i].second;
	}
	cout << k * cal_small_rect() << "\n";

	return 0;
}
