#include <iostream>
#include "windows.h"
#include <algorithm>
void quick_sort(int* arr, int size) {
    
    int i = 0;
    int j = size - 1;

    
    int mid = arr[size / 2];

    
    do {
        
        while (arr[i] < mid) {
            i++;
        }
       
        while (arr[j] > mid) {
            j--;
        }

       
        if (i <= j) {
            std::swap(arr[i], arr[j]);

            i++;
            j--;
        }
    } while (i <= j);


   
    if (j > 0) {
        
       quick_sort(arr, j + 1);
    }
    if (i < size) {
        
        quick_sort(arr+i, size - i);
    }
}

void arr_display(int* arr, int size) {
	for (int i = 0; i < size; i++) {
		std::cout << arr[i] << " ";
		if (i == size - 1) std::cout << std::endl;
	}
}

int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	int arr[10] = { 3, 43, 38, 29, 18, 72, 57, 61, 2, 33 };
	int size = sizeof(arr) / sizeof(arr[0]);
	std::cout << "Исходный массив: ";
	arr_display(arr, size);
	quick_sort(arr, size);
	std::cout << "Отсортированный массив: ";
	arr_display(arr, size);

	return 0;
}