#include <cstdlib>
#include <ctime>
#include "random_value.h"

int getNumber (int max) {

	std::srand(std::time(nullptr)); // use current time as seed for random generator

	const int random_value = std::rand() % max;

    return random_value;
}