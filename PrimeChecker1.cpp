#include <iostream>
#include <string>
using namespace std;

int main() {
	enum constants {
		MIN = 1, MAX = 100
	};

	unsigned int counter; // if this hits 2, the number is not prime
	unsigned int x; // second index, counts from MIN to the square root of i

	for (unsigned int i = MIN; i <= MAX; i++) {
		x = 1; 
		counter = 0;

		if (i == 1) {
			// 1 is a unique case, being neither prime nor composite.
			// If it falls between the min and max, exclude it.
			counter = 2;
		}

		while (x <= pow(i, 0.5) && counter < 2) { // while x <= the square root of i and the number is not prime...
			if (i % x == 0) { // if i is divisible by the current second index...
				counter++;
			}
			x++;
		}
		if(counter == 1) {
			cout << i << endl;
		}
	}

	return 0;
}