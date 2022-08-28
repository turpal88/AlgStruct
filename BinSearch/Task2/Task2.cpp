#include <iostream>
#include "windows.h"
#include "bin_sort.h"
int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int arr[9] = {14, 16, 19, 32, 32, 32, 56, 69, 72};
	int size = sizeof(arr) / sizeof(arr[0]);
	int setpoint = 0;
	std::cout << "Введите точку отсчета: ";
	std::cin >> setpoint;

	std::cout << "Количество элементов в массиве больших, чем " << setpoint << ": " << BinSort(arr, size, setpoint) << std::endl;

	return 0;
}