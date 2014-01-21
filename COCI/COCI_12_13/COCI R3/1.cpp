#include <iostream>
using namespace std;
typedef long long llint;

int n;
llint a, na;
llint b, nb;

int main() {
	cin >> n;
	
	a = 1;
	b = 0;
	
	for (int i = 0; i < n; i++) {
		na = b;
		nb = a+b;
		
		a = na;
		b = nb;
	}
	
	cout << a << " " << b;
	
	return 0;
}
