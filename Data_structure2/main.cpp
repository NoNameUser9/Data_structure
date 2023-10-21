#include <iostream>
<<<<<<< Updated upstream
// #include <stack>
#include "stack.h"
=======
#include "stack.hpp"
#include "queue.hpp"
#include "deque.hpp"
#include "list.hpp"

typedef int my_type;
>>>>>>> Stashed changes

int main(int argc, char* argv[])
{
    // std::stack<int> cca;
    // cca.push(5);
    stack st{};
    stack st2{};
    stack st3{};
    int in[] = {5, 2, 13, 4, 21, 23,12,67,54};
    // int in2 = 2;
    // int in3 = 6;
    // int in4 = 9;
    st.push(in[0]);
    st.push(in[1]);
    st.push(in[2]);
    st2.push(in[3]);
    st2.push(in[4]);
    st3.push(in[5]);
    st3.push(in[6]);
    st3.push(in[7]);
    st3.push(in[8]);

<<<<<<< Updated upstream
    std::cout << "\nbefore:\n";
=======
        stack.push(10);
        stack.push(20);
        stack.push(30);
        // stack.emplace(10);
>>>>>>> Stashed changes

    // st.push(st2.pop());
    while (!st2.empty())
        st.push(st2.pop());

<<<<<<< Updated upstream
    // while (!st2.empty())
    //     st.push(st2.pop());
=======
        stack.pop();
        stack.pop();
        // stack.pop();
        // stack.pop();
        // stack.pop();

        std::cout << "Size of the stack after popping: " << stack.size() << std::endl;
        std::cout << "Top element after popping: " << stack.top() << std::endl;
    }

    {
        queue<my_type> queue;

        queue.push(10);
        queue.push(20);
        queue.push(30);

        std::cout << "Front element: " << queue.front() << std::endl;

        queue.pop();
        queue.pop();

        std::cout << "Front element: " << queue.front() << std::endl;
    }
>>>>>>> Stashed changes
    
    while (!st3.empty())
        st.push(st3.pop());

    
    
    // auto temp = new int[st.size()];
    auto size = st.size();
    // std::cout << "\nsize:" << st.size() << "\n";

    while (!st.empty())
    {
<<<<<<< Updated upstream
        std::cout << st.pop() << "\n";
=======
        deque<my_type> deque;

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
        list<my_type> list;
        
        list.push_front(3);
        list.push_front(2);
        list.push_front(1);
        
        // list.print_list();
        
        list.pop_front();
        
        // list.print_list();
>>>>>>> Stashed changes
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
