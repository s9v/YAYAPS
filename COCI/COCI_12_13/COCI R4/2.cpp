#include <iostream>
#include <string>
#define  ln(X)  (int)X.length()
using namespace std;

int n, m;
string a;
string b;
int cost[300]; // too lazy me :D
int res;

int main()
{
	cin >> a >> b;
	n = ln(a);
	m = ln(b);
	
	cin >> cost['A'];
	cin >> cost['C'];
	cin >> cost['G'];
	cin >> cost['T'];
	
	res = 1e9;
	for (int i = 0; i < n; i++)
	{
		int cur = 0;
		int x = i;
		int y = 0;
		
		while (y < m)
		{
			if (x < n && a[x] == b[y])
				x++;
			else
				cur += cost[(int)b[y]];
			y++;
		}
		
		res = min(res, cur);
	}
	
	cout << res;
	
	return 0;
}
