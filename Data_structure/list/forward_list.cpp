﻿#include "forward_list.hpp"
#include "../supporting_finctions/shell_sort.hpp"
#include "../supporting_finctions/unique_idx.hpp"
#include <iostream>

namespace NNU9
{
    template list<int>;
    template list<size_t>;
    template list<float>;
    template list<char>;
    template list<bool>;
    template list<std::string>;

    template <class T, class Allocator>
    list<T, Allocator>::list(): front_(nullptr), back_(front_), size_(0) {}

    template <class T, class Allocator>
    list<T, Allocator>::list(const list& right): front_{new node{right.front_->data, nullptr}}, size_(0)
    {
        list temp;
        for (iterator it = right.begin(); it != right.end(); ++it)
            temp.push_front(it.ptr->data);
        
        for (iterator it = temp.begin(); it != right.end(); ++it)
            push_front(it.ptr->data);
    }

    template <class T, class Allocator>
    template <class ... Args>
    list<T, Allocator>::list(Args... args)
    {
        constexpr auto num_args{ sizeof...(Args) };

        T temp[num_args] = {args ...};
            
        for (auto i = 0; i < num_args; ++i)
            push_front(temp[i]);
    }

    template <class T, class Allocator>
    list<T, Allocator>::~list()
    {
        clear();
    }

    template <class T, class Allocator>
    void list<T, Allocator>::push_front(const_ref value)
    {
        node* new_node = new node{value};
        
        switch (size_)
        {
        case 0:
            {
                new_node->next = nullptr;
                front_ = new_node;
                back_ = front_;
                ++size_;
                return;
            }
        default:
            {
                new_node->next = front_;
                front_ = new_node;
                ++size_;
            }
        }
    }

    template <class T, class Allocator>
    void list<T, Allocator>::push_front(ref value)
    {
        push_front(static_cast<const_ref>(value));
    }

    template <class T, class Allocator>
    void list<T, Allocator>::pop_front()
    {
        if (empty())
            throw std::runtime_error("\nList is empty!\n");

        const node* pop_node = front_;
        front_ = front_->next;
        delete pop_node;

        --size_;
    }

    template <class T, class Allocator>
    typename list<T, Allocator>::iterator list<T, Allocator>::begin()
    {
        if (front_ == nullptr)
            throw std::runtime_error("\nlist is empty!\n");
        
        iterator ret(front_);
        return ret;
    }

    template <class T, class Allocator>
    typename list<T, Allocator>::iterator list<T, Allocator>::begin() const
    {
        if (front_ == nullptr)
            throw std::runtime_error("\nlist is empty!\n");
        
        iterator ret(front_);
        return ret;
    }

    template <class T, class Allocator>
    typename list<T, Allocator>::iterator list<T, Allocator>::end()
    {
        if (back_ == nullptr)
            throw std::runtime_error("\nlist is empty!\n");
        
        iterator ret(back_->next);
        return ret;
    }

    template <class T, class Allocator>
    typename list<T, Allocator>::iterator list<T, Allocator>::end() const
    {
        if (back_ == nullptr)
            throw std::runtime_error("\nlist is empty!\n");
        
        iterator ret(back_->next);
        return ret;
    }

    template <class T, class Allocator>
    typename list<T, Allocator>::ref list<T, Allocator>::front()
    {
        if (front_ == nullptr)
            throw std::runtime_error("\nlist is empty!\n");
        
        return front_->data;
    }

    template <class T, class Allocator>
    typename list<T, Allocator>::ref list<T, Allocator>::back()
    {
        if (back_ == nullptr)
            throw std::runtime_error("\nlist is empty!\n");
        
        return back_->data;
    }

    /**
     * \brief 
     * \param value element which will be inserted
     * \param index index of element after which will be inserted the new element
     */
    template <class T, class Allocator>
    void list<T, Allocator>::insert_after(const_ref value, const size_t& index)
    {
        if (front_ == nullptr)
            throw std::runtime_error("\nlist is empty!\n");
        
        node* new_node = new node(value, nullptr);

        auto it = begin();

        for (size_t count = 0; it.ptr->next != nullptr && count < index; ++it, ++count)
            if (it.ptr == nullptr)
                throw std::runtime_error("\ninsert_after(nullptr)!\n");

        if (it.ptr->next == nullptr)
        {
            it.ptr->next = new_node;
            back_ = it.ptr->next;
            ++size_;
            return;
        }

        node* after_insert_node = it.ptr->next;
        new_node->next = after_insert_node;
        it.ptr->next = new_node;

        ++size_;
    }

    template <class T, class Allocator>
    void list<T, Allocator>::print_list()
    {
        if (empty())
            throw std::runtime_error("\nList is empty!\n");

        size_t i = 0;
        for (auto& it : *this)
            std::cout << "it(" << i++ << "): " << it << "\n";
    }

    template <class T, class Allocator>
    void list<T, Allocator>::sort()
    {
        if (front_ == nullptr)
            throw std::runtime_error("\nlist is empty!\n");
        
        shell_sort(*this);
    }
    
    template <class T, class Allocator>
    void list<T, Allocator>::unique()
    {
        if (front_ == nullptr)
            throw std::runtime_error("\nlist is empty!\n");
        
        node** ptr_ptr_node = new node*[size_];
        const auto idx_ptr_ptr_node = new size_t[size_ * 2];
        
        //copy pointers to node in pointer of pointers
        auto it = begin();
        for (size_t i = 0; i < size_; ++it, ++i)
            ptr_ptr_node[i] = it.ptr;

        //search idxes of non unique element
        size_t idx_count = 0;
        for (size_t i1 = 0, cycle_t = 0, cycle_dif_idx = 0; i1 < size_ - 1; ++i1)
        {
            if (i1 == 0)
                for (size_t i2 = i1; ptr_ptr_node[i2]->next != nullptr; ++i2, ++cycle_t)
                    if (ptr_ptr_node[i1]->data == ptr_ptr_node[i2]->next->data)
                        idx_ptr_ptr_node[idx_count++ - cycle_dif_idx] = i2 + 1;
            
            for (size_t i2 = i1; ptr_ptr_node[i2]->next->next != nullptr; ++i2, ++cycle_t)
                if (ptr_ptr_node[i1]->next->data == ptr_ptr_node[i2]->next->next->data)
                    idx_ptr_ptr_node[idx_count++ - cycle_dif_idx] = i2 + 2;
            
            if (cycle_t > size_)
            {
                unique_idx(idx_count, idx_ptr_ptr_node);
                cycle_t = 0;
            }
        }
        
        unique_idx(idx_count, idx_ptr_ptr_node);
        
        //remove nodes by idx
        for (size_t i = 0; i < idx_count; ++i)
        {
            it = begin();
            
            for (size_t i1 = 0; it != end(), i1 < idx_ptr_ptr_node[i] - 1 - i; ++it, ++i1){}
                
            auto temp = it.ptr->next;
            it.ptr->next = it.ptr->next->next;
            delete temp;
            
            // back_ = it.back_;
            --size_;
        }

        it = begin();
        
        while (it.ptr->next != nullptr)
            ++it;
        back_ = it.ptr;
        
        delete[] ptr_ptr_node;
    }

    template <class T, class Allocator>
    void list<T, Allocator>::merge(const list& right)
    {
        if (front_ == nullptr)
            throw std::runtime_error("\nlist is empty!\n");
        
        for (auto it = right.begin(); it != right.end(); ++it)
            push_front(it.ptr->data);
    }

    template <class T, class Allocator>
    void list<T, Allocator>::clear()
    {
        while (!empty())
            pop_front();
    }

    template <class T, class Allocator>
    bool list<T, Allocator>::empty() const
    {
        return size_ == 0;
    }

    template <class T, class Allocator>
    size_t list<T, Allocator>::size() const
    {
        return size_;
    }

    template <class T, class Allocator>
    typename list<T, Allocator>::ref list<T, Allocator>::operator[](const size_t index)
    {
        auto it = begin();
        for(size_t count = 0; it != end() && count < index; ++it, ++count) {}
        return it.ptr->data;
    }

    template <class T, class Allocator>
    list<T, Allocator>& list<T, Allocator>::operator=(const list& right)
    {
        if (right.front_ == nullptr)
            throw std::runtime_error("\nright list is empty!\n");
        
        list temp;
        for (auto it = right.begin(); it != right.end(); ++it)
            temp.push_front(it.ptr->data);
        
        for (auto it = temp.begin(); it != temp.end(); ++it)
            push_front(it.ptr->data);
        
        return *this;
    }

    template <class T, class Allocator>
    list<T, Allocator>::iterator::iterator(): ptr(nullptr), pos_now_(0), front_(nullptr), back_(nullptr) {}

    template <class T, class Allocator>
    list<T, Allocator>::iterator::iterator(auto begin): ptr(begin), pos_now_(0), front_(begin), back_(begin)
    {
        while (back_ != nullptr)
            back_ = back_->next;
    }

    template <class T, class Allocator>
    list<T, Allocator>::iterator::~iterator() {}

    template <class T, class Allocator>
    bool list<T, Allocator>::iterator::operator==(const iterator& right) const
    {
        return ptr == right.ptr;
    }

    template <class T, class Allocator>
    typename list<T, Allocator>::ref list<T, Allocator>::iterator::operator*()
    {
        if (ptr == nullptr)
            throw std::runtime_error("\nOut of range!\n");

        return ptr->data;
    }

    template <class T, class Allocator>
    typename list<T, Allocator>::iterator& list<T, Allocator>::iterator::operator++()
    {
        if (ptr == nullptr)
            throw std::runtime_error("\nOut of range!(operator++ preincrement)\n");

        ++pos_now_;
        ptr = ptr->next;
        return *this;
    }

    template <class T, class Allocator>
    typename list<T, Allocator>::iterator list<T, Allocator>::iterator::operator++(int)
    {
        if (ptr == nullptr)
            throw std::runtime_error("\nOut of range!(operator++ postincrement)\n");

        auto old = *this;
        ++ptr;
        return old;
    }

    template <class T, class Allocator>
    size_t list<T, Allocator>::iterator::pos() const
    {
        return pos_now_;
    }
}
