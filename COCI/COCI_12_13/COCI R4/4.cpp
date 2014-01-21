#include <iostream>
#include <vector>
#include <set>
#define  sz(X)  (int)X.size()
using namespace std;
typedef vector<int> vi;

int n;
double a;
set<double> s;

int main()
{
	cin >> n;
	
	for (int i = 0; i <= n; i++)
	{
		cin >> a;
		for (int j = 1; j < a; j++)
			s.insert(100.0/a*j);
	}
	
	cout << sz(s);
	
	return 0;
}
