﻿#pragma once
#include <iostream>

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

template <class T>
LinkedList<T>::LinkedList(): head_(nullptr){}

template <class T>
LinkedList<T>::~LinkedList()
{
    while (head_ != nullptr)
        pop_front();
}

template <class T>
void LinkedList<T>::push_front(T value)
{
    node* new_node = new node;
    new_node->data = value;
    new_node->next = head_;
    head_ = new_node;
}

template <class T>
void LinkedList<T>::pop_front()
{
    if (head_ == nullptr) {
        std::cout << "Список пуст!" << std::endl;
        return;
    }
    const node* temp = head_;
    head_ = head_->next;
    delete temp;
}

template <class T>
void LinkedList<T>::print_list()
{
    node* current = head_;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}