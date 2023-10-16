#include <iostream>
#include "stack.h"
#include "queue.h"
#include "deque.h"
#include "linked_list.h"

typedef int my_type;

int main(int argc, char* argv[])
{
    {
        Stack<my_type> stack;

        stack.push(10);
        stack.push(20);
        stack.push(30);

        std::cout << "Size of the stack: " << stack.size() << std::endl;
        std::cout << "Top element: " << stack.top() << std::endl;

        stack.pop();

        std::cout << "Size of the stack after popping: " << stack.size() << std::endl;
        std::cout << "Top element after popping: " << stack.top() << std::endl;
    }

    {
        Queue<my_type> queue;

        queue.enqueue(10);
        queue.enqueue(20);
        queue.enqueue(30);

        std::cout << "Front element: " << queue.get_front() << std::endl;

        queue.dequeue();
        queue.dequeue();

        std::cout << "Front element: " << queue.get_front() << std::endl;
    }
    
    {
        Deque<my_type> deque;

        deque.push_front(1);
        deque.push_back(2);
        deque.push_front(3);

        std::cout << "Front: " << deque.get_front() << std::endl;
        std::cout << "Back: " << deque.get_back() << std::endl;

        deque.pop_front();
        deque.pop_back();

        std::cout << "Size: " << deque.get_size() << std::endl;
    }

    {
        LinkedList<my_type> list;
        
        list.push_front(3);
        list.push_front(2);
        list.push_front(1);
        
        list.print_list();
        
        list.pop_front();
        
        list.print_list();
    }
    
    return 0;
}