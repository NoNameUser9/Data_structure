#pragma once
#include "deque.hpp"

namespace NNU9
{
    template <typename T, class Container = deque<T>>
    class stack  // NOLINT(cppcoreguidelines-special-member-functions)
    {
    public:
        stack();
        ~stack();
        void push(const T& value);
        void pop();
        template<typename... Args>
        void emplace(Args&&... args);
        [[nodiscard]] T top();
        [[nodiscard]] bool empty() const;
        [[nodiscard]] size_t size() const;
    private:
        Container container_;
    };
}