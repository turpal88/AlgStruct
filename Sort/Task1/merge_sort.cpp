
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


/*
// C++ program for Merge Sort
#include <iostream>
using namespace std;

// Merges two subarrays of array[].
// First subarray is arr[begin..mid]
// Second subarray is arr[mid+1..end]
void merge(int array[], int const left, int const mid,
    int const right)
{
    auto const subArrayOne = mid - left + 1;
    auto const subArrayTwo = right - mid;

    // Create temp arrays
    auto* leftArray = new int[subArrayOne],
        * rightArray = new int[subArrayTwo];

    // Copy data to temp arrays leftArray[] and rightArray[]
    for (auto i = 0; i < subArrayOne; i++)
        leftArray[i] = array[left + i];
    for (auto j = 0; j < subArrayTwo; j++)
        rightArray[j] = array[mid + 1 + j];

    auto indexOfSubArrayOne
        = 0, // Initial index of first sub-array
        indexOfSubArrayTwo
        = 0; // Initial index of second sub-array
    int indexOfMergedArray
        = left; // Initial index of merged array

    // Merge the temp arrays back into array[left..right]
    while (indexOfSubArrayOne < subArrayOne
        && indexOfSubArrayTwo < subArrayTwo) {
        if (leftArray[indexOfSubArrayOne]
            <= rightArray[indexOfSubArrayTwo]) {
            array[indexOfMergedArray]
                = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
        }
        else {
            array[indexOfMergedArray]
                = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
        }
        indexOfMergedArray++;
    }
    // Copy the remaining elements of
    // left[], if there are any
    while (indexOfSubArrayOne < subArrayOne) {
        array[indexOfMergedArray]
            = leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }
    // Copy the remaining elements of
    // right[], if there are any
    while (indexOfSubArrayTwo < subArrayTwo) {
        array[indexOfMergedArray]
            = rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }
    delete[] leftArray;
    delete[] rightArray;
}

// begin is for left index and end is
// right index of the sub-array
// of arr to be sorted
void mergeSort(int array[], int const begin, int const end)
{
    if (begin >= end)
        return; // Returns recursively

    auto mid = begin + (end - begin) / 2;
    mergeSort(array, begin, mid);
    mergeSort(array, mid + 1, end);
    merge(array, begin, mid, end);
}

// UTILITY FUNCTIONS
// Function to print an array
void printArray(int A[], int size)
{
    for (auto i = 0; i < size; i++)
        cout << A[i] << " ";
}

// Driver code
int main()
{
    int arr[] = { 12, 11, 13, 5, 6, 7 };
    auto arr_size = sizeof(arr) / sizeof(arr[0]);

    cout << "Given array is \n";
    printArray(arr, arr_size);

    mergeSort(arr, 0, arr_size - 1);

    cout << "\nSorted array is \n";
    printArray(arr, arr_size);
    return 0;
}

// This code is contributed by Mayank Tyagi
// This code was revised by Joshua Estes
*/