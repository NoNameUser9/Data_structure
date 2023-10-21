#pragma once
#include "deque.hpp"
namespace NNU9
{
    template<class T, class Container = deque<T>>
    class queue  // NOLINT(cppcoreguidelines-special-member-functions)
    {
    public:
        queue();
        ~queue();
        [[nodiscard]] bool empty() const;
        [[nodiscard]] size_t size() const;
        void push(const T& value);
        void pop();
        T front();
        T back();
    private:
        Container container_;
    };
}