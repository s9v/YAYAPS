#include <iostream>
#include <cstdio>
#include <algorithm>
#define  ln(X)    (int)X.length()
#define  DBG(X)   cerr << #X << " --> " << X << "\n";
using namespace std;
typedef long long llint;

int n;
int a[1000];
int b[1000];

int main() {
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		cin >> b[i];
	}
	
	double L = 0;
	double U = 1e18;
	for (int i = 0; i < n; i++) {
		for (int j = i+1; j < n; j++) {
			if (b[i] == b[j]) {
				if (a[i] < a[j]) {
					cout << -1;
					return 0;
				}
			}
			else if (b[i] > b[j]) {
				double l = 1.0 * (a[j]-a[i]) / (b[i]-b[j]);
				
				if (l > U) {
					cout << -1;
					return 0;
				}
				
				L = max(L, l);
			}
			else {
				double u = 1.0 * (a[i]-a[j]) / (b[j]-b[i]);
				
				if (L > u) {
					cout << -1;
					return 0;
				}
				
				U = min(U, u);
			}
		}
	}
	
	if (L == 0) {
		cout << 0;
		return 0;
	}
	
	int g = b[0];
	for (int i = 1; i < n; i++)
		g = __gcd(g, b[i]);
	
	for (int i = 0; i < n; i++)
		b[i] /= g;
	
	llint sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += b[i];
		
		if (L*sum > 1e7) {
			cout << -1;
			return 0;
		}
	}
	
	printf("%.15lf", L*sum);
	
	return 0;
}
