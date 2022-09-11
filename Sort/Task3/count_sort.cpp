#include <iostream>
#include "windows.h"

void count_sort(int* arr, int size) {
	int counts[25] = {0};
	
	for (int i = 0; i < size; i++) {
		counts[arr[i]]++;
	}
	int c = 0;
	for (int i = 0; i < 25; i++) {
		while (counts[i] != 0) {
			arr[c] = i;
			c++;
			counts[i]--;
		}
		
	}
	
	
}

void print_arr(int* arr, int size) {
	for (int i = 0; i < size; i++) {
		std::cout << arr[i] << " ";
		if (i == size - 1) std::cout << std::endl;
	}
}
int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	int arr[30] = {19, 14, 22, 22, 17, 22, 13, 21, 20, 24, 18, 10, 17, 16, 17, 20, 22, 11, 20, 16, 14, 13, 10, 22, 18, 14, 16, 24, 19, 17};
	int size = sizeof(arr) / sizeof(arr[0]);
	std::cout << "Исходный массив: ";
	print_arr(arr, size);
	count_sort(arr, size);
	std::cout << "Отсортированный массив: ";
	print_arr(arr, size);
	return 0;
}