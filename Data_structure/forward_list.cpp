#include "forward_list.hpp"
#include <iostream>

namespace NNU9
{
    template list<int>;
    template list<float>;
    template list<char>;
    template list<bool>;
    template list<std::string>;
    
    template <class T, class Allocator>
    list<T, Allocator>::list(): front_(nullptr), back_(nullptr), size_(0) {}

    template <class T, class Allocator>
    list<T, Allocator>::~list() {}

    template <class T, class Allocator>
    void list<T, Allocator>::push_front(const_ref value)
    {
        auto new_node = new node;
        new_node->data = value;
        new_node->next = front_;
        front_ = new_node;
    }

    template <class T, class Allocator>
    void list<T, Allocator>::pop_front()
    {
        try
        {
            if(empty())
                throw std::runtime_error("\nList is empty!\n");
            
            front_ = front_->next;
            --size_;
        }
        catch (std::runtime_error& ex)
        {
            std::cerr << ex.what();
        }
    }

    template <class T, class Allocator>
    T list<T, Allocator>::begin()
    {
        return 0;
    }

    template <class T, class Allocator>
    typename list<T, Allocator>::ref list<T, Allocator>::front()
    {
        return front_->data;
    }

    template <class T, class Allocator>
    typename list<T, Allocator>::ref list<T, Allocator>::back()
    {
        return back_->data;
    }

    template <class T, class Allocator>
    void list<T, Allocator>::insert(const T& value, const size_t& index)
    {
        node* new_node = new node(value);

        if (index == 0)
        {
            new_node->next = front_;
            front_ = new_node;
            return;
        }

        node* current = front_;
        int count = 0;

        while (current != nullptr && count < index - 1)
        {
            current = current->next;
            count++;
        }

        if (current == nullptr)
        {
            std::cout << "Invalid index!" << std::endl;
            return;
        }

        new_node->next = current->next;
        current->next = new_node;
    }

    template <class T, class Allocator>
    void list<T, Allocator>::print_list()
    {
        try
        {
            if(empty())
                throw std::runtime_error("\nList is empty!\n");
            
            auto temp_node = new node;
            temp_node = front_;
            
            while (temp_node->next != nullptr)
            {
                std::cout << temp_node->data;
                temp_node = temp_node->next;
            }
        }
        catch (std::runtime_error& ex)
        {
            std::cerr << ex.what();
        }
        
    }

    template <class T, class Allocator>
    void list<T, Allocator>::clear()
    {
        while (!empty())
            pop_front();
    }

    template <class T, class Allocator>
    bool list<T, Allocator>::empty() const
    {
        return size_ == 0;
    }

    template <class T, class Allocator>
    size_t list<T, Allocator>::size() const
    {
        return size_;
    }
}