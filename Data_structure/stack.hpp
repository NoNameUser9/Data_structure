#pragma once
#include "deque.hpp"

namespace NNU9
{
    template <typename T, class Container = deque<T>>
    class stack  // NOLINT(cppcoreguidelines-special-member-functions)
    {
    public:
        using ref = T&;
        using const_ref = const T&;
        using const_size_t_ref = const size_t&;
        stack();
        ~stack();
        void push(const_ref value);
        void pop();
        [[nodiscard]] ref top();
        [[nodiscard]] const_ref top() const;
        [[nodiscard]] bool empty() const;
        [[nodiscard]] size_t size() const;
        void swap(Container& other) noexcept;
    private:
        Container container_;
    };
}