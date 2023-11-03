#pragma once
#include <iostream>
#include <windows.h>
#include "../list/forward_list.hpp"
#include "typedef.h"
#include "bynary_tree_print.hpp"
#include "../binary_tree.h"

constexpr short shift_y = 1;
constexpr short shift_x = 10;
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

inline short y_shift = 10;
inline short x_shift = 10;
bool is_left = false;
template<class T>
void printTreeUtil(Node<T>* node, const short level, COORD& position, HANDLE hConsole, bool is_left)
{
    if (node == nullptr)
        return;
    
    // position.Y += shift_y;
    // is_left = true;
    // is_left = false;
    position.X = shift_x*level + shift_x*2*!is_left;
    printTreeUtil(node->right, level + 1, position, hConsole, false);
    position.Y = shift_y*level*2+shift_y*is_left;
        
    SetConsoleCursorPosition(hConsole, position);
    // Sleep(500);
    std::cout << node->data;
    // std::cout << "a";
    Sleep(500);
    is_left = true;
    printTreeUtil(node->left, level + 1, position, hConsole, true);
    // pos.Y += shift_y;
    // pos.X += shift_x;
    // print_supporter(arr, pos, hConsole, size - 1);
    // for (size_t i = 0; i < level; ++i)
        // std::cout << "    ";
    // SetConsoleCursorPosition(hConsole, position);
    
    

}
template<class T>
void printBinaryTree(Node<T>* root)
{
    COORD position{0, 0};
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    
    printTreeUtil(root, 0, position, hConsole, false);
    // position.Y = 150 ;
    SetConsoleCursorPosition(hConsole, position);
    std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n";
}
template<class T>
void binary_tree_print(BinaryTree<T>& tree)
{
    auto arr = new T[tree.size()][tree.size()];
    size_t i = 0;
    // tree.
    for (auto it = tree.begin(); it != tree.end(); ++it)
        arr[i++] = it.ptr->data;

    
    
    COORD position{80, 0};
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hConsole, position);

    // print_supporter(arr, position, hConsole, list.size());
    
}
