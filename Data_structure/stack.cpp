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
    void stack<T, Container>::push(const T& value)
    {
        container_.push_back(value);
    }

    template <class T, class Container>
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
    template <typename ... Args>
    void stack<T, Container>::emplace(Args&&... args)
    {
        // node* new_node = new node(std::forward<Args>(args)...);
        // new_node->next = head_;
        // head_ = new_node;
    }

    template <class T, class Container>
    T stack<T, Container>::top()
    {
        try
        {
            if(container_.empty())
                throw std::runtime_error("\nStack is empty!\n");
            return container_.back();
        }
        catch (const std::runtime_error& ex)
        {
            std::cerr << ex.what();
        }
        return {};
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
}