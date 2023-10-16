#include "queue.h"
#include <iostream>

template Queue<int>;
template Queue<float>;
template Queue<char>;
template Queue<bool>;
template Queue<std::string>;

template <class T>
Queue<T>::Queue()
{
    front_ = nullptr;
    rear_ = nullptr;
}

template <class T>
Queue<T>::~Queue()
{
    while (!empty())
        dequeue();
}

template <class T>
bool Queue<T>::empty()
{
    return front_ == nullptr;
}

template <class T>
void Queue<T>::enqueue(T value)
{
    node* new_node = new node;
    new_node->data = value;
    new_node->next = nullptr;
        
    if (empty())
        front_ = rear_ = new_node;
    else
    {
        rear_->next = new_node;
        rear_ = new_node;
    }

    std::cout << "Element " << value << " enqueued successfully." << std::endl;
}

template <class T>
void Queue<T>::dequeue()
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
}

template <class T>
T Queue<T>::get_front()
{
    if (empty())
        throw std::runtime_error("Queue is empty!");

    return front_->data;
}