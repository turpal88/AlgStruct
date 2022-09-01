#include <iostream>
#include "windows.h"

int fibonacci(int n) {
	
	while (n > 1) {
		return fibonacci(n - 1) + fibonacci(n - 2);
	}
	if (n == 1) return 1;
	if (n == 0) return 0;
	
	
}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int n = 0;
	std::cout << "Введите число: ";
	std::cin >> n;
	int* arr = new int[n+1];
	std::cout << "Последовательность Фибоначчи для числа " << n << " = ";
	for (int i = 0; i < n + 1; i++) {
		arr[i] = fibonacci(i);
		if (i == 0) std::cout << "{";
		std::cout << arr[i];
		if (i >= 0 && i < n) std::cout << " ";
		if (i == n) std::cout << "}";
	}
	std::cout << std::endl;
	delete[] arr;

	return 0;
}