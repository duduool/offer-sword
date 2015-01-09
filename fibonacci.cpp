#include <iostream>

using namespace std;

long long Fibonacci(unsigned int n)
{
	int result[2] = {0, 1};
	if (n < 2)
		return result[n];

	long long fibNMinusOne = 0;
	long long fibNMinusTwo = 1;
	long long fibN;

	for (int i = 2; i <= n; i++) {
		fibN = fibNMinusOne + fibNMinusTwo;

		fibNMinusOne = fibNMinusTwo;
		fibNMinusTwo = fibN;
	}

	return fibN;
}

int main(int argc, const char *argv[])
{
	cout << Fibonacci(0) << " ";
	cout << Fibonacci(1) << " ";
	cout << Fibonacci(2) << " ";
	cout << Fibonacci(3) << " ";
	cout << Fibonacci(4) << " ";
	cout << endl;

	return 0;
}
