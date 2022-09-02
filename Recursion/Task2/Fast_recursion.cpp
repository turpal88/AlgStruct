#include <iostream>
#include "windows.h"


int fibonacci(int n, int* arr) {
	
	while (n > 1) {
		if (arr[n - 1] >= 0 && arr[n - 2] >= 0) {
			arr[n] = arr[n - 1] + arr[n - 2];
			return arr[n];
		}
		else fibonacci(n - 1, arr);
		
		
		
	}
	if (n == 1) {
		arr[n] = 1;
		fibonacci(n - 1, arr);
	} 
	
	if (n == 0) {
		arr[n] = 0;
		return arr[n];
	}
	
	
}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int n = 0;
	std::cout << "Введите число: ";
	std::cin >> n;
	int* arr = new int[n+1];
	for (int i = 0; i < n + 1; i++) {
		arr[i] = -1;
	}
	
	fibonacci(n, arr);
	std::cout << "Последовательность Фибоначчи для числа " << n << " = ";
	for (int i = 0; i < n + 1; i++) {
		
		
		if (i == 0) std::cout << "{";
		std::cout << arr[i];
		if (i >= 0 && i < n) std::cout << " ";
		if (i == n) std::cout << "}";
	}
	std::cout << std::endl;
	delete[] arr;

	return 0;
}