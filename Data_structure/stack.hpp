#pragma once
#include <cstdint>

// #include "deque.hpp"
#include "queue.hpp"

template <typename T, class Container = queue<T>>
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
