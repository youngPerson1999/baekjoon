#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main(){
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); cout.tie(NULL);

	int n, t, loc;
	long long min = 20000000001;

	cin>>n;
	
	vector<int>h;

	for(int i = 0; i < n; i++){
		cin>>t;
		h.push_back(t);
	}

	sort(h.begin(), h.end());
	
	t = 0;
	for(int i = (n-1)/2; i + abs(t)< n;){
		long long rst = 0;
		for(int j = 0; j < n; j++)
			rst += abs(h[j] - h[i + t]);
		if (rst > min) break;
		if (rst < min) {
			min = rst;
			loc = h[i + t];
		}
		t *= -1;
		if (t >= 0) {
			t++;
		}
	}
	cout<<loc<<"\n";
	
	return 0;
}