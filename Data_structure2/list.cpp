#include "list.hpp"
#include <iostream>

template list<int>;
template list<float>;
template list<char>;
template list<bool>;
template list<std::string>;

template <class T, class Container>
list<T, Container>::list() {}

template <class T, class Container>
list<T, Container>::~list() {}

template <class T, class Container>
void list<T, Container>::push_front(const T& value)
{
    container_.push_front(value);
}

template <class T, class Container>
void list<T, Container>::push_back(const T& value)
{
    container_.push_back(value);
}

template <class T, class Container>
void list<T, Container>::pop_front()
{
    try
    {
        if(container_.empty())
            throw std::runtime_error("\nList is empty!\n");
        container_.pop_front();
    }
    catch (std::runtime_error& ex)
    {
        std::cerr << ex.what();
    }
}

template <class T, class Container>
void list<T, Container>::pop_back()
{
    try
    {
        if(container_.empty())
            throw std::runtime_error("\nList is empty!\n");
        container_.pop_back();
    }
    catch (std::runtime_error& ex)
    {
        std::cerr << ex.what();
    }
}

template <class T, class Container>
void list<T, Container>::insert(const T& value, const size_t& size)
{
    container_.insert();
}

template <class T, class Container>
void list<T, Container>::print_list()
{
    // node* current = head_;
    // while (current != nullptr) {
    //     std::cout << current->data << " ";
    //     current = current->next;
    // }
    // std::cout << std::endl;
}

template <class T, class Container>
void list<T, Container>::clear()
{
    while (!empty())
        container_.pop_back();
}

template <class T, class Container>
bool list<T, Container>::empty() const
{
    return container_.empty();
}

template <class T, class Container>
size_t list<T, Container>::size() const
{
    return container_.size();
}