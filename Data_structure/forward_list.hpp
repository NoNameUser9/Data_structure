#pragma once
#include "deque.hpp"

namespace NNU9
{
    /**
     * \tparam T is type of data
     * \tparam Allocator is container of data
     * \note Not yet implemented now!
     */
    template<class T, class Allocator = allocator<T>>
    class list  // NOLINT(cppcoreguidelines-special-member-functions)
    {
    public:
        using ref = T&;
        using const_ref = const T&;
        list();
        ~list();
        void push_front(const T& value);
        void pop_front();
        // const_reference at(num& ptr) const;
        // reference at(num& ptr);
        T begin();
        ref front();
        ref back();
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
        node* back_;
        size_t size_;
        Allocator alloc_;
    };
}