#pragma once

template<class T>
class Queue
{
public:
    Queue();
    ~Queue();
    bool empty();
    void enqueue(T value);
    void dequeue();
    T get_front();
private:
    struct node
    {
        T data;
        node* next;
    };
    node* front_;
    node* rear_;
};