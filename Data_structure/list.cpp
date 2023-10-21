#include "list.hpp"
#include <iostream>
namespace NNU9
{
    template list<int>;
    template list<float>;
    template list<char>;
    template list<bool>;
    template list<std::string>;

    template <class T, class Container>
    list<T, Container>::list(): front_(nullptr), size_(0) {}

    template <class T, class Container>
    list<T, Container>::~list() {}

    template <class T, class Container>
    void list<T, Container>::push_front(const T& value)
    {
        node* new_node = new node;
        new_node->data = value;

        if (empty())
            new_node->next = nullptr;
        else
            new_node->next = front_;

        front_ = new_node;
        size_++;
        // container_.push_front(value);
    }

    template <class T, class Container>
    void list<T, Container>::push_back(const T& value)
    {
        node* new_node = new node;
        new_node->data = value;
        new_node->next = nullptr;

        if (empty())
            front_ = new_node;
        else
            front_[size_ - 1].next = new_node;

        ++size_;
    }

    template <class T, class Container>
    void list<T, Container>::pop_front()
    {
        try
        {
            if(empty())
                throw std::runtime_error("\nList is empty!\n");
            auto temp = front_->next;
            delete front_;
            front_ = temp;
            --size_;
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
            if(empty())
                throw std::runtime_error("\nList is empty!\n");
            delete front_[size_ - 2].next;
            front_[size_ - 2].next = nullptr;
        }
        catch (std::runtime_error& ex)
        {
            std::cerr << ex.what();
        }
    }

    template <class T, class Container>
    typename list<T, Container>::const_reference list<T, Container>::at(num& ptr) const
    {
        try
        {
            if(ptr > size_)
                throw std::runtime_error("\nOut of range!\n");
            return front_[ptr].data;
        }
        catch (std::runtime_error& ex)
        {
            std::cerr << ex.what();
        }
    }

    template <class T, class Container>
    typename list<T, Container>::reference list<T, Container>::at(num& ptr)
    {
        try
        {
            if(ptr > size_)
                throw std::runtime_error("\nOut of range!\n");
            return front_[ptr].data;
        }
        catch (std::runtime_error& ex)
        {
            std::cerr << ex.what();
        }
    }

    template <class T, class Container>
    void list<T, Container>::insert(const T& value, const size_t& index)
    {
        // node* new_node = new node;
        // new_node->data = value;


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

    template <class T, class Container>
    void list<T, Container>::print_list()
    {
        for(size_t i = 0; i < size_; ++i)
            std::cout << at(i);
    }

    template <class T, class Container>
    void list<T, Container>::clear()
    {
        while (!empty())
            pop_back();
    }

    template <class T, class Container>
    bool list<T, Container>::empty() const
    {
        return size_ == 0;
    }

    template <class T, class Container>
    size_t list<T, Container>::size() const
    {
        return size_;
    }
}