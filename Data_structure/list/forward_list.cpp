#include "../shell_sort.hpp"
#include "forward_list.hpp"
#include <iostream>

namespace NNU9
{
    template list<int>;
    template list<float>;
    template list<char>;
    template list<bool>;
    template list<std::string>;

    template <class T, class Allocator>
    list<T, Allocator>::list(): front_(nullptr), back_(front_), size_(0) {}

    template <class T, class Allocator>
    list<T, Allocator>::~list()
    {
        clear();
    }

    template <class T, class Allocator>
    void list<T, Allocator>::push_front(const_ref value)
    {
        auto new_node = new node{value, nullptr};

        if (size_ == 0)
        {
            front_ = new_node;
            back_ = front_;
            ++size_;
            return;
        }

        new_node->next = front_;
        front_ = new_node;
        ++size_;
    }

    template <class T, class Allocator>
    void list<T, Allocator>::push_front(ref value)
    {
        push_front(static_cast<const_ref>(value));
    }

    template <class T, class Allocator>
    void list<T, Allocator>::pop_front()
    {
        try
        {
            if (empty())
                throw std::runtime_error("\nList is empty!\n");

            const node* pop_node = front_;
            front_ = front_->next;
            delete pop_node;

            --size_;
        }
        catch (std::runtime_error& ex)
        {
            std::cerr << ex.what();
        }
    }

    template <class T, class Allocator>
    typename list<T, Allocator>::iterator list<T, Allocator>::begin()
    {
        iterator ret(front_);
        return ret;
    }

    template <class T, class Allocator>
    typename list<T, Allocator>::iterator list<T, Allocator>::begin() const
    {
        return begin();
    }

    template <class T, class Allocator>
    typename list<T, Allocator>::iterator list<T, Allocator>::end()
    {
        iterator ret(back_->next);
        return ret;
    }

    template <class T, class Allocator>
    typename list<T, Allocator>::iterator list<T, Allocator>::end() const
    {
        return end();
    }

    template <class T, class Allocator>
    typename list<T, Allocator>::ref list<T, Allocator>::front()
    {
        return front_->data;
    }

    template <class T, class Allocator>
    typename list<T, Allocator>::ref list<T, Allocator>::back()
    {
        return back_->data;
    }

    /**
     * \brief 
     * \param value element which will be inserted
     * \param index index of element after which will be inserted the new element
     */
    template <class T, class Allocator>
    void list<T, Allocator>::insert_after(const T& value, const size_t& index)
    {
        try
        {
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
        catch (std::runtime_error& ex)
        {
            std::cerr << ex.what();
        }
        catch (...)
        {
            std::cerr << "\ninsert_after() error!\n";
        }
    }

    template <class T, class Allocator>
    void list<T, Allocator>::print_list()
    {
        try
        {
            if (empty())
                throw std::runtime_error("\nList is empty!\n");

            for (auto& it : *this)
                std::cout << "it: " << it << "\n";
        }
        catch (std::runtime_error& ex)
        {
            std::cerr << ex.what();
        }
    }

    template <class T, class Allocator>
    void list<T, Allocator>::sort()
    {
        shell_sort(*this);
    }
    
    /**
     * \note Not yet realized!
     */
    template <class T, class Allocator>
    void list<T, Allocator>::unique()
    {
        node** ptr_ptr_node = new node*[size_]{{nullptr}};
        const auto idx_ptr_ptr_node = new size_t[size_];
        
        //copy pointers to node in pointer of pointers
        auto it = begin();
        for (size_t i = 0; i < size_; ++it, ++i)
            ptr_ptr_node[i] = it.ptr;

        //search idxes of non unique element
        size_t idx_count = 0;
        for (size_t i1 = 0; i1 < size_ - 1; ++i1)
        {
            if (i1 == 0)
                for (size_t i2 = i1; ptr_ptr_node[i2]->next != nullptr; ++i2)
                    if (ptr_ptr_node[i1]->data == ptr_ptr_node[i2]->next->data)
                        idx_ptr_ptr_node[idx_count++] = i2 + 1;
            
            for (size_t i2 = i1; ptr_ptr_node[i2]->next->next != nullptr; ++i2)
                if (ptr_ptr_node[i1]->next->data == ptr_ptr_node[i2]->next->next->data)
                    idx_ptr_ptr_node[idx_count++] = i2 + 2;
        }

        //unique idx
        for (size_t i = 0; i < idx_count - 1; ++i)
            for (auto i2 = i + 1; i2 < idx_count; ++i2)
                if (idx_ptr_ptr_node[i] == idx_ptr_ptr_node[i2])
                    idx_ptr_ptr_node[i2] = 0;
        
        //slide idx
        for (size_t i = 0; i < idx_count; ++i)
            while (idx_ptr_ptr_node[i] == 0)
            {
                for (auto i2 = i; i2 < idx_count; ++i2)
                    idx_ptr_ptr_node[i2] = idx_ptr_ptr_node[i2 + 1];
                
                --idx_count;
            }

        for (size_t i = 0; i < 5; ++i)
            std::cout << idx_ptr_ptr_node[i] << '\n';
        
        //remove nodes by idx
        for (size_t i = 0; i < idx_count; ++i)
        {
            auto temp = new node;
            it = begin();
            for (size_t i1 = 0; it != end(), i1 < idx_ptr_ptr_node[i] - 1 - i; ++it, ++i1){}
                
            temp = it.ptr->next;
            it.ptr->next = it.ptr->next->next;
            delete temp;

            --size_;
        }
        
        delete[] ptr_ptr_node;
    }

    template <class T, class Allocator>
    void list<T, Allocator>::merge(list& list)
    {
        for (auto it = list.begin(); it != list.end(); ++it)
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
    list<T, Allocator>& list<T, Allocator>::operator=(list& right)
    {
        list temp;
        for (auto it = right.begin(); it != right.end(); ++it)
            temp.push_front(it.ptr->data);
        
        for (auto it = temp.begin(); it != temp.end(); ++it)
            push_front(it.ptr->data);

        return *this;
    }

    template <class T, class Allocator>
    list<T, Allocator>::iterator::iterator(): ptr(nullptr), front_(nullptr), back_(nullptr), pos_now_(0)
    {
    }

    template <class T, class Allocator>
    list<T, Allocator>::iterator::iterator(auto begin): ptr(begin), front_(begin), back_(begin), pos_now_(0)
    {
        while (back_ != nullptr)
            back_ = back_->next;
    }

    template <class T, class Allocator>
    bool list<T, Allocator>::iterator::operator==(const iterator& right) const
    {
        return ptr == right.ptr;
    }

    template <class T, class Allocator>
    // ReSharper disable once CppNotAllPathsReturnValue
    typename list<T, Allocator>::ref list<T, Allocator>::iterator::operator*()
    {
        try
        {
            if (ptr == nullptr)
                throw std::runtime_error("\nOut of range!\n");

            return ptr->data;
        }
        catch (std::runtime_error& ex)
        {
            std::cerr << ex.what();
        }
    }

    template <class T, class Allocator>
    // ReSharper disable once CppNotAllPathsReturnValue
    typename list<T, Allocator>::iterator& list<T, Allocator>::iterator::operator++()
    {
        try
        {
            if (ptr == nullptr)
                throw std::runtime_error("\nOut of range!(operator++ preincrement)\n");

            ++pos_now_;
            ptr = ptr->next;
            return *this;
        }
        catch (std::runtime_error& ex)
        {
            std::cerr << ex.what();
        }
    }

    template <class T, class Allocator>
    // ReSharper disable once CppNotAllPathsReturnValue
    typename list<T, Allocator>::iterator list<T, Allocator>::iterator::operator++(int)
    {
        try
        {
            if (ptr == nullptr)
                throw std::runtime_error("\nOut of range!(operator++ postincrement)\n");

            auto old = *this;
            ++ptr;
            return old;
        }
        catch (std::runtime_error& ex)
        {
            std::cerr << ex.what();
        }
    }
}
