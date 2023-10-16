#pragma once

template <typename T>
// ReSharper disable once CppInconsistentNaming
class Stack
{
public:
    Stack();
    ~Stack();
    void push(const T& value);
    void pop();
    [[nodiscard]] T& top() const;
    [[nodiscard]] bool empty() const;
    [[nodiscard]] size_t size() const;
private:
    struct node
    {
        T data;
        node* next;
    };

    node* top_node_;
};