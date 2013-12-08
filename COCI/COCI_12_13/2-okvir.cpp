#include <iostream>
using namespace std;

int n, m;
int u, l, r, d;
char c[100][100];

int main() {
	cin >> n >> m;
	
	cin >> u >> l >> r >> d;
	
	for (int i = 0; i < n+u+d; i++)
		for (int j = 0; j < m+l+r; j++)
			c[i][j] = ((i%2 + j%2)%2 == 0 ?'#' :'.');
	
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			char x;
			cin >> x;
			c[i+u][j+l] = x;
		}
	
	for (int i = 0; i < n+u+d; i++) {
		for (int j = 0; j < m+l+r; j++)
			cout << c[i][j];
		cout << "\n";
	}
	
	return 0;
}
