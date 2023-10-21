#include "queue.hpp"
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
    void queue<T, Container>::push(const T& value)
    {
        container_.push_back(value);
    }

    template <class T, class Container>
    void queue<T, Container>::pop()
    {
        container_.pop_back();
    }

    template <class T, class Container>
    T queue<T, Container>::front()
    {
        return  container_.front();
    }

    template <class T, class Container>
    T queue<T, Container>::back()
    {
        return container_.back();
    }
}