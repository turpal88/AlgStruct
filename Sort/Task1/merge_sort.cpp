
#include "windows.h"
#include <iostream>

int* merge(int* A, int size_A, int* B, int size_B) {
    
    
    int* final_arr = new int[size_A + size_B];

    int ia = 0, ib = 0, ic = 0;
    while (ia < size_A || ib < size_B) {
        if (ia == size_A)
            final_arr[ic++] = B[ib++];           
        else if (ib == size_B)
            final_arr[ic++] = A[ia++];             
                                            
        else if (A[ia] <= B[ib])              
            final_arr[ic++] = A[ia++];            
        else                                 
                                               
                                              
            final_arr[ic++] = B[ib++];                                     
    }                                                              
                                                                     
    
    return final_arr;
}                                                                   
int* merge_sort(int* arr, int size) {                      
    
    if (size == 1) return arr;
    
    int mid = size / 2;
    
   
    int left_size = mid + 1;
    int right_size = size - mid;
    int* left = new int[left_size];
    int* right = new int[right_size];
    int* left_sorted;
    int* right_sorted;
    for (int i = 0; i < mid + 1; i++) {
        left[i] = arr[i];
    }

    for (int i = 0, k = mid + 1; i < mid + 1, k < size + 1; i++, k++) {
        right[i] = arr[k];
    }

    left_sorted = merge_sort(left, left_size-1);
    right_sorted = merge_sort(right, right_size-1);
    return merge(left_sorted, left_size, right_sorted, right_size);

    delete[] left;
    delete[] right;
    delete[] left_sorted;
    delete[] right_sorted;

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
    arr_display(arr1, size);
    int* final_arr = new int[size];
    final_arr = merge_sort(arr1, size-1);
    arr_display(final_arr, size);
    delete[] final_arr;
    return 0;
}
