#include "bin_sort.h"
 // 0   1   2   3   4   5   6   7   8
//{14, 16, 19, 32, 32, 32, 56, 69, 72};
int BinSort(int* arr, int size, int setpoint) {
	int left = 0;
	int right = size - 1;
	while (left <= right) {
		int middle = (left + right) / 2;
		if (arr[middle] > setpoint) right = middle - 1;
		else if (arr[middle] <= setpoint) left = middle + 1;


	}
	return size - left;
}