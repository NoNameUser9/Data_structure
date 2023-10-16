#pragma once

template<typename T>
class Deque
{
public:
    Deque();
    ~Deque();
    [[nodiscard]] bool empty() const;
    [[nodiscard]] uint32_t get_size() const;
    void push_front(const T& value);
    void push_back(const T& value);
    void pop_front();
    void pop_back();
    [[nodiscard]] const T& get_front() const;
    [[nodiscard]] const T& get_back() const;
private:
    struct node
    {
        T data;
        node* prev;
        node* next;
    };

    node* front_;
    node* back_;
    uint32_t size_;
};

template <typename T>
Deque<T>::Deque(): front_(nullptr), back_(nullptr), size_(0){}

template <typename T>
Deque<T>::~Deque()
{
    while (!empty())
        pop_front();
}

template <typename T>
bool Deque<T>::empty() const
{
    return size_ == 0;
}

template <typename T>
uint32_t Deque<T>::get_size() const
{
    return size_;
}

template <typename T>
void Deque<T>::push_front(const T& value)
{
    node* new_node = new node;
    new_node->data = value;
    new_node->prev = nullptr;
    new_node->next = front_;

    if (empty())
        back_ = new_node;
    else
        front_->prev = new_node;

    front_ = new_node;
    size_++;
}

template <typename T>
void Deque<T>::push_back(const T& value)
{
    node* new_node = new node;
    new_node->data = value;
    new_node->prev = back_;
    new_node->next = nullptr;

    if (empty())
        front_ = new_node;
    else
        back_->next = new_node;
    
    back_ = new_node;
    size_++;
}

template <typename T>
void Deque<T>::pop_front()
{
    if (empty())
    {
        std::cout << "Deque is empty!" << std::endl;
        return;
    }

    const node* temp = front_;
    front_ = front_->next;

    if (front_ == nullptr)
        back_ = nullptr;
    else
        front_->prev = nullptr;

    delete temp;
    size_--;
}

template <typename T>
void Deque<T>::pop_back()
{
    if (empty())
    {
        std::cout << "Deque is empty!" << std::endl;
        return;
    }

    const node* temp = back_;
    back_ = back_->prev;

    if (back_ == nullptr)
        front_ = nullptr;
    else
        back_->next = nullptr;

    delete temp;
    size_--;
}

template <typename T>
const T& Deque<T>::get_front() const
{
    if (empty())
        throw std::runtime_error("Deque is empty!");
    return front_->data;
}

template <typename T>
const T& Deque<T>::get_back() const
{
    if (empty())
        throw std::runtime_error("Deque is empty!");
    return back_->data;
}