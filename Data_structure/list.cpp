#include "list.hpp"
#include <iostream>
#include <string>

template list<int>;
template list<float>;
template list<char>;
template list<bool>;
template list<std::string>;

template <class T>
list<T>::list(): head_(nullptr), size_(0){}

template <class T>
list<T>::~list()
{
    while (head_ != nullptr)
        pop_front();
}

template <class T>
void list<T>::push_front(T value)
{
    node* new_node = new node;
    new_node->data = value;
    new_node->next = head_;
    head_ = new_node;
}

template <class T>
void list<T>::pop_front()
{
    if (head_ == nullptr) {
        std::cout << "Список пуст!" << std::endl;
        return;
    }
    const node* temp = head_;
    head_ = head_->next;
    delete temp;
}

template <class T>
void list<T>::print_list()
{
    node* current = head_;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

template <class T>
bool list<T>::empty() const
{
    return size_ == 0;
}

template <class T>
uint32_t list<T>::size() const
{
    return size_;
}