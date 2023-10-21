#pragma once
#include <cstdint>

namespace NNU9
{
    template <typename T>
    class Allocator {
    public:
        using value_type = T;
        using pointer = T*;
        using const_pointer = const T*;
        using size_type = size_t;

        // Методы, необходимые для аллокации и освобождения памяти
        pointer allocate(size_type n) {
            return static_cast<pointer>(operator new(n * sizeof(value_type)));
        }

        void deallocate(pointer p, size_type n) {
            ::operator delete(p);
        }

        // Конструкторы и деструктор
        Allocator() noexcept {}

        template <typename U>
        Allocator(const Allocator<U>&) noexcept {}

        ~Allocator() noexcept {}
    };

    template<class T>
    struct allocator
    {
    public:
        typedef uint64_t const_pointer;
        typedef uint64_t const_reference;
        [[nodiscard]] constexpr T* allocate( size_t n );
        // void construct();
        // void destruct(size_t& n);
        // const_pointer address(const_reference x) const;
    private:
    };
}