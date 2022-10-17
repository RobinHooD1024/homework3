#include <iostream>
#include <string>
#include "random_value.h"
#include "high_scores.h"

using namespace std;

int main(int argc, char** argv) {

    int max {100};
    if (argc >= 2) {
        string arg1 = argv[1];
        if (argc == 3 && arg1 == "-max") {
            max = stoi(argv[2]);
        } else if (argc == 2 && arg1 == "-table"){
            print_hs();
            return 1;
        } else {
            max = 100;
        }
    }

	const int target_value = getNumber(max);
	int current_value = 0;
	bool not_win = true;
    string name;
    int attempt_count = 0;

    cout << "Enter your name" << endl;
    cin >> name;
	std::cout << "Enter your guess:" << std::endl;

	do {
        std::cin >> current_value;

		if (current_value > target_value) {
			std::cout << "less than " << current_value << std::endl;
            attempt_count++;
		}
		else if (current_value < target_value) {
			std::cout << "greater than " << current_value << std::endl;
            attempt_count++;
		}
		else {
            not_win = false;
            save_and_print_hs(name, ++attempt_count);
			break;
		}

	} while (not_win);

	return 0;
}