#include <iostream>
#include <vector>

using namespace std;

int main() {
	long long total = 0, n; cin >> n;
	int arr[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		total += arr[i];
	}

	vector< vector<long long> > dp(n, vector<long long>(n));

	for (int l = n - 1; l >= 0; l--)
		for (int r = l; r < n; r++)
			if (l == r)	dp[l][r] = arr[l];
			else dp[l][r] = max(arr[l] - dp[l + 1][r], arr[r] - dp[l][r - 1]);


	cout << (total + dp[0][n - 1]) / 2 << '\n';
	return 0;
}
