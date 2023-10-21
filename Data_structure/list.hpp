#pragma once
#include "deque.hpp"

template<class T, class Container = deque<T>>
class list  // NOLINT(cppcoreguidelines-special-member-functions)
{
public:
    list();
    ~list();
    void push_front(const T& value);
    void push_back(const T& value);
    void pop_front();
    void pop_back();
    void insert(const T& value, const size_t& size);
    void print_list();
    void clear();
    [[nodiscard]] bool empty() const;
    [[nodiscard]] size_t size() const;
private:
    Container container_;
};
