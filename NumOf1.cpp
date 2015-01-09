#include <iostream>

using namespace std;

int Numof1(int n)
{
	int count = 0;

	while (n) {
		count++;
		n = (n - 1) & n;
	}

	return count;
}

int main(int argc, const char *argv[])
{
	cout << Numof1(15) << endl;
	
	return 0;
}
