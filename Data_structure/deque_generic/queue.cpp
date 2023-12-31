﻿#include "queue.hpp"
#include <iostream>

namespace NNU9
{
    template queue<int>;
    template queue<float>;
    template queue<char>;
    template queue<bool>;
    template queue<std::string>;

    template <class T, class Container>
    queue<T, Container>::queue() {}

    template <class T, class Container>
    queue<T, Container>::queue(std::initializer_list<T> list)
    {
        for (auto it : list)
            container_.push_back(it);
    }

    template <class T, class Container>
    queue<T, Container>::~queue() {}

    template <class T, class Container>
    bool queue<T, Container>::empty() const
    {
        return container_.empty();
    }

    template <class T, class Container>
    size_t queue<T, Container>::size() const
    {
        return container_.size();
    }

    template <class T, class Container>
    size_t queue<T, Container>::max_size() const
    {
        return container_.max_size();
    }

    template <class T, class Container>
    typename queue<T, Container>::const_ref queue<T, Container>::at(const_size_t_ref pos) const
    {
        if(pos > container_.size())
            throw std::runtime_error("\nQueue is empty!\n");
        
        return container_.at(pos);
    }

    template <class T, class Container>
    typename queue<T, Container>::ref queue<T, Container>::at(const_size_t_ref pos)
    {
        if(pos > container_.size())
            throw std::runtime_error("\nQueue is empty!\n");
        
        return container_.at(pos);
    }

    template <class T, class Container>
    void queue<T, Container>::push(const_ref value)
    {
        if(container_.max_size() == container_.size())
            throw std::runtime_error("\nQueue is full!\n");
        
        container_.push_back(value);
    }

    template <class T, class Container>
    void queue<T, Container>::pop()
    {
        if(container_.max_size() == container_.size())
            throw std::runtime_error("\nQueue is empty!\n");
        
        container_.pop_front();
    }

    template <class T, class Container>
    void queue<T, Container>::insert(const_size_t_ref pos, const_ref value)
    {
        if(container_.size() == container_.max_size())
            throw std::runtime_error("\nQueue is full!\n");
    
        container_.insert(pos, value);
    }

    template <class T, class Container>
    void queue<T, Container>::swap(Container& other) noexcept
    {
        container_.swap(other);
    }

    template <class T, class Container>
    void queue<T, Container>::resize(const_size_t_ref size)
    {
        if(size < container_.size())
            throw std::runtime_error("\nQueue has a queue bigger then a new size!\n");

        container_.resize(size);
    }

    template <class T, class Container>
    typename queue<T, Container>::ref queue<T, Container>::front()
    {
        if(empty())
            throw std::runtime_error("\nQueue is empty!\n");
        
        return container_.front();
    }

    template <class T, class Container>
    typename queue<T, Container>::const_ref queue<T, Container>::front() const
    {
        if(empty())
            throw std::runtime_error("\nQueue is empty!\n");
        
        return container_.front();
    }

    template <class T, class Container>
    typename queue<T, Container>::ref queue<T, Container>::operator[](const_size_t_ref pos)
    {
        return container_[pos];
    }

    template <class T, class Container>
    typename queue<T, Container>::const_ref queue<T, Container>::operator[](const_size_t_ref pos) const
    {
        return container_[pos];
    }

    template <class T, class Container>
    typename queue<T, Container>::ref queue<T, Container>::back()
    {
        if(empty())
            throw std::runtime_error("\nQueue is empty!\n");

        return container_.back();
    }

    template <class T, class Container>
    void queue<T, Container>::shrink_to_fit()
    {
        if(container_.size() == 0)
            throw std::runtime_error("\nDeque is empty!\n");
    
        container_.shrink_to_fit();
    }

    template <class T, class Container>
    void queue<T, Container>::erase(const_size_t_ref pos)
    {
        container_.erase(pos);
    }

    template <class T, class Container>
    void queue<T, Container>::erase(const_size_t_ref first, const_size_t_ref last)
    {
        container_.erase(first, last);
    }

    template <class T, class Container>
    void queue<T, Container>::clear()
    {
        container_.clear();
    }

    template <class T, class Container>
    typename queue<T, Container>::const_ref queue<T, Container>::back() const
    {
        if(empty())
            throw std::runtime_error("\nQueue is empty!\n");

        return container_.back();
    }
}
