#pragma once
#include "swap.h"

struct stack
{
    stack()
    {
        next_ = nullptr;
    }
    void push(int elem)
    {
        if(size_ > 0)
        {
            // next_[++size_ - 2].next_ = nullptr;
            next_[++size_ - 2].next_ = new stack;
            next_[size_ - 2].data_ = elem;
            return;
        }
        next_ = new stack;
        // next_ = nullptr;
        data_ = elem;
        ++size_;
    }
    int pop()
    {
        if(size_ > 2)
        {
            int tmp = next_[--size_ - 1].data_;
            // delete next_[size_ - 1].next_;
            next_[size_ - 1].next_ = nullptr;
            return tmp;
        }
        if (size_ == 2)
        {
            int tmp = next_[0].data_;
            // delete next_;
            next_[0].next_ = nullptr;
            next_ = nullptr;
            --size_;
            return tmp;
        }
        if (size_ == 1)
        {
            --size_;
            return data_;
        }
        return 0;
    }
    int top();
    [[nodiscard]] bool empty() const;
    void emplace(int& elem)
    {
        if(size_ == 1)
            data_ = elem;
        else
            next_[size_ - 2].data_ = elem;
    }
    uint16_t size()
    {
        return size_;
    }
    // void swap(stack& st) noexcept;
private:
    int data_;
    stack* next_;
    uint16_t size_{};
};


bool stack::empty() const
{
    return size_ == 0;
}

// void stack::emplace(int& elem)
// {
//     if(size_ == 1)
//         data_ = elem;
//     else
//         next_[size_ - 2].data_ = elem;
// }

// void stack::swap(stack& st) noexcept
// {
//     NNU9::swap(data_, st.data_);
//     NNU9::swap(size_, st.size_);
//     NNU9::swap(next_, st.next_);
// }
// #include "swap.h"
//
// template <class T>
// struct stack
// {
//     stack();
//     void push(T elem);
//     T pop();
//     T top();
//     [[nodiscard]] bool empty() const;
//     void emplace(T& elem);
//     auto size() const;
//     void swap(stack& st) noexcept;
// private:
//     T data_;
//     stack* next_;
//     uint16_t size_{};
// };
//
// template <class T>
// stack<T>::stack()
// {
//     next_ = nullptr;
// }
//
// template <class T>
// void stack<T>::push(T elem)
// {
//     if(size_ > 0)
//     {
//         // next_[++size_ - 2].next_ = nullptr;
//         next_[++size_ - 2].next_ = new stack;
//         next_[size_ - 2].data_ = elem;
//         return;
//     }
//     next_ = new stack;
//     // next_ = nullptr;
//     data_ = elem;
//     ++size_;
// }
//
// template <class T>
// T stack<T>::pop()
// {
//     if(size_ > 2)
//     {
//         T tmp = next_[--size_ - 1].data_;
//         // delete next_[size_ - 1].next_;
//         next_[size_ - 1].next_ = nullptr;
//         return tmp;
//     }
//     if (size_ == 2)
//     {
//         T tmp = next_[0].data_;
//         // delete next_;
//         next_[0].next_ = nullptr;
//         next_ = nullptr;
//         --size_;
//         return tmp;
//     }
//     if (size_ == 1)
//     {
//         --size_;
//         return data_;
//     }
//     return 0;
// }
//
// template <class T>
// T stack<T>::top()
// {
//     if (size_ == 1)
//         return data_;
//     return next_[size_ - 1];
// }
//
// template <class T>
// bool stack<T>::empty() const
// {
//     return size_ == 0;
// }
//
// template <class T>
// void stack<T>::emplace(T& elem)
// {
//     if(size_ == 1)
//         data_ = elem;
//     else
//         next_[size_ - 2].data_ = elem;
// }
//
// template <class T>
// auto stack<T>::size() const
// {
//     return size_;
// }
//
// template <class T>
// void stack<T>::swap(stack& st) noexcept
// {
//     NNU9::swap(data_, st.data_);
//     NNU9::swap(size_, st.size_);
//     NNU9::swap(next_, st.next_);
// }