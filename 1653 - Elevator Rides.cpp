#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n, x; cin >> n >> x;
	int weights[n];
	for (int i = 0; i < n; i++) cin >> weights[i];

	pair<int, int> best[1 << n];
	// Base Case
	best[0] = {1, 0};
	for (int i = 1; i < (1 << n); i++) {
		best[i] = {n + 1, 0};
		for (int p = 0; p < n; p++) {
			if (i & (1 << p)) {
				auto choice = best[i ^ (1 << p)];
				if (choice.second + weights[p] <= x) {
					// Add the person to same ride
					choice.second += weights[p];
				} else {
					// Reserve a new ride for the person
					choice.first++;
					choice.second = weights[p];
				}
				best[i] = min(best[i], choice);
			}
		}
	}

	cout << best[(1 << n) - 1].first << '\n';
	return 0;
}
