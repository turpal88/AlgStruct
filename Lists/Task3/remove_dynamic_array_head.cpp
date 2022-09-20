
#include "windows.h"
#include <iostream>
#include "error_exception.h"
void print_dynamic_array(int* arr, int logical_size, int actual_size) {
    
    for (int i = 0; i < logical_size; i++) {
        std::cout << arr[i] << " ";
        if(logical_size == actual_size && i == logical_size - 1) std::cout << std::endl;
    }
    for (int i = logical_size; i < actual_size; i++) {
        std::cout << '_' << " ";
        if (i == actual_size - 1) std::cout << std::endl;
    }
    
}
int* append_to_dynamic_array(int* new_arr, int& fact_size, int& actual_size, int added_element) {
    if (actual_size < fact_size) {
        new_arr[actual_size] = added_element;
        actual_size++;
        return new_arr;
    }
    else if(actual_size == fact_size) {
        fact_size *= 2;
        int* newnew_arr = new int[fact_size];
        for (int i = 0; i < actual_size; i++) {
            newnew_arr[i] = new_arr[i];
        }
        newnew_arr[actual_size] = added_element;
        actual_size++;
        delete[] new_arr;
        return newnew_arr;
        
        
        
    }
}
int* remove_dynamic_array_head(int* new_arr, int& fact_size, int& actual_size) {
    if (actual_size - 1 > fact_size / 3) {
        
        for (int i = 1; i < actual_size; i++) {
            new_arr[i - 1] = new_arr[i];
        }
        actual_size--;
        return new_arr;
    }
    else {
        fact_size /= 3;
        
        int* newnew_arr = new int[fact_size];
        for (int i = 1; i < actual_size; i++) {
            newnew_arr[i-1] = new_arr[i];
        }
        actual_size--;
        delete[] new_arr;
        return newnew_arr;
    }
}

int main() 
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    
    int fact_size = 0, actual_size = 0;
    std::string answer = " ";
    try {
        std::cout << "Введите фактичеcкий размер массива: ";
        std::cin >> fact_size;
        std::cout << "Введите логический размер массива: ";
        std::cin >> actual_size;
        if (actual_size >= fact_size) throw error_exception("Ошибка! Логический размер массива не может превышать фактический!");
    }

    catch (error_exception& e) {
        std::cout << e.what() << std::endl;
        return -1;
    }
   
    int* arr = new int[fact_size];
    int* new_arr = arr;
    for (int i = 0; i < actual_size; i++) {
        std::cout << "Введите arr" << "[" << i << "]: ";
        std::cin >> arr[i];
    }
    std::cout << "Динамический массив: ";
    print_dynamic_array(arr, actual_size, fact_size);
    while (true) {
        std::cout << "Удалить первый элемент? ";
        std::cin >> answer;
        if (answer == "да") {
            if (fact_size == 0) break;
            new_arr = remove_dynamic_array_head(new_arr, fact_size, actual_size);
            std::cout << "Динамический массив: ";
            print_dynamic_array(new_arr, actual_size, fact_size);
            std::cout << "actual_size = " << actual_size << std::endl;
            std::cout << "fact_size = " << fact_size << std::endl;
        }
        else break;
        //std::cin >> added_element;
        //new_arr = append_to_dynamic_array(new_arr, fact_size, actual_size, added_element);
       
    }
    if (fact_size > 0 && answer == "нет") {
        std::cout << "Спасибо! Ваш массив: ";
        print_dynamic_array(new_arr, actual_size, fact_size);
    }
    else std::cout << "Невозможно удалить первый элемент, так как массив пустой. До свидания!" << std::endl;
    delete[] arr;
    delete[] new_arr;
    return 0;
}


