#pragma once

template<class T>
class queue  // NOLINT(cppcoreguidelines-special-member-functions)
{
public:
    queue();
    ~queue();
    [[nodiscard]] bool empty() const;
    [[nodiscard]] size_t size() const;
    void push(const T& value);
    void pop();
    T front();
    T back();
protected:
    struct node
    {
        T data;
        node* next;
    };
    node* front_;
    size_t size_;
};