﻿#pragma once
#include "list/forward_list.hpp"

template<class T>
size_t binary_search(NNU9::list<T>& list, T find)
{
    auto size = list.size();
    size_t begin = 0, end = size, i = size / 2;
    while (list[i] != find && static_cast<double>(end) - static_cast<double>(begin) > 1.5)
    {
        if(find < list[i])
        {
            end = (end - begin) / 2 + begin;
            i = begin + (end - begin) / 2;
        }
        else if(find > list[i])
        {
            begin += (end - begin) / 2;
            i = begin + (end - begin) / 2;
        }
    }
    if(find == list[i])
        return i;
    
    throw std::runtime_error("\nObject not found\n");
}
