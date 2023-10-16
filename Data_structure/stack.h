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

template <typename T>
Stack<T>::Stack(): top_node_(nullptr){}

template <typename T>
Stack<T>::~Stack()
{
    while (!empty())
        pop();
}

template <typename T>
void Stack<T>::push(const T& value)
{
    node* new_node = new node(value, top_node_);
    top_node_ = new_node;
}

template <typename T>
void Stack<T>::pop()
{
    if (!empty())
        top_node_ = top_node_->next;
}

template <typename T>
T& Stack<T>::top() const
{
    if (!empty())
        return top_node_->data;
    throw std::runtime_error("Stack is empty");
}

template <typename T>
bool Stack<T>::empty() const
{
    return top_node_ == nullptr;
}

template <typename T>
size_t Stack<T>::size() const
{
    size_t count = 0;
    node* current = top_node_;
    while (current != nullptr)
    {
        count++;
        current = current->next;
    }
    return count;
}