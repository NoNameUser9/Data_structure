#pragma once
#include "../allocator.hpp"

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
        class iterator;
        using ref = T&;
        using const_ref = const T&;
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
        list();
        list(const list &right);
        template<class... Args>
        // ReSharper disable once CppNonExplicitConvertingConstructor
        list(Args ... args);
        ~list();
        
        void push_front(const_ref value);
        void push_front(ref value);
        void pop_front();
        iterator begin();
        iterator begin() const;
        iterator end();
        iterator end() const;
        ref front();
        ref back();
        void insert_after(const_ref value, const size_t& index);
        void print_list();
        void sort();
        void unique();
        void merge(const list& right);
        void clear();
        [[nodiscard]] bool empty() const;
        [[nodiscard]] size_t size() const;
        ref operator[](size_t index);
        list& operator=(const list& right);
        
        class iterator  // NOLINT(cppcoreguidelines-special-member-functions)
        {
        public:
            node* ptr;
            
            iterator();
            explicit iterator(auto begin);
            ~iterator();

            bool operator==(const iterator& right) const;
            ref operator*();
            iterator& operator++();
            iterator operator++(int);
            [[nodiscard]] size_t pos() const;
            
        private:
            size_t pos_now_;
            node* front_;
            node* back_;
        };
    };
}
