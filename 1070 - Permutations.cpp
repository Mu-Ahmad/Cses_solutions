#include<bits/stdc++.h>
using namespace std;

#define finc(s, e, k)		for(int i=s; i<e; i+=k)

int main() {
	int n; cin >> n;

	if (n == 1) cout << 1;

	else if (n < 4) cout << "NO SOLUTION";

	else {
		finc(1, n, 2) cout << n - i << ' ';
		finc(0, n, 2) cout << n - i << ' ';
	}

	return 0;
}



