#include <iostream>
#include <string>



void print(std::string *places, int32_t n) {
	for (int i = 0; i < n; i++) {
		std::cout << places[i] << std::endl;
	}
}

int main()
{
	int32_t n;
	std::cin >> n;
	std::string *places = new std::string[n];
	for (int32_t i = 0; i < n; i++) {
		std::cin >> places[i];
	}
	int32_t m;
	std::cin >> m;
	for (int32_t i = 0; i < m; i++) {
		int num;
		std::string side, position;
		std::cin >> num >> side >> position;
		int32_t point = 0;
		if (side[0] == 'r') {
			point += 4;
			if (position[0] == 'w') {
				point += 2;
			}
		}
		else if (position[0] == 'a') {
			point += 2;
		}
		bool t_f = false;
		switch (point) {
		case 0: // on the left by the window
			switch (num) {
			case 1: // one person
				for (int32_t j = 0; j < n; j++) {
					if (places[j][0] == '.') {
						places[j][0] = 'X';
						std::cout << "Passengers can take seats: " << j + 1 << "A" << std::endl;
						print(places, n);
						places[j][0] = '#';
						t_f = true;
						break;
					}
				}
				break;
			case 2: // two persons
				for (int32_t j = 0; j < n; j++) {
					if (places[j][0] == '.' && places[j][1] == '.') {
						places[j][0] = 'X';
						places[j][1] = 'X';
						std::cout << "Passengers can take seats: " << j + 1 << "A" << " " << j + 1 << "B" << std::endl;
						print(places, n);
						places[j][0] = '#';
						places[j][1] = '#';
						t_f = true;
						break;
					}
				}
				break;
			case 3: // three persons
				for (int32_t j = 0; j < n; j++) {
					if (places[j][0] == '.' && places[j][1] == '.' && places[j][2] == '.') {
						places[j][0] = 'X';
						places[j][1] = 'X';
						places[j][2] = 'X';
						std::cout << "Passengers can take seats: " << j + 1 << "A" << " " << j + 1 << "B" << " " << j + 1 << "C" << std::endl;
						print(places, n);
						places[j][0] = '#';
						places[j][1] = '#';
						places[j][2] = '#';
						t_f = true;
						break;
					}
				}
				break;
			}
			break;
		case 2: // to the left of the aisle
			switch (num) {
			case 1: // one person
				for (int32_t j = 0; j < n; j++) {
					if (places[j][2] == '.') {
						places[j][2] = 'X';
						std::cout << "Passengers can take seats: " << j + 1 << "C" << std::endl;
						print(places, n);
						places[j][2] = '#';
						t_f = true;
						break;
					}
				}
				break;
			case 2: // two persons
				for (int32_t j = 0; j < n; j++) {
					if (places[j][2] == '.' && places[j][1] == '.') {
						places[j][2] = 'X';
						places[j][1] = 'X';
						std::cout << "Passengers can take seats: " << j + 1 << "B" << " " << j + 1 << "C" << std::endl;
						print(places, n);
						places[j][2] = '#';
						places[j][1] = '#';
						t_f = true;
						break;
					}
				}
				break;
			case 3: // three persons
				for (int32_t j = 0; j < n; j++) {
					if (places[j][2] == '.' && places[j][1] == '.' && places[j][0] == '.') {
						places[j][2] = 'X';
						places[j][1] = 'X';
						places[j][0] = 'X';
						std::cout << "Passengers can take seats: " << j + 1 << "A" << " " << j + 1 << "B" << " " << j + 1 << "C" << std::endl;
						print(places, n);
						places[j][2] = '#';
						places[j][1] = '#';
						places[j][0] = '#';
						t_f = true;
						break;
					}
				}
				break;
			}
			break;
		case 4: // to the right of the aisle 
			switch (num) {
			case 1: // one person
				for (int32_t j = 0; j < n; j++) {
					if (places[j][4] == '.') {
						places[j][4] = 'X';
						std::cout << "Passengers can take seats: " << j + 1 << "D" << std::endl;
						print(places, n);
						places[j][4] = '#';
						t_f = true;
						break;
					}
				}
				break;
			case 2: // two persons
				for (int32_t j = 0; j < n; j++) {
					if (places[j][4] == '.' && places[j][5] == '.') {
						places[j][4] = 'X';
						places[j][5] = 'X';
						std::cout << "Passengers can take seats: " << j + 1 << "D" << " " << j + 1 << "E" << std::endl;
						print(places, n);
						places[j][4] = '#';
						places[j][5] = '#';
						t_f = true;
						break;
					}
				}
				break;
			case 3: // three persons
				for (int32_t j = 0; j < n; j++) {
					if (places[j][4] == '.' && places[j][5] == '.' && places[j][6] == '.') {
						places[j][4] = 'X'; 
						places[j][5] = 'X';
						places[j][6] = 'X';
						std::cout << "Passengers can take seats: " << j + 1 << "D" << " " << j + 1 << "E" << " " << j + 1 << "F" << std::endl;
						print(places, n);
						places[j][4] = '#';
						places[j][5] = '#';
						places[j][6] = '#';
						t_f = true;
						break;
					}
				}
				break;
			}
			break;
		case 6: // right by the window
			switch (num) {
			case 1: // one person
				for (int32_t j = 0; j < n; j++) {
					if (places[j][6] == '.') {
						places[j][6] = 'X';
						std::cout << "Passengers can take seats: " << j + 1 << "F" << std::endl;
						print(places, n);
						places[j][6] = '#';
						t_f = true;
						break;
					}
				}
				break;
			case 2: // two persons
				for (int32_t j = 0; j < n; j++) {
					if (places[j][6] == '.' && places[j][5] == '.') {
						places[j][6] = 'X';
						places[j][5] = 'X';
						std::cout << "Passengers can take seats: " << j + 1 << "E" << " " << j + 1 << "F" << std::endl;
						print(places, n);
						places[j][6] = '#';
						places[j][5] = '#';
						t_f = true;
						break;
					}
				}
				break;
			case 3: // three persons
				for (int32_t j = 0; j < n; j++) {
					if (places[j][6] == '.' && places[j][5] == '.' && places[j][4] == '.') {
						places[j][6] = 'X';
						places[j][5] = 'X';
						places[j][4] = 'X';
						std::cout << "Passengers can take seats: " << j + 1 << "D" << " " << j + 1 << "E" << " " << j + 1 << "F" << std::endl;
						print(places, n);
						places[j][6] = '#';
						places[j][5] = '#';
						places[j][4] = '#';
						t_f = true;
						break;
					}
				}
				break;
			}
			break;
		}
		
		if (!t_f) {
			std::cout << "Cannot fulfill passengers requirements" << std::endl;
		}
			
	}
	return 0;
}
