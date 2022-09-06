#include <iostream>
#include <string>
#include <vector>

int runVersion2() {
	enum constants {
		MIN = 2
	};
	
	std::vector<int> primes; // Dynamic array for prime numbers. The program will build this list and use it to discover additional primes.
	unsigned int max{ 0 }; // User-defined maximum number to check.
	bool valid{ false }; // Used for determining valid user input.
	std::string input{ "" }; // Accepts getline for checking valid input.
	 // CHECK USER INPUT WITH REGEX IN VERSION 3!

	do {
		std::cout << "Enter a positive integer to serve as the maximum: ";
		std::getline(std::cin, input);
		try {
			max = stoi(input); // Will throw an exception if the input cannot be converted to an int.
			std::cout << max << "\n";
			if (max < MIN) { // if the input is less than the permitted minumum enum, throw an exception.
				throw std::exception();
			}

			valid = true;
		}
		catch (std::exception e) {
			std::cout << "Invalid input!\n";
		}
	} 
	while (!valid);

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
	for (int number : primes) {
		std::cout << number << "\n";
	}

	return 0;
}