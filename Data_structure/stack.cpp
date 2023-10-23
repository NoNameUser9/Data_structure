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

    template <class T, class Container>
    stack<T, Container>::~stack() {}

    template <class T, class Container>
    void stack<T, Container>::push(const_ref value)
    {
        try
        {
            if(container_.max_size() == container_.size())
                throw std::runtime_error("\nStack is full!\n");
            
            container_.push_back(value);
        }
        catch (const std::runtime_error& ex)
        {
            std::cerr << ex.what();
        }
    }

    template <typename T, class Container>
    void stack<T, Container>::pop()
    {
        try
        {
            if(container_.empty())
                throw std::runtime_error("\nStack is empty!\n");
            
            container_.pop_back();
        }
        catch (const std::runtime_error& ex)
        {
            std::cerr << ex.what();
        }
    }

    template <class T, class Container>
    // ReSharper disable once CppNotAllPathsReturnValue
    typename stack<T, Container>::ref stack<T, Container>::top()
    {
        try
        {
            if(container_.empty())
                throw std::runtime_error("\nStack is empty!\n");
            
            return container_.front();
        }
        catch (const std::runtime_error& ex)
        {
            std::cerr << ex.what();
        }
    }

    template <typename T, class Container>
    // ReSharper disable once CppNotAllPathsReturnValue
    typename stack<T, Container>::const_ref stack<T, Container>::top() const
    {
        try
        {
            if(container_.empty())
                throw std::runtime_error("\nStack is empty!\n");
            
            return container_.front();
        }
        catch (const std::runtime_error& ex)
        {
            std::cerr << ex.what();
        }
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