
#include "windows.h"
#include <iostream>
#include "error_exception.h"
void print_dynamic_array(int* arr, int logical_size, int actual_size) {
    std::cout << "������������ ������: ";
    for (int i = 0; i < logical_size; i++) {
        std::cout << arr[i] << " ";
    }
    for (int i = logical_size; i < actual_size; i++) {
        std::cout << '_' << " ";
    }
}



int main() 
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    
    int fact_size = 0, actual_size = 0;
    
    try {
        std::cout << "������� �������c��� ������ �������: ";
        std::cin >> fact_size;
        std::cout << "������� ���������� ������ �������: ";
        std::cin >> actual_size;
        if (actual_size >= fact_size) throw error_exception("������! ���������� ������ ������� �� ����� ��������� �����������!");
    }

    catch (error_exception& e) {
        std::cout << e.what() << std::endl;
        return -1;
    }
   
    int* arr = new int[fact_size];

    for (int i = 0; i < actual_size; i++) {
        std::cout << "������� arr" << "[" << i << "]: ";
        std::cin >> arr[i];
    }
    print_dynamic_array(arr, actual_size, fact_size);
    delete[] arr;
    return 0;
}


