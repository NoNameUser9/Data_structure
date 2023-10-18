#include "deque.hpp"
#include <iostream>
#include <string>

template deque<int>;
template deque<float>;
template deque<char>;
template deque<bool>;
template deque<std::string>;

template <typename T>
deque<T>::deque(): front_(nullptr), back_(nullptr), size_(0){}

template <typename T>
deque<T>::~deque()
{
    while (!empty())
        pop_front();
}

template <typename T>
bool deque<T>::empty() const
{
    return size_ == 0;
}

template <typename T>
uint32_t deque<T>::get_size() const
{
    return size_;
}

template <typename T>
void deque<T>::push_front(const T& value)
{
    node* new_node = new node;
    new_node->data = value;
    new_node->prev = nullptr;
    new_node->next = front_;

    if (empty())
        back_ = new_node;
    else
        front_->prev = new_node;

    front_ = new_node;
    size_++;
}

template <typename T>
void deque<T>::push_back(const T& value)
{
    node* new_node = new node;
    new_node->data = value;
    new_node->prev = back_;
    new_node->next = nullptr;

    if (empty())
        front_ = new_node;
    else
        back_->next = new_node;
    
    back_ = new_node;
    size_++;
}

template <typename T>
void deque<T>::pop_front()
{
    if (empty())
    {
        std::cout << "Deque is empty!" << std::endl;
        return;
    }

    const node* temp = front_;
    front_ = front_->next;

    if (front_ == nullptr)
        back_ = nullptr;
    else
        front_->prev = nullptr;

    delete temp;
    size_--;
}

template <typename T>
void deque<T>::pop_back()
{
    if (empty())
    {
        std::cout << "Deque is empty!" << std::endl;
        return;
    }

    const node* temp = back_;
    back_ = back_->prev;

    if (back_ == nullptr)
        front_ = nullptr;
    else
        back_->next = nullptr;

    delete temp;
    size_--;
}

template <typename T>
const T& deque<T>::get_front() const
{
    if (empty())
        throw std::runtime_error("Deque is empty!");
    return front_->data;
}

template <typename T>
const T& deque<T>::get_back() const
{
    if (empty())
        throw std::runtime_error("Deque is empty!");
    return back_->data;
}