#pragma once
#include <utility>

#include "deque.hpp"

namespace NNU9
{
    template <class T, class Container = deque<T>>
    class queue // NOLINT(cppcoreguidelines-special-member-functions)
    {
        using ref = T&;
        using const_ref = const T&;
        using const_size_t_ref = const size_t&;

    public:
        queue();
        queue(std::initializer_list<T> list);
        ~queue();
        [[nodiscard]] bool empty() const;
        [[nodiscard]] size_t size() const;
        [[nodiscard]] size_t max_size() const;
        const_ref at(const_size_t_ref pos) const;
        ref at(const_size_t_ref pos);
        void push(const_ref value);
        void pop();
        void insert(const_size_t_ref pos, const_ref value);
        void swap(Container& other) noexcept;
        void resize(const_size_t_ref size);
        void shrink_to_fit();
        void erase(const_size_t_ref pos);
        void erase(const_size_t_ref first, const_size_t_ref last);
        void clear();
        [[nodiscard]] ref back();
        [[nodiscard]] const_ref back() const;
        [[nodiscard]] ref front();
        [[nodiscard]] const_ref front() const;
        ref operator[](const_size_t_ref pos);
        const_ref operator[](const_size_t_ref pos) const;

    private:
        Container container_;
    };
}
