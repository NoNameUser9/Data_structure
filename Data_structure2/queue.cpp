#include "queue.hpp"
#include <iostream>

template queue<int>;
template queue<float>;
template queue<char>;
template queue<bool>;
template queue<std::string>;

template <class T>
queue<T>::queue(): front_(nullptr), size_(0) {}

template <class T>
queue<T>::~queue() {}

template <class T>
bool queue<T>::empty() const
{
    return size_ == 0;
}

template <class T>
size_t queue<T>::size() const
{
    return size_;
}

template <class T>
void queue<T>::push(const T& value)
{
    node* new_node = new node;
    new_node->data = value;
    new_node->next = nullptr;

    if (empty())
        front_ = new_node;
    else
        front_[size_ - 1].next = new_node;
    
    size_++;
}

template <class T>
void queue<T>::pop()
{
    try
    {
        if(empty())
            throw std::runtime_error("\nQueue is empty!\n");

        if (front_[0].next == nullptr)
            front_ = nullptr;
        else
            front_[size_ - 2].next = nullptr;
        
        size_--;
    }
    catch (const std::runtime_error& ex)
    {
        std::cerr << ex.what();
    }
}

template <class T>
T queue<T>::front()
{
    try
    {
        if (empty())
            throw std::runtime_error("\nQueue is empty!\n");
        return front_->data;
    }
    catch (std::runtime_error& ex)
    {
        std::cerr << ex.what();
    }
    return {};
}

template <class T>
T queue<T>::back()
{
    try
    {
        if (empty())
            throw std::runtime_error("\nQueue is empty!\n");
        return front_[size_ - 1].data;
    }
    catch (std::runtime_error& ex)
    {
        std::cerr << ex.what();
    }
    return {};
}
