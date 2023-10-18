#pragma once
#include <cstdint>

template <typename T>
class stack  // NOLINT(cppcoreguidelines-special-member-functions)
{
public:
    stack();
    ~stack();
    void push(const T& value);
    void pop();
    [[nodiscard]] T& top() const;
    [[nodiscard]] bool empty() const;
    [[nodiscard]] uint32_t size() const;
private:
    struct node
    {
        T data;
        node* next;
    };

    node* head_;
};