#pragma once

template<typename T>
class deque  // NOLINT(cppcoreguidelines-special-member-functions)
{
typedef const unsigned long long num;
typedef T& reference;
typedef const T& const_reference;
public:
    deque();
    ~deque();
    [[nodiscard]] bool empty() const;
    [[nodiscard]] size_t size() const;
    const_reference at(num& ptr) const;
    reference at(num& ptr);
    void push_front(const T& value);
    void push_back(const T& value);
    void pop_front();
    void pop_back();
    void insert(){};
    void resize(const size_t& size);
    [[nodiscard]] const T& front() const;
    [[nodiscard]] const T& back() const;
private:
    struct node
    {
        T data;
        node* prev;
        node* next;
    };
    node* back_;
    node* front_;
    size_t size_;
};