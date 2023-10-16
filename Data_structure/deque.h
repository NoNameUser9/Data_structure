#pragma once
#include <cstdint>

template<typename T>
class Deque
{
public:
    Deque();
    ~Deque();
    [[nodiscard]] bool empty() const;
    [[nodiscard]] uint32_t get_size() const;
    void push_front(const T& value);
    void push_back(const T& value);
    void pop_front();
    void pop_back();
    [[nodiscard]] const T& get_front() const;
    [[nodiscard]] const T& get_back() const;
private:
    struct node
    {
        T data;
        node* prev;
        node* next;
    };

    node* front_;
    node* back_;
    uint32_t size_;
};