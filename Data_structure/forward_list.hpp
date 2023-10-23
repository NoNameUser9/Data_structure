#pragma once
#include "deque.hpp"

// ReSharper disable once CppInconsistentNaming
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
    public:
        class iterator;
        using ref = T&;
        using const_ref = const T&;
        list();
        ~list();
        void push_front(const T& value);
        void pop_front();
        iterator begin();
        iterator end();
        ref front();
        ref back();
        void insert_after(const T& value, const size_t& index);
        void print_list();
        void sort();
        /**
         * \note Not yet implemented!
         */
        void unique();
        void merge(list& list);
        void clear();
        [[nodiscard]] bool empty() const;
        [[nodiscard]] size_t size() const;
        class iterator
        {
        public:
            node* ptr;
            iterator();
            explicit iterator(auto begin);
            
            bool operator==(const iterator& right) const;
            // ReSharper disable once CppNotAllPathsReturnValue
            ref operator*();
            iterator& operator++();
            iterator operator++(int);
        private:
            node* front_;
            node* back_;
            uint64_t pos_now_;
        };
    };
}
