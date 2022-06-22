#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int n, m, x; cin >> n >> m >> x;

	int desired[n];
	int size[m];

	for (int i = 0; i < n; i++)
		cin >> desired[i];


	for (int i = 0; i < m; i++)
		cin >> size[i];

	int i = 0, j = 0;
	int count = 0;

	sort(desired, desired + n);
	sort(size, size + m);


	while (i < n and j < m) {
		if (size[j] < desired[i] - x)	j++; // Current House Can not be alloted

		else if (size[j] <= desired[i] + x) { // House is alloted to current customer
			j++;
			i++;
			count++;
		}

		else	i++; // Current Customer can not be alloted a house
	}

	cout << count << '\n';
	return 0;
}
