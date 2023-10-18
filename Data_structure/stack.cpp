#include "stack.hpp"
#include <stdexcept>

template stack<int>;
template stack<float>;
template stack<char>;
template stack<bool>;
template stack<std::string>;

template <class T>
stack<T>::stack(): head_(nullptr){}

template <typename T>
stack<T>::~stack()
{
    while (!empty())
        pop();
}

template <typename T>
void stack<T>::push(const T& value)
{
    node* new_node = new node(value, head_);
    head_ = new_node;
}

template <typename T>
void stack<T>::pop()
{
    if (!empty())
        head_ = head_->next;
}

template <typename T>
T& stack<T>::top() const
{
    if (!empty())
        return head_->data;
    throw std::runtime_error("Stack is empty");
}

template <typename T>
bool stack<T>::empty() const
{
    return head_ == nullptr;
}

template <typename T>
uint32_t stack<T>::size() const
{
    size_t count = 0;
    node* current = head_;
    while (current != nullptr)
    {
        count++;
        current = current->next;
    }
    return count;
}