#include <iostream>
#include <vector>

int main() {
	int n, x; std::cin >> n;
	std::vector<int> sequence;
	while (n--) {
		std::cin >> x;
		auto it = std::lower_bound(sequence.begin(), sequence.end(), x);
		if (it == sequence.end())
			sequence.push_back(x);
		else
			*it = x;
	}
	std::cout << sequence.size() << '\n';
	return 0;
}
