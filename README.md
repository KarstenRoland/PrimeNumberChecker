# PrimeNumberChecker
An extension of a programming test from a college course.
Accepts a user input in the form of a positive integer and calculates all prime numbers between 2 and that number.

##Version 1 (35 lines):
This version is limited to all numbers between 1 and 100. It checks all numbers between 2 and the square root of the number it was checking for divisibility. It uses a condition counter to determine if a number is prime or composite, outputting the number after a condition check. The program is short and easy to understand, but checks way more numbers than it needs to.

##Version 2 (62 lines):
This version was constructed from scratch and checks all numbers between 2 and a user-defined maximum. If the user input is invalid (e.g. a string of characters or an empty string) or is below the minimum (2), it throws an exception, asking again for a valid input and looping until a valid input is entered. If the user enters a floating point number, the program rounds down to the nearest integer. If the user enters a number greater than 32 bits, the program throws an unhandled out-of-range exception. The program uses a vector to keep track of all confirmed prime numbers. It checks a number for divisibility against all prime numbers in the vector, stopping when the prime number it's using is greater than the square root of the number being checked. If the number is prime at the end of this process, it adds it to the end of the vector. Once all numbers are checked, it outputs each prime number in the vector on a new line. The larger the number is, the longer it takes to compute all prime numbers.

##Version 3 (74 lines):
This version is virtually identical to version 2, but uses Regex to validate user input ("\d+"). If the input fails a regex_match check, the program outputs a request for a valid input and loops. Negative integers, empty strings, and floating point numbers will fail. Entering a number below the minimum (2) will also fail. The prime calculation algorithm is identical to version 2. A statement was added at the start of the algorithm to let the user know the calculation is in progress. The output was cleaned up for ease of viewing: an underline was added to separate the "PRIME NUMBERS" title from the numbers themselves and the for-each loop was ditched to allow each number to be printed in sequence, separated by commas instead of new lines.
