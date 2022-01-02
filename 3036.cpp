#include <iostream>
#include <vector>

using namespace std;
int gcd(int a, int b)
{
	int c;
	while (b != 0)
	{
		c = a % b;
		a = b;
		b = c;
	}
	return a;
}
int main()
{
    int n,t;
    
    cin>>n;
    
    vector<int>ring(n);
    
    for(int i=0;i<n;i++){
        cin>>t;
        ring[i]=t;
    }
    for(int i=1;i<n;i++){
        int g = gcd(ring[0],ring[i]);
        cout<<ring[0]/g<<"/"<<ring[i]/g<<"\n";
    }

    return 0;
}
