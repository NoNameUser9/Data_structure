#include "shell_sort.hpp"
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
    list<T, Allocator>::list(): front_(new node), back_(front_), size_(0)
    {
        front_->next = nullptr;
    }

    template <class T, class Allocator>
    list<T, Allocator>::~list()
    {
        delete[] front_;
    }

    template <class T, class Allocator>
    void list<T, Allocator>::push_front(const_ref value)
    {
        auto new_node = new node;
        new_node->data = value;
   
        if(front_ != nullptr)
            new_node->next = front_;
        
        front_ = new_node;
        ++size_;
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
    typename list<T, Allocator>::iterator list<T, Allocator>::begin()
    {
        iterator ret(front_);
        return ret;
    }

    template <class T, class Allocator>
    typename list<T, Allocator>::iterator list<T, Allocator>::end()
    {
        iterator ret(back_);
        return ret;
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
    void list<T, Allocator>::insert_after(const T& value, const size_t& index)
    {
        node* new_node = new node(value);

        if (index == 0)
        {
            front_->next = new_node;
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
    void list<T, Allocator>::sort()
    {
        shell_sort(*this, 0);
    }

    template <class T, class Allocator>
    void list<T, Allocator>::unique()
    {
        
    }

    template <class T, class Allocator>
    void list<T, Allocator>::merge(list& list)
    {
        for (auto it = list.begin(); it != list.end(); ++it)
            push_front(it.ptr->data);
    }

    template <class T, class Allocator>
    void list<T, Allocator>::clear()
    {
        while (!empty())
            pop_front();

        size_ = 0;
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

    template <class T, class Allocator>
    list<T, Allocator>::iterator::iterator(): ptr(nullptr), front_(nullptr), back_(nullptr), pos_now_(0)
    {}

    template <class T, class Allocator>
    list<T, Allocator>::iterator::iterator(auto begin): ptr(begin), front_(begin), pos_now_(0)
    {
        node* temp = front_;
        while (temp->next != nullptr)
            temp = temp->next;

        back_ = temp;
    }

    template <class T, class Allocator>
    bool list<T, Allocator>::iterator::operator==(const iterator& right) const
    {
        return ptr == right.ptr;
    }

    template <class T, class Allocator>
    // ReSharper disable once CppNotAllPathsReturnValue
    typename list<T, Allocator>::ref list<T, Allocator>::iterator::operator*()
    {
        try
        {
            if(ptr == nullptr)
                throw std::runtime_error("\nOut of range!\n");
                    
            return ptr->data;
        }
        catch (std::runtime_error& ex)
        {
            std::cerr << ex.what();
        }
    }

    template <class T, class Allocator>
    // ReSharper disable once CppNotAllPathsReturnValue
    typename list<T, Allocator>::iterator& list<T, Allocator>::iterator::operator++()
    {
        try
        {
            if(ptr->next == nullptr)
                throw std::runtime_error("\nOut of range!(operator++ preincrement)\n");

            ++pos_now_;
            ptr = ptr->next;
            return *this;
        }
        catch (std::runtime_error& ex)
        {
            std::cerr << ex.what();
        }
    }

    template <class T, class Allocator>
    // ReSharper disable once CppNotAllPathsReturnValue
    typename list<T, Allocator>::iterator list<T, Allocator>::iterator::operator++(int)
    {
        try
        {
            if(ptr->next == nullptr)
                throw std::runtime_error("\nOut of range!(operator++ postincrement)\n");
                    
            auto old = *this;
            ++ptr;
            return old;
        }
        catch (std::runtime_error& ex)
        {
            std::cerr << ex.what();
        }
    }
}
