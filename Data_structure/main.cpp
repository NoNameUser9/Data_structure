#include <iostream>
#include <list>
#include "stack.hpp"
#include "queue.hpp"
#include "deque.hpp"
#include "forward_list.hpp"

typedef int my_type;

int main(int argc, char* argv[])
{

    {
        NNU9::stack<my_type> stack;
        std::cout << "\nbefore:\n";

        stack.push(10);
        stack.push(20);
        stack.push(30);
        // stack.emplace(10);


        stack.pop();
        stack.pop();
        // stack.pop();
        // stack.pop();
        // stack.pop();

        std::cout << "Size of the stack after popping: " << stack.size() << std::endl;
        std::cout << "Top element after popping: " << stack.top() << std::endl;
    }

    {
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
        NNU9::deque<my_type> deque;


        deque.push_front(1);
        deque.push_back(2);
        deque.push_front(3);

        std::cout << "Front: " << deque.front() << std::endl;
        std::cout << "Back: " << deque.back() << std::endl;

        deque.pop_front();
        deque.pop_back();
        std::cout << "\n\n5 elem: " << deque.at(0) << "\n\n";
        // deque.pop_back();
        // deque.pop_back();
        // deque.pop_back();
        // deque.pop_back();

        std::cout << "Size: " << deque.size() << std::endl;
    }

    {
        std::list<my_type> l;
        NNU9::list<my_type> list;

        // l.begin();
        // for (auto it = l.begin(); it != l.end(); ++it)
            // std::cout << it.;
        
        list.push_front(3);
        list.push_front(2);
        list.push_front(1);
        
        // list.print_list();
        
        list.pop_front();
        
        // list.print_list();

    }
    // std::cout << "\n\nempty: " << st.empty() << "\n\n";
    //
    // std::cout << "\n1111111111";
    // auto temp = new int[st.size()];
    // std::cout << "size: " << st.size() << "\n";
    // while (!st.empty())
    //     temp[st.size() - 1] = st.pop();
    // for (int i = 0; i < size; ++i)
    //     std::cout << temp[i] << "\n";
    // // for (int i = 0; i < size; ++i)
    // //     st.push(temp[i]);
    // delete[] temp;
    
    //
    // std::cout << "\nasl;fkskf";
    // size = st2.size();
    // temp = new int[st2.size()];
    // while (!st2.empty())
    //     temp[st2.size()] = st2.pop();
    // for (int i = 0; i < size; ++i)
    //     std::cout << temp[size - i - 1];
    // for (int i = 0; i < size; ++i)
    //     st2.push(temp[i]);
    // delete[] temp;
    
    
    
    // st.swap(st2);
    // st.emplace(in[2]);
    
    // std::cout << "\nafter:\n";
    // while (!st.empty())
    //     std::cout << st.pop();
    // std::cout << "\n";
    // while (!st2.empty())
    //     std::cout << st2.pop();
    
    
    
    return 0;
}
