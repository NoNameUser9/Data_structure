#pragma once
#include <cstdint>

template<class T>
class list  // NOLINT(cppcoreguidelines-special-member-functions)
{
public:
    list();
    ~list();
    void push_front(T value);
    void pop_front();
    void insert(T value, uint16_t num);
    void print_list();
    [[nodiscard]] bool empty() const;
    [[nodiscard]] uint32_t size() const;
private:
    struct node
    {
        T data;
        node* next;
    };
    node* head_;
    uint32_t size_;
};