#pragma once

template<class T>
class LinkedList
{
public:
    LinkedList();
    ~LinkedList();
    void push_front(T value);
    void pop_front();
    void print_list();
private:
    struct node
    {
        T data;
        node* next;
    };
    node* head_;
};