#include "queue.hpp"
#include <iostream>

template queue<int>;
template queue<float>;
template queue<char>;
template queue<bool>;
template queue<std::string>;

template <class T>
queue<T>::queue(): front_(nullptr), back_(nullptr), size_(0){}

template <class T>
queue<T>::~queue()
{
    while (!empty())
        dequeue();
}

template <class T>
bool queue<T>::empty()
{
    return front_ == nullptr;
}

template <class T>
uint32_t queue<T>::size() const
{
    return size_;
}

template <class T>
void queue<T>::enqueue(T value)
{
    node* new_node = new node;
    new_node->data = value;
    new_node->next = nullptr;
        
    if (empty())
        front_ = back_ = new_node;
    else
    {
        back_->next = new_node;
        back_ = new_node;
    }
    ++size_;
    std::cout << "Element " << value << " enqueued successfully." << std::endl;
}

template <class T>
void queue<T>::dequeue()
{
    if (empty())
        std::cout << "Queue is empty. Cannot dequeue." << std::endl;
    else
    {
        node* temp = front_;
        front_ = front_->next;
        std::cout << "Element " << temp->data << " dequeued successfully." << std::endl;
        delete temp;
    }
    --size_;
}

template <class T>
T queue<T>::get_front()
{
    if (empty())
        throw std::runtime_error("Queue is empty!");

    return front_->data;
}