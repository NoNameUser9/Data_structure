#pragma once
#include "forward_list.hpp"
#include <cstdint>

namespace NNU9
{
    /**
     * \note Not yet implemented now!
     */
    class iterator
    {
    public:
        using ref = uint64_t&;

        iterator(const size_t size, const uint64_t pos_now, uint64_t* arr)
            : size_(size), pos_now_(pos_now), arr_(arr) {}

        [[nodiscard]] ref begin() const
        {
            return arr_[0];
        }

        [[nodiscard]] ref end() const
        {
            return arr_[size_ - 1];
        }
        iterator& operator=(const iterator&);
    private:
        size_t size_;
        uint64_t pos_now_;
        uint64_t* arr_;
    };
}
