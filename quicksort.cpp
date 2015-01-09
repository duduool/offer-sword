#include <iostream>
#include <exception>

using namespace std;

void Swap(int *a, int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

int Partition(int *data, int length, int start, int end)
{
	if (data == NULL || length <= 0 || start < 0 || end >= length)
		throw new exception();

	int index = (start + end)/2;
	Swap(&data[index], &data[end]);

	int small = start - 1;
	for (index = start; index < end; index++) {
		if (data[index] < data[end]) {
			small++;
			if (small != index)
				Swap(&data[index], &data[small]);
		}
	}

	small++;
	Swap(&data[small], &data[end]);

	return small;
}

void QuickSort(int *data, int length, int start, int end)
{
	if (start == end)
		return;

	int index = Partition(data, length, start, end);
	if (index > start)
		QuickSort(data, length, start, index - 1);
	if (index < end)
		QuickSort(data, length, index + 1, end);
}

void Print(int *data, int length) 
{
	for (int i = 0; i < length; i++) {
		cout << data[i] << " ";
	}
	cout << endl;
}

int main(int argc, const char *argv[])
{
	int data[] = {1, 3, 2, 0, 5, 4};
	Print(data, 6);
	QuickSort(data, 6, 0, 5);
	Print(data, 6);

	return 0;
}
