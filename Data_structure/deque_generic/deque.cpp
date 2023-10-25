#include "deque.hpp"
#include "../swap.hpp"
#include <iostream>

namespace NNU9
{
    template deque<int>;
    template deque<float>;
    template deque<char>;
    template deque<bool>;
    template deque<std::string>;
    
    template <class T, class  Allocator>
    deque<T, Allocator>::deque(): arr_(new T[SIZE]{}), max_size_(SIZE), max_size_for_all_(SIZE), size_(0){}

    template <class T, class  Allocator>
    deque<T, Allocator>::~deque()
    {
        try
        {
            if(incremented_times_ > 0)
                for (auto i = incremented_times_; i != 0; --i)
                    --arr_;

            alloc_.deallocate(arr_);
        }
        catch (std::runtime_error& ex)
        {
            std::cerr << ex.what();
        }
    }

    template <class T, class  Allocator>
    bool deque<T, Allocator>::empty() const
    {
        return size_ == 0;
    }

    template <class T, class  Allocator>
    size_t deque<T, Allocator>::size() const
    {
        return size_;
    }

    template <typename T, class Allocator>
    size_t deque<T, Allocator>::max_size() const
    {
        return max_size_;
    }

    template <class T, class  Allocator>
    // ReSharper disable once CppNotAllPathsReturnValue
    typename deque<T, Allocator>::const_ref deque<T, Allocator>::at(const_size_t_ref pos) const
    {
        try
        {
            if(pos > size_)
                throw std::runtime_error("\nOut of range!\n");
            
            return arr_[pos];
        }
        catch (std::runtime_error& ex)
        {
            std::cerr << ex.what();
        }
    }

    template <class T, class  Allocator>
    // ReSharper disable once CppNotAllPathsReturnValue
    typename deque<T, Allocator>::ref deque<T, Allocator>::at(const_size_t_ref pos)
    {
        try
        {
            if(pos > size_)
                throw std::runtime_error("\nOut of range!\n");
            
            return arr_[pos];
        }
        catch (std::runtime_error& ex)
        {
            std::cerr << ex.what();
        }
    }

    template <class T, class  Allocator>
    void deque<T, Allocator>::push_back(const_ref value)
    {
        try
        {
            if(size_ == max_size_for_all_)
                throw std::runtime_error("\nDeque is full!\n");

            if (size_ + 1 == max_size_)
            {
                auto temp = new T[size_];
                for (auto i = 0; i < size_; ++i)
                    temp[i] = arr_[i];

                alloc_.deallocate(arr_);
                arr_ = alloc_.allocate(max_size_for_all_);
                max_size_ = max_size_for_all_;
            
                for (size_t i = 0; i < size_; ++i)
                    arr_[i] = temp[i];
            }

            arr_[size_++] = value;
        }
        catch (std::runtime_error& ex)
        {
            std::cerr << ex.what();
        }
    }

    template <class T, class  Allocator>
    void deque<T, Allocator>::push_front(const_ref value)
    {
        try
        {
            if(size_ == max_size_for_all_)
                throw std::runtime_error("\nDeque is full!\n");
            
            auto temp = new T[size_];
            for (auto i = 0; i < size_; ++i)
                temp[i] = arr_[i];
            
            if(incremented_times_ > 0)
                for (auto i = incremented_times_; i != 0; --i)
                    --arr_;
            
            alloc_.deallocate(arr_);
            arr_ = alloc_.allocate(max_size_for_all_);
            max_size_ = max_size_for_all_;
            
            for (size_t i = 0; i < size_; ++i)
                arr_[i + 1] = temp[i];
            arr_[0] = value;
            
            ++size_;
            delete[] temp;
        }
        catch (std::runtime_error& ex)
        {
            std::cerr << ex.what();
        }
    }

    template <class T, class  Allocator>
    void deque<T, Allocator>::pop_back()
    {
        try
        {
            if (empty())
                throw std::runtime_error("\nDeque is empty!\n");

            arr_[--size_] = static_cast<T>(0);
        }
        catch (std::runtime_error& ex)
        {
            std::cerr << ex.what();
        }
    }


    template <class T, class  Allocator>
    void deque<T, Allocator>::pop_front()
    {
        try
        {
            if (empty())
                throw std::runtime_error("\nDeque is empty!\n");

            ++arr_;
            ++incremented_times_;

            --max_size_;
            --size_;
        }
        catch (std::runtime_error& ex)
        {
            std::cerr << ex.what();
        }
    }

    template <typename T, class Allocator>
    void deque<T, Allocator>::insert(const_size_t_ref pos, const_ref value)
    {
        try
        {
            if(size_ == max_size_)
                throw std::runtime_error("\nDeque is full!\n");

            for (size_t i = size_; i > pos; --i)
                arr_[i] = arr_[i - 1];
            arr_[pos] = value;
        }
        catch (std::runtime_error& ex)
        {
            std::cerr << ex.what();
        }
    }

    template <typename T, class Allocator>
    void deque<T, Allocator>::swap(deque& other) noexcept
    {
        NNU9::swap(arr_, other.arr_);
        NNU9::swap(size_, other.size_);
        NNU9::swap(max_size_, other.max_size_);
    }

    template <class T, class  Allocator>
    void deque<T, Allocator>::resize(const_size_t_ref size)
    {
        try
        {
            if(size < size_)
                throw std::runtime_error("\nDeque has a queue bigger then a new size!\n");

            auto temp = new T[size_];
            for (size_t i = 0; i < size_; ++i)
                    temp[i] = arr_[i];

            alloc_.deallocate(arr_);
            arr_ = alloc_.allocate(size_);
            
            for (size_t i = 0; i < size_; ++i)
                arr_[i] = temp[i];
            
            max_size_ = size;

            delete[] temp;
        }
        catch (std::runtime_error& ex)
        {
            std::cerr << ex.what();
        }
    }

    template <typename T, class Allocator>
    void deque<T, Allocator>::shrink_to_fit()
    {
        try
        {
            if(size_ == 0)
                throw std::runtime_error("\nDeque is empty!\n");
            
            max_size_ = size_;
            
            resize(size_);
        }
        catch (std::runtime_error& ex)
        {
            std::cerr << ex.what();
        }
    }

    template <typename T, class Allocator>
    void deque<T, Allocator>::erase(const_size_t_ref pos)
    {
        try
        {
            if(empty())
                throw std::runtime_error("\nDeque is empty!\n");
            
            if (size_ == max_size_)
                arr_[size_ - 1] = static_cast<T>(0);
            
            for (size_t i = pos; i < size_--; ++i)
                arr_[i] = arr_[i + 1];
        }
        catch (std::runtime_error& ex)
        {
            std::cerr << ex.what();
        }
    }

    template <typename T, class Allocator>
    void deque<T, Allocator>::erase(const_size_t_ref first, const_size_t_ref last)
    {
        try
        {
            if(last > size() || first > size())
                throw std::runtime_error("\nOut of range!\n");
            
            for (auto i(first); i <= last; ++i)
                erase(i);
        }
        catch (std::runtime_error& ex)
        {
            std::cerr << ex.what();
        }
    }

    template <typename T, class Allocator>
    void deque<T, Allocator>::clear()
    {
        alloc_.deallocate(arr_);
        arr_ = alloc_.allocate(max_size_);
        size_ = 0;
    }

    template <class T, class  Allocator>
    // ReSharper disable once CppNotAllPathsReturnValue
    typename deque<T, Allocator>::const_ref deque<T, Allocator>::back() const
    {
        try
        {
            if (empty())
                throw std::runtime_error("\nDeque is empty!\n");
            
            return arr_[size_ - 1];
        }
        catch (std::runtime_error& ex)
        {
            std::cerr << ex.what();
        }
    }

    template <typename T, class Allocator>
    // ReSharper disable once CppNotAllPathsReturnValue
    typename deque<T, Allocator>::ref deque<T, Allocator>::back()
    {
        try
        {
            if (empty())
                throw std::runtime_error("\nDeque is empty!\n");
            
            return arr_[size_ - 1];
        }
        catch (std::runtime_error& ex)
        {
            std::cerr << ex.what();
        }
    }

    template <class T, class  Allocator>
    // ReSharper disable once CppNotAllPathsReturnValue
    typename deque<T, Allocator>::const_ref deque<T, Allocator>::front() const
    {
        try
        {
            if (empty())
                throw std::runtime_error("\nDeque is empty!\n");

            return arr_[0];
        }
        catch (std::runtime_error& ex)
        {
            std::cerr << ex.what();
        }
    }

    template <typename T, class Allocator>
    // ReSharper disable once CppNotAllPathsReturnValue
    typename deque<T, Allocator>::ref deque<T, Allocator>::front()
    {
        try
        {
            if (empty())
                throw std::runtime_error("\nDeque is empty!\n");
            
            return arr_[0];
        }
        catch (std::runtime_error& ex)
        {
            std::cerr << ex.what();
        }
    }

    template <typename T, class Allocator>
    // ReSharper disable once CppNotAllPathsReturnValue
    typename deque<T, Allocator>::ref deque<T, Allocator>::operator[](const_size_t_ref pos)
    {
        try
        {
            if(size_ < pos)
                throw std::runtime_error("\nOut of range!\n");

            return arr_[pos];
        }
        catch (std::runtime_error& ex)
        {
            std::cerr << ex.what();
        }
    }

    template <typename T, class Allocator>
    // ReSharper disable once CppNotAllPathsReturnValue
    typename deque<T, Allocator>::const_ref deque<T, Allocator>::operator[](const_size_t_ref pos) const
    {
        try
        {
            if(size_ < pos)
                throw std::runtime_error("\nOut of range!\n");

            return arr_[pos];
        }
        catch (std::runtime_error& ex)
        {
            std::cerr << ex.what();
        }
    }
}
