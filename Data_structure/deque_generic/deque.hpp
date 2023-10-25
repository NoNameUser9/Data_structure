#pragma once
#include "../allocator.hpp"

namespace NNU9
{
    template<typename T, class Allocator = allocator<T>>
    class deque  // NOLINT(cppcoreguidelines-special-member-functions)
    {
    public:
        using ref = T&;
        using const_ref = const T&;
        using const_size_t_ref = const size_t&;
        deque();
        ~deque();
        [[nodiscard]] bool empty() const;
        [[nodiscard]] size_t size() const;
        [[nodiscard]] size_t max_size() const;
        const_ref at(const_size_t_ref pos) const;
        ref at(const_size_t_ref pos);
        void push_back(const_ref value);
        void push_front(const_ref value);
        void pop_back();
        void pop_front();
        void insert(const_size_t_ref pos, const_ref value);
        void swap(deque& other) noexcept;
        void resize(const_size_t_ref size);
        void shrink_to_fit();
        void erase(const_size_t_ref pos);
        void erase(const_size_t_ref first, const_size_t_ref last );
        void clear();
        [[nodiscard]] const_ref back() const;
        [[nodiscard]] ref back();
        [[nodiscard]] const_ref front() const;
        [[nodiscard]] ref front();
        ref operator[](const_size_t_ref pos);
        const_ref operator[](const_size_t_ref pos) const;
    private:
        size_t incremented_times_ = 0;
        T* arr_;
        Allocator alloc_;
        size_t max_size_for_all_;
        size_t max_size_;
        size_t size_;
    };
}
