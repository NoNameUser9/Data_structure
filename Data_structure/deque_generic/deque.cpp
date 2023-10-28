#include "deque.hpp"
#include "../supporting_finctions/swap.hpp"
#include <iostream>

namespace NNU9
{
    template deque<int>;
    template deque<float>;
    template deque<char>;
    template deque<bool>;
    template deque<std::string>;
    
    template <class T, class  Allocator>
    deque<T, Allocator>::deque(): arr_(new T[SIZE]{}), max_size_for_all_(SIZE), max_size_(SIZE), size_(0){}

    template <typename T, class Allocator>
    deque<T, Allocator>::deque(std::initializer_list<T> list): arr_(new T[SIZE]{}), max_size_for_all_(SIZE), max_size_(SIZE), size_(0)
    {
        for (auto it : list)
            arr_[size_++] = it;
    }

    template <class T, class  Allocator>
    deque<T, Allocator>::~deque()
    {
        for (; incremented_times_ > 0; --incremented_times_)
            --arr_;
        
        alloc_.deallocate(arr_);
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
    typename deque<T, Allocator>::const_ref deque<T, Allocator>::at(const_size_t_ref pos) const
    {
        if(pos > size_)
            throw std::runtime_error("\nOut of range!\n");
        
        return arr_[pos];
    }

    template <class T, class  Allocator>
    typename deque<T, Allocator>::ref deque<T, Allocator>::at(const_size_t_ref pos)
    {
        if(pos > size_)
            throw std::runtime_error("\nOut of range!\n");
        
        return arr_[pos];
    }

    template <class T, class  Allocator>
    void deque<T, Allocator>::push_back(const_ref value)
    {
        if(size_ == max_size_for_all_)
            throw std::runtime_error("\nDeque is full!\n");

        if (size_ + 1 == max_size_)
        {
            auto temp = new T[size_];
            for (size_t i = 0; i < size_; ++i)
                temp[i] = arr_[i];

            for (; incremented_times_ > 0; --incremented_times_)
                --arr_;
        
            alloc_.deallocate(arr_);
            arr_ = alloc_.allocate(max_size_for_all_);
            max_size_ = max_size_for_all_;
        
            for (size_t i = 0; i < size_; ++i)
                arr_[i] = temp[i];
        }

        arr_[size_++] = value;
    }

    template <class T, class  Allocator>
    void deque<T, Allocator>::push_front(const_ref value)
    {
        if(size_ == max_size_for_all_)
            throw std::runtime_error("\nDeque is full!\n");
        
        if(incremented_times_ > 0)
        {
            --incremented_times_;
            --arr_;
            ++max_size_;
            arr_[0] = value;
        }

        if (incremented_times_ == 0)
        {
            auto temp = new T[size_];
            for (size_t i = 0; i < size_; ++i)
                temp[i] = arr_[i];
            
            alloc_.deallocate(arr_);
            arr_ = alloc_.allocate(max_size_for_all_);
            max_size_ = max_size_for_all_;
            
            for (size_t i = 0; i < size_; ++i)
                arr_[i + 1] = temp[i];
            arr_[0] = value;
            
            delete[] temp;
        }
        
        ++size_;
    }

    template <class T, class  Allocator>
    void deque<T, Allocator>::pop_back()
    {
        if (empty())
            throw std::runtime_error("\nDeque is empty!\n");

        arr_[--size_] = static_cast<T>(0);
    }


    template <class T, class  Allocator>
    void deque<T, Allocator>::pop_front()
    {
        if (empty())
            throw std::runtime_error("\nDeque is empty!\n");

        ++arr_;
        ++incremented_times_;

        --max_size_;
        --size_;
    }

    template <typename T, class Allocator>
    void deque<T, Allocator>::insert(const_size_t_ref pos, const_ref value)
    {
        if(size_ == max_size_)
            throw std::runtime_error("\nDeque is full!\n");

        for (size_t i = size_; i > pos; --i)
            arr_[i] = arr_[i - 1];
        arr_[pos] = value;
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
        if(size < size_)
            throw std::runtime_error("\nDeque has a queue bigger then a new size!\n");

        auto temp = new T[size_];
        for (size_t i = 0; i < size_; ++i)
                temp[i] = arr_[i];

        alloc_.deallocate(arr_);
        arr_ = alloc_.allocate(size_);
        
        for (size_t i = 0; i < size_; ++i)
            arr_[i] = temp[i];
        
        max_size_for_all_ = size;
        max_size_ = max_size_for_all_;

        delete[] temp;
    }

    template <typename T, class Allocator>
    void deque<T, Allocator>::shrink_to_fit()
    {
        if(size_ == 0)
            throw std::runtime_error("\nDeque is empty!\n");
        
        resize(size_);
    }

    template <typename T, class Allocator>
    void deque<T, Allocator>::erase(const_size_t_ref pos)
    {
        if(empty())
            throw std::runtime_error("\nDeque is empty!\n");
        
        if (size_ == max_size_)
            arr_[size_ - 1] = static_cast<T>(0);
        
        for (size_t i = pos; i < size_--; ++i)
            arr_[i] = arr_[i + 1];
    }

    template <typename T, class Allocator>
    void deque<T, Allocator>::erase(const_size_t_ref first, const_size_t_ref last)
    {
        if(last > size() || first > size())
            throw std::runtime_error("\nOut of range!\n");
        
        for (auto i(first); i <= last; ++i)
            erase(i);
    }

    template <typename T, class Allocator>
    void deque<T, Allocator>::clear()
    {
        alloc_.deallocate(arr_);
        arr_ = alloc_.allocate(max_size_);
        size_ = 0;
    }

    template <class T, class  Allocator>
    typename deque<T, Allocator>::const_ref deque<T, Allocator>::back() const
    {
        if (empty())
            throw std::runtime_error("\nDeque is empty!\n");
        
        return arr_[size_ - 1];
    }

    template <typename T, class Allocator>
    typename deque<T, Allocator>::ref deque<T, Allocator>::back()
    {
        if (empty())
            throw std::runtime_error("\nDeque is empty!\n");
        
        return arr_[size_ - 1];
    }

    template <class T, class  Allocator>
    typename deque<T, Allocator>::const_ref deque<T, Allocator>::front() const
    {
        if (empty())
            throw std::runtime_error("\nDeque is empty!\n");

        return arr_[0];
    }

    template <typename T, class Allocator>
    typename deque<T, Allocator>::ref deque<T, Allocator>::front()
    {
        if (empty())
            throw std::runtime_error("\nDeque is empty!\n");
        
        return arr_[0];
    }

    template <typename T, class Allocator>
    typename deque<T, Allocator>::ref deque<T, Allocator>::operator[](const_size_t_ref pos)
    {
        if(size_ < pos)
            throw std::runtime_error("\nOut of range!\n");

        return arr_[pos];
    }

    template <typename T, class Allocator>
    typename deque<T, Allocator>::const_ref deque<T, Allocator>::operator[](const_size_t_ref pos) const
    {
        if(size_ < pos)
            throw std::runtime_error("\nOut of range!\n");

        return arr_[pos];
    }
}
