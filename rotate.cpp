// 求旋转数组中的最小值
// 二分查找

#include <iostream>

using namespace std;

int MinOrder(int *numbers, int start, int end)
{
	int result = numbers[start];
	for (int i = start + 1; i <= end; i++) {
		if (numbers[i] < result)
			result = numbers[i];
	}
	return result;
}

int Mid(int *numbers, int length)
{
	int index1 = 0;
	int index2 = length - 1;
	int indexMid = index1; // 如果数组旋转为0，第一个元素即为最小值

	while (numbers[index1] >= numbers[index2]) {
		if (index2 - index1 == 1) {
			indexMid = index2;
			break;
		}

		indexMid = (index1 + index2) / 2;

		// 特殊情况如:{0, 1, 1, 1, 1}->{1, 0, 1, 1, 1}
		// numbers[0] = numbers[2] = numbers[4]
		if (numbers[index1] == numbers[indexMid] &&
			numbers[index2] == numbers[indexMid])
			return MinOrder(numbers, index1, index2);

		if (numbers[indexMid] >= numbers[index1])
			index1 = indexMid;
		else if (numbers[indexMid] <= numbers[index2])
			index2 = indexMid;
	}

	return numbers[indexMid];
}


int main(int argc, const char *argv[])
{
	int numbers[] = {3, 4, 5, 1, 2};
	int min = Mid(numbers, 5);

	cout << min << endl;

	return 0;
}
