#include <iostream>

int main()
{
	int n = 0;
	std::cin >> n;
	int *v = new int[n];
	for (int i = 0; i < n; i++) {
		std::cin >> v[i];
	}
	int end = n - 1;
	for (int i = 0; i < end; i++) {
		if (v[i] > v[i + 1]) {
			std::cout << -1;
			return 0;
		}
	}
	std::cout << v[end] - v[0];
	return 0;
}