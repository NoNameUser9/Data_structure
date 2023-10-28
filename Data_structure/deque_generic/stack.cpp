#include "stack.hpp"
#include <iostream>

namespace NNU9
{
    template stack<int>;
    template stack<float>;
    template stack<char>;
    template stack<bool>;
    template stack<std::string>;

    template <class T, class Container>
    stack<T, Container>::stack() {}

    template <typename T, class Container>
    stack<T, Container>::stack(std::initializer_list<T> list)
    {
        for (auto it : list)
            container_.push_back(it);
    }

    template <class T, class Container>
    stack<T, Container>::~stack() {}

    template <class T, class Container>
    void stack<T, Container>::push(const_ref value)
    {
        if(container_.max_size() == container_.size())
            throw std::runtime_error("\nStack is full!\n");
        
        container_.push_back(value);
    }

    template <typename T, class Container>
    void stack<T, Container>::pop()
    {
        if(container_.empty())
            throw std::runtime_error("\nStack is empty!\n");
        
        container_.pop_back();
    }

    template <class T, class Container>
    typename stack<T, Container>::ref stack<T, Container>::top()
    {
        if(container_.empty())
            throw std::runtime_error("\nStack is empty!\n");
        
        return container_.front();
    }

    template <typename T, class Container>
    typename stack<T, Container>::const_ref stack<T, Container>::top() const
    {
        if(container_.empty())
            throw std::runtime_error("\nStack is empty!\n");
        
        return container_.front();
    }

    template <class T, class Container>
    bool stack<T, Container>::empty() const
    {
        return container_.empty();
    }

    template <class T, class Container>
    size_t stack<T, Container>::size() const
    {
        return container_.size();
    }

    template <typename T, class Container>
    void stack<T, Container>::swap(Container& other) noexcept
    {
        container_.swap(other);
    }
}