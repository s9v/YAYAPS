#include <iostream>
using namespace std;

int n;
int o;
int mn;
int mx;

int main()
{
	cin >> n >> o;
	
	mx = -1000;
	mn = +1000;
	
	for (int m = 0; m <= 15000; m++)
		if (m - m/n == o)
		{
			mn = min(mn, m);
			mx = max(mx, m);
		}
	
	cout << mn << " " << mx;
	
	return 0;
}
