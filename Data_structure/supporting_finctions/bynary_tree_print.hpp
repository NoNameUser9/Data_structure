#pragma once
#include <iostream>
#include <windows.h>
#include "../list/forward_list.hpp"
#include "typedef.h"
constexpr int shift_y = 1;
constexpr int shift_x = 10;
template<class T>
void print_supporter(T* arr, COORD pos, HANDLE hConsole, const size_t size)
{
    if(size > 0)
    {
        if (arr[size - 1] < arr[size - 2])
        {
            SetConsoleCursorPosition(hConsole, pos);
            Sleep(100);
            std::cout << arr[size - 1];
            Sleep(100);
            pos.Y += shift_y;
            pos.X += shift_x;
            print_supporter(arr, pos, hConsole, size - 1);
        }
        else
        {
            SetConsoleCursorPosition(hConsole, pos);
            Sleep(100);
            std::cout << arr[size - 1];
            Sleep(100);
            pos.Y += shift_y;
            pos.X -= shift_x;
            print_supporter(arr, pos, hConsole, size - 1);
        }
        
    }
            
    
}
template<class T>
void binary_tree_print(NNU9::list<my_type> list)
{
    auto arr = new T[list.size()];
    size_t i = 0;
    for (auto it = list.begin(); it != list.end(); ++it)
        arr[i++] = it.ptr->data;

    
    
    COORD position{50, 0};
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hConsole, position);

    print_supporter(arr, position, hConsole, list.size());
    
}
