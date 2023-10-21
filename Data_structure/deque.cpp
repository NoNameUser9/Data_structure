#include "deque.hpp"
#include <iostream>
#include <string>
namespace NNU9
{
    template deque<int>;
    template deque<float>;
    template deque<char>;
    template deque<bool>;
    template deque<std::string>;

    template <typename T>
    deque<T>::deque(): arr(new size_t[10]), back_(nullptr), front_(nullptr), size_(0)
    {
    }

    template <typename T>
    deque<T>::~deque()
    {
        // while (!empty())
        //     pop_front();
        try
        {
            delete[] arr;
            throw std::runtime_error("deletion err");
        }
        catch (std::runtime_error& ex)
        {
            std::cerr << ex.what();
        }
    }

    template <typename T>
    bool deque<T>::empty() const
    {
        return size_ == 0;
    }

    template <typename T>
    size_t deque<T>::size() const
    {
        return size_;
    }

    template <typename T>
    typename deque<T>::const_reference deque<T>::at(num& ptr) const
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

    template <typename T>
    typename deque<T>::reference deque<T>::at(num& ptr)
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
        try
        {
            if (empty())
                throw std::runtime_error("\nDeque is empty!\n");

            const node* temp = front_;
            front_ = front_->next;

            if (front_ == nullptr)
                back_ = nullptr;
            else
                front_->prev = nullptr;

            delete temp;
            size_--;
        }
        catch (std::runtime_error& ex)
        {
            std::cerr << ex.what();
        }
    }

    template <typename T>
    void deque<T>::pop_back()
    {
        try
        {
            if (empty())
                throw std::runtime_error("\nDeque is empty!\n");
            
            back_ = back_->prev;

            if (back_ == nullptr)
                front_ = nullptr;
            else
                back_->next = nullptr;
            size_--;
        }
        catch (std::runtime_error& ex)
        {
            std::cerr << ex.what();
        }
    }

    template <typename T>
    void deque<T>::resize(const size_t& size)
    {
        size_ = size;
    }

    template <typename T>
    const T& deque<T>::front() const
    {
        try
        {
            if (empty())
                throw std::runtime_error("\nDeque is empty!\n");
            return front_->data;
        }
        catch (std::runtime_error& ex)
        {
            std::cerr << ex.what();
        }
        return {};
    }

    template <typename T>
    const T& deque<T>::back() const
    {
        try
        {
            if (empty())
                throw std::runtime_error("\nDeque is empty!\n");
            return back_->data;
        }
        catch (std::runtime_error& ex)
        {
            std::cerr << ex.what();
        }
        return {};
    }
}