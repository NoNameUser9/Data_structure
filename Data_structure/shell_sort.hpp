#pragma once
#include "forward_list.hpp"
#include "swap.hpp"

template<class T>
void shell_sort(NNU9::list<T>& a, const bool& to_low)
{
    auto range = static_cast<double>(a.size());
    constexpr double factor = 1.2473309;
    
        auto temp = new T[a.size()];
        {
            int i = 0;
            for(auto it = a.begin(); it != a.end(); ++it, ++i)
                temp[i] = it.ptr->data;
        }
        
        while(true)
        {
            for(size_t i = 0, j = range - 1; j < a.size() && j > i; ++i, ++j)
            {
                if(temp[i] > temp[j])
                    NNU9::swap(temp[i], temp[j]);
            }

            if(range <= 2)
            {
                auto size = a.size();
                a.clear();
                
                for(size_t i = 0; i < size; ++i)
                    a.push_front(temp[size - i - 1]);
                break;
            }
        
            range /= factor;
        }
        delete[] temp;
    
    
    // if(to_low == true)
    //     tolow(a, a.size());
}