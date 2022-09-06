#include <iostream>
#include <regex>
#include <string>
#include <vector>

int main() {
	enum constants {
		MIN = 2
	};

	std::vector<int> primes; // Dynamic array for prime numbers. The program will build this list and use it to discover additional primes.
	unsigned int max{ 0 }; // User-defined maximum number to check.
	bool valid{ false }; // Used for determining valid user input.
	std::string input{ "" }; // Accepts getline for checking valid input.

	std::regex inputRegexValidation("\\d+");

	do {
		std::cout << "Enter an integer to serve as the maximum: ";
		std::getline(std::cin, input);
		
		if (std::regex_match(input, inputRegexValidation)) {
			try {
				max = stoi(input);
				if (max >= MIN) { // if the input is less than the permitted minumum enum, throw an exception.
					valid = true;
				}
			}
			catch (std::out_of_range e) {
				std::cout << "Your max number is too large! Use a number smaller than 2147483648!\n";
			}
		}
		else {
			std::cout << "Invalid input!\n";
		}
	} while (!valid);

	std::cout << "Working...\n";

	bool isComposite{ false };
	// i represents all numbers from MIN to max
	// x represents the index value of all numbers in primes
	for (unsigned int i = MIN; i <= max; i++) {
		isComposite = false;

		/*
		* The following for loop will be terminated under the following conditions:
		*	x exceeds the maximum index value of primes.
		*	the int at x is greater than the square root of i.
		*	i is found to be composite.
		*/
		for (unsigned int x{ 0 }; x < primes.size() && primes.at(x) <= pow(i, 0.5) && !isComposite; x++) {
			if (i % primes.at(x) == 0) {
				isComposite = true;
			}
		}
		if (!isComposite) { // If by this point, i is not composite, it is considered prime and added to the end of primes.
			primes.push_back(i);
		}
	}

	std::cout << "PRIME NUMBERS:\n";
	std::cout << "--------------\n";

	/*for (int number : primes) {
		std::cout << number << "\n";
	}*/

	std::cout << primes.at(0);
	for (unsigned int number{ 1 }; number < primes.size(); number++) {
		std::cout << ", " << primes.at(number);
	}
	return 0;
}