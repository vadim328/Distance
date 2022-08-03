#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

void quickSort(int* numbers, int left, int right) {
	int pivot = numbers[(left + right) / 2];
	int left_border = left;
	int right_border = right;
	int value;
	while (right_border >= left_border) {

		while (numbers[left_border] < pivot) {
			left_border++;
		}

		while (numbers[right_border] > pivot) {
			right_border--;
		}

		if (right_border >= left_border) {
			value = numbers[left_border];
			numbers[left_border] = numbers[right_border];
			numbers[right_border] = value;
			left_border++;
			right_border--;
		}	
	}
	if (right_border > left) {
		quickSort(numbers, left, right_border);
	}
	if (left_border < right) {
		quickSort(numbers, right_border, right);
	}
}


int main()
{
	int32_t n, k;
	std::cin >> n >> k;
	int32_t *a = new int32_t[n];
	std::vector<int32_t> a_sort;
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
		a_sort.push_back(a[i]);
	}
	int64_t dist = 0;
	if (n - k == 1) {
		for (int32_t i = 0; i < n; i++) {
			dist = 0;
			for (int32_t j = 0; j < n; j++) {
				if (i != j) {
					dist += std::abs(a[i] - a[j]);
				}
			}
			std::cout << dist << " ";
		}
		return 0;
	}
	std::sort(a_sort.begin(), a_sort.end());
	std::vector<int32_t >::iterator last = a_sort.end() - 1;
	for (int32_t  i = 0; i < n; i++) {
		std::vector<int32_t>::iterator it_left = lower_bound(a_sort.begin(), a_sort.end(), a[i]);
		std::vector<int32_t>::iterator it_right = it_left;
		std::vector<int32_t> s;
		dist = 0;
		if (it_left == a_sort.begin()) {
			for (int32_t j = 0; j < k; j++) {
				it_right++;
				dist += std::abs(a[i] - *it_right);
			}
		}
		else if (it_right == last) {
			for (int32_t j = 0; j < k; j++) {
				it_left--;
				dist += std::abs(a[i] - *it_left);
			}
		}
		else {
			it_left--;
			it_right++;
			bool t_f = false;
			for (int32_t j = 0; j < k; j++) {
				if (it_left == a_sort.begin() && t_f == true) {
					dist += std::abs(a[i] - *it_right);
					it_right++;
				}
				else if (it_right == last && t_f == true) {
					dist += std::abs(a[i] - *it_left);
					it_left--;
				}
				else if (std::abs(a[i] - *it_left) <= std::abs(a[i] - *it_right)) {
					dist += std::abs(a[i] - *it_left);
					if (it_left == a_sort.begin()) {
						t_f = true;
						continue;
					}
					it_left--;
				}
				else {
					dist += std::abs(a[i] - *it_right);
					if (it_right == last) {
						t_f = true;
						continue;
					}
					it_right++;
				}
			}

		}
		std::cout << dist << " ";
	}
	return 0;
}
