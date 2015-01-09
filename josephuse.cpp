#include <iostream>
#include <list>

using namespace std;

int LastRemaining(unsigned int n, unsigned int m)
{
	if (n < 1 || m < 1)
		return -1;

	unsigned int i = 0;

	list<int> numbers;
	for (i = 0; i < n; i++) {
		numbers.push_back(i);
	}

	list<int>::iterator current = numbers.begin();
	while (numbers.size() > 1) {
		for (int i = 1; i < m; i++) {
			current++;
			if (current == numbers.end())
				current = numbers.begin();
		}

		list<int>::iterator next = ++current;
		if (next == numbers.end())
			next = numbers.begin();

		current--;
		numbers.erase(current);
		current = next;
	}

	return *current;
}

int josephuse()
{
	const int N = 5;
	int j[N] = {0};
	int bol[N] = {0};
	int i, c = 0, bleap = 1;

	for (i = 0; i < N; i++) {
		j[i] = i;
	}

	i = 0;
	while (c < N) {
		if (bol[i%N] == 0) {
			if (bleap == 0) {
				bleap = 1;
			} else {
				c++;
				bol[i%N] = 1;
				bleap = 0;
			}
		}
		i++;
	}
	return j[i%N];
} 

int main(int argc, const char *argv[])
{
	cout << LastRemaining(5, 3) << endl;
	cout << josephuse() << endl;

	return 0;
}
