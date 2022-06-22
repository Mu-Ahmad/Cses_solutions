#include<bits/stdc++.h>
using namespace std;

int main() {
	long long n; cin >> n;
	long long ans = (n * (n + 1)) / 2;
	for (int i = 1; i < n; i++) {
		long long temp; cin >> temp;
		ans -= temp;
	}
	cout << ans;
	return 0;
}



