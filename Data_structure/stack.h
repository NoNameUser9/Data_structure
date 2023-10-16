#pragma once

template <typename T>
// ReSharper disable once CppInconsistentNaming
class Stack {
private:
    struct Node
    {
        T data;
        Node* next;

        explicit Node(const T& value, Node* next = nullptr);
    };

    Node* topNode;

public:
    Stack();

    ~Stack();

    void push(const T& value);

    void pop();

    [[nodiscard]] T& top() const;

    [[nodiscard]] bool empty() const;

    [[nodiscard]] size_t size() const;
};

template <typename T>
Stack<T>::Node::Node(const T& value, Node* next): data(value), next(next)
{}

template <typename T>
Stack<T>::Stack(): topNode(nullptr)
{}

template <typename T>
Stack<T>::~Stack()
{
    while (!empty())
        pop();
}

template <typename T>
void Stack<T>::push(const T& value)
{
    Node* newNode = new Node(value, topNode);
    topNode = newNode;
}

template <typename T>
void Stack<T>::pop()
{
    if (!empty())
        topNode = topNode->next;
}

template <typename T>
T& Stack<T>::top() const
{
    if (!empty())
        return topNode->data;
    throw std::runtime_error("Stack is empty");
}

template <typename T>
bool Stack<T>::empty() const
{
    return topNode == nullptr;
}

template <typename T>
size_t Stack<T>::size() const
{
    size_t count = 0;
    Node* current = topNode;
    while (current != nullptr)
    {
        count++;
        current = current->next;
    }
    return count;
}