
#include "windows.h"
#include <iostream>

void merge(int* arr1, int size_arr1, int* arr2, int size_arr2, int* final_arr) {
    
    int arr1_index = 0;
    int arr2_index = 0;
    int final_arr_index = 0;

    while (arr1_index < size_arr1 && arr2_index < size_arr2) {
        if (arr1[arr1_index] <= arr2[arr2_index]) {
            final_arr[final_arr_index] = arr1[arr1_index];
            arr1_index++;
        }
        else {
            final_arr[final_arr_index] = arr2[arr2_index];
            arr2_index++;
        }
        final_arr_index++;
    }

    while (arr1_index < size_arr1) {
        final_arr[final_arr_index] = arr1[arr1_index];
        arr1_index++;
        final_arr_index++;
    }

    while (arr2_index < size_arr2) {
        final_arr[final_arr_index] = arr2[arr2_index];
        arr2_index++;
        final_arr_index++;
    }

    
}                                                                   
void merge_sort(int* arr, int size) {                      
    
    if (size < 2) return;
    
    int mid = size / 2;
    
   
    int left_size = mid;
    int right_size = size - mid;
    int* left = new int[left_size];
    int* right = new int[right_size];
   
    for (int i = 0; i < mid; i++) {
        left[i] = arr[i];
    }

    for (int i = mid; i < size; i++) {
        right[i-mid] = arr[i];
    }

    merge_sort(left, left_size);
    merge_sort(right, right_size);
    merge(left, left_size, right, right_size, arr);
   

    delete[] left;
    delete[] right;
  

}

void arr_display(int* arr, int size) {
    
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
        if (i == size - 1) std::cout << std::endl;
    }
}
int main() 
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int arr1[10] = {3, 43, 38, 29, 18, 72, 57, 61, 2, 33};
    int size = sizeof(arr1) / sizeof(arr1[0]);
    std::cout << "Исходный массив: ";
    arr_display(arr1, size);
    merge_sort(arr1, size);
    std::cout << "Отсортированный массив: ";
    arr_display(arr1, size);
   
    return 0;
}


