#include <iostream>
#define  ln(X)    (int)X.length()
using namespace std;

string one[10] = {
	"",
	"one",
	"two",
	"three",
	"four",
	"five",
	"six",
	"seven",
	"eight",
	"nine"
};

string eleven[10] = {
	"eleven",
	"twelve",
	"thirteen",
	"fourteen",
	"fifteen",
	"sixteen",
	"seventeen",
	"eighteen",
	"nineteen"
};

string ten[10] = {
	"ten",
	"twenty",
	"thirty",
	"forty",
	"fifty",
	"sixty",
	"seventy",
	"eighty",
	"ninety"
};

string nike(int x) { // just do it
	if (x < 10)
		return one[x];
	
	if (11 <= x && x <= 19)
		return eleven[x-11];
	
	if (10 <= x && x <= 99)
		return ten[x/10-1]+nike(x%10);
	
	if (100 <= x && x <= 999)
		return one[x/100]+"hundred"+nike(x%100);
	
	return "NULL";
}

int n, totlen;
int res;
string s[20];

int main() {
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		cin >> s[i];
		
		if (s[i] != "$")
			totlen += ln(s[i]);
	}
	
	for (res = 1; res < 1000; res++)
		if (totlen+ln(nike(res)) == res)
			break;
	
	for (int i = 0; i < n; i++)
		cout <<  (s[i] != "$" ?s[i] :nike(res)) << " ";
	
	return 0;
}
