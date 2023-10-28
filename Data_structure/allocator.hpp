#pragma once
#define SIZE 1000  // NOLINT(modernize-macro-to-enum)

namespace NNU9
{
    template <class  T>
    class allocator {  // NOLINT(cppcoreguidelines-special-member-functions)
        using ptr = T*;
        using value_type = T;
        using const_ptr = const T*;
        using size_type = size_t;
        
    public:
        allocator() noexcept;
        template <typename U>
        explicit allocator(const allocator<U>&) noexcept;
        ~allocator() noexcept;
        
        [[nodiscard]] static constexpr ptr allocate(const size_t& n);
        static constexpr void append(size_t& n, const size_t& add, ptr Ptr);
        [[nodiscard]] static constexpr ptr shrink(size_t& n, const size_t& remove);
        static constexpr void deallocate(T* p);

    };

    template <typename T>
    constexpr typename allocator<T>::ptr allocator<T>::allocate(const size_t& n)
    {
        return static_cast<T*>(operator new(n * sizeof(T)));
    }

    template <typename T>
    constexpr void allocator<T>::append(size_t& n, const size_t& add, ptr Ptr)
    {
        n += add;
        deallocate(Ptr);
        Ptr = allocate(n);
    }

    template <typename T>
    constexpr typename allocator<T>::ptr allocator<T>::shrink(size_t& n, const size_t& remove)
    {
        n -= remove;
        return static_cast<T>(operator new(n * sizeof(T)));
    }

    template <typename T>
    constexpr void allocator<T>::deallocate(ptr p)
    {
        ::operator delete(p);
    }

    template <typename T>
    allocator<T>::allocator() noexcept {}

    template <typename T>
    template <typename U>
    allocator<T>::allocator(const allocator<U>&) noexcept {}

    template <typename T>
    allocator<T>::~allocator() noexcept {}
}
