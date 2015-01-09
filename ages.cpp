#include <iostream>

using namespace std;

void SortAges(int *ages, int length)
{
	if (ages == NULL || length <= 0)
		return;

	const int oldestAge = 99;
	int timesofAge[oldestAge + 1] = {0};

	for (int i = 0; i < length; i++) {
		timesofAge[ages[i]]++;
	}

	int index = 0;
	for (int i = 0; i < oldestAge; i++) {
		for (int j = 0; j < timesofAge[i]; j++) {
			ages[index] = i;
			index++;
		}
	}	
}

void Print(int *p, int length)
{
	for (int i = 0; i < length; i++) {
		cout << p[i] << " ";
	}
	cout << endl;
}

int main(int argc, const char *argv[])
{
	int ages[10] = {30, 31, 22, 22, 23, 40, 33, 40, 39, 45}; 

	Print(ages, 10);
	SortAges(ages, 10);
	Print(ages, 10);

	return 0;
}
