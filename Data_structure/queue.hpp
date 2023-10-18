#pragma once
#include <cstdint>

template<class T>
class queue  // NOLINT(cppcoreguidelines-special-member-functions)
{
public:
    queue();
    ~queue();
    bool empty();
    [[nodiscard]] uint32_t size() const;
    void enqueue(T value);
    void dequeue();
    T get_front();
private:
    struct node
    {
        T data;
        node* next;
    };
    node* front_;
    node* back_;
    uint32_t size_;
};