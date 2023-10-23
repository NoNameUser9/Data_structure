#pragma once
#include <cstdint>
#define SIZE 10

namespace NNU9
{
    template <class  T>
    class allocator {
    public:
        // Конструкторы и деструктор
        allocator() noexcept;
        template <typename U>
        explicit allocator(const allocator<U>&) noexcept;
        ~allocator() noexcept;
        
        // Методы, необходимые для аллокации и освобождения памяти
        [[nodiscard]] static constexpr T* allocate(const size_t& n);
        [[nodiscard]] static constexpr T* append(size_t& n, const size_t& add);
        [[nodiscard]] static constexpr T* shrink(size_t& n, const size_t& remove);
        static constexpr void deallocate(T* p);

        using value_type = T;
        using pointer = T*;
        using const_pointer = const T*;
        using size_type = size_t;
    };

    template <typename T>
    constexpr T* allocator<T>::allocate(const size_t& n)
    {
        return static_cast<T*>(operator new(n * sizeof(T)));
    }

    template <typename T>
    constexpr T* allocator<T>::append(size_t& n, const size_t& add)
    {
        n += add;
        return static_cast<T>(operator new(n * sizeof(T)));
    }

    template <typename T>
    constexpr T* allocator<T>::shrink(size_t& n, const size_t& remove)
    {
        n -= remove;
        return static_cast<T>(operator new(n * sizeof(T)));
    }

    template <typename T>
    constexpr void allocator<T>::deallocate(T* p)
    {
        ::operator delete[](p);
    }

    template <typename T>
    allocator<T>::allocator() noexcept {}

    template <typename T>
    template <typename U>
    allocator<T>::allocator(const allocator<U>&) noexcept {}

    template <typename T>
    allocator<T>::~allocator() noexcept {}
}