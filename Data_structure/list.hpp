#pragma once
#include "deque.hpp"
namespace NNU9
{
    template<class T, class Container = deque<T>>
    class list  // NOLINT(cppcoreguidelines-special-member-functions)
    {
    public:
        using num = const unsigned long long;
        using reference = T&;
        using const_reference = const T&;
        list();
        ~list();
        void push_front(const T& value);
        void push_back(const T& value);
        void pop_front();
        void pop_back();
        const_reference at(num& ptr) const;
        reference at(num& ptr);
        void insert(const T& value, const size_t& index);
        void print_list();
        void clear();
        [[nodiscard]] bool empty() const;
        [[nodiscard]] size_t size() const;
    private:
        struct node
        {
            T data;
            node* next;
        };
        node* front_;
        size_t size_;
    };
}