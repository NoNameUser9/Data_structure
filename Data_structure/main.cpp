#include <iostream>
#include "deque_generic/stack.hpp"
#include "deque_generic/queue.hpp"
#include "deque_generic/deque.hpp"
#include "list/forward_list.hpp"

typedef int my_type;

int main(int argc, char* argv[])
{
    {
        NNU9::stack<my_type> stack;
        std::cout << "\nStack:\n\n";

        stack.push(10);
        stack.push(20);
        stack.push(30);
        // stack.emplace(10);

        stack.pop();
        stack.pop();

        std::cout << "Size of the stack after popping: " << stack.size() << std::endl;
        std::cout << "Top element after popping: " << stack.top() << std::endl;
    }

    {
        std::cout << "\nQueue:\n\n";

        NNU9::queue<my_type> queue;

        queue.push(10);
        queue.push(20);
        queue.push(30);

        std::cout << "Front element: " << queue.front() << std::endl;

        queue.pop();
        queue.pop();

        std::cout << "Front element: " << queue.front() << std::endl;
    }
    
    {
        std::cout << "\nDeque:\n\n";
        NNU9::deque<my_type> deque;

        deque.push_front(1);
        deque.push_back(2);
        deque.push_front(3);

        std::cout << "Front: " << deque.front() << std::endl;
        std::cout << "Back: " << deque.back() << std::endl;

        deque.pop_front();
        deque.pop_back();
        
        std::cout << "\n\n5 elem: " << deque.at(0) << "\n\n";
        std::cout << "Size: " << deque.size() << std::endl;
    }

    {
        std::cout << "\nList:\n\n";

        NNU9::list<my_type> list;
        NNU9::list<my_type> list2;
        
        list.push_front(3);
        list.push_front(13);
        list.push_front(5);
        list.push_front(53);
        list.push_front(1);
        list.push_front(12);

        list2.push_front(32);
        list2.push_front(1);
        list2.push_front(15);
        list2.push_front(523);
        list2.push_front(19);
        list2.push_front(21);

        list.merge(list2);
        list.sort();
        list.insert_after(315, 11);
        std::cout << "\nsize: " << list.size() << "\n";
        for (const int& it : list)
            std::cout << "it: " << it << "\n";

        // list.sort();
        std::cout << "\nsize: " << list.size() << "\n";
        std::cout << "\nback: " << list.back() << "\n\n";
        
        list.print_list();
        list.clear();
        list.print_list();
    }
    
    return 0;
}
