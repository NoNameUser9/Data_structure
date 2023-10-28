#include <iostream>
#include <list>
#include "deque_generic/stack.hpp"
#include "deque_generic/queue.hpp"
#include "deque_generic/deque.hpp"
#include "list/forward_list.hpp"
#include "supporting_finctions/time.hpp"
#include "binary_search.hpp"

typedef int my_type;

int main(int argc, char* argv[])
{
    const size_t size = static_cast<size_t>(rand())%10;
    // auto arr = new my_type[size];
    // delete[] arr;
    
    auto init_arr = new my_type[size];
    for (size_t i = 0; i < size; ++i)
        init_arr[i] = rand();
    
    while (true)
    {
        size_t sw1 = 0;
        system("cls");
        std::cout << "Program Data_Structure ver: 1.0.0\n"
                     "1.stack\n"
                     "2.queue\n"
                     "3.deque\n"
                     "4.forward_list\n"
                     "5.exit\n";
        std::cin >> sw1;
        switch (sw1)
        {
        case 1:
            {
                system("cls");

                NNU9::stack<my_type> stack;
                std::cout << "\nStack:\n\n";

                // stack.push(10);
                // stack.push(20);
                // stack.push(30);

                for (size_t i = 0; i < size; ++i)
                    stack.push(init_arr[i]);

                stack.pop();
                stack.pop();

                std::cout << "Size of the stack after popping: " << stack.size() << std::endl;
                std::cout << "Top element after popping: " << stack.top() << std::endl;
                
                system("pause");
                break;
            }
        case 2:
            {
                system("cls");

                std::cout << "\nQueue:\n\n";

                NNU9::queue<my_type> queue = {1,5,7};

                for (size_t i = 0; i < size; ++i)
                    queue.push(init_arr[i]);
                
                queue.push(10);
                queue.push(20);
                queue.push(30);

                std::cout << "Front element: " << queue.front() << std::endl;

                queue.pop();

                std::cout << "Front element: " << queue.front() << std::endl;

                system("pause");
                break;
            }
        case 3:
            {
                system("cls");

                std::cout << "\nDeque:\n\n";
                NNU9::deque<my_type> deque = {1, 5, 23,6};
                for (size_t i = 0; i < size; ++i)
                    deque.push_back(init_arr[i]);
                
                for (size_t i = 0; i < deque.size(); ++i)
                    std::cout << "it(" << i << ")" << deque[i] << '\n';
                
                deque.push_front(1);
                deque.push_back(2);
                deque.push_front(3);

                std::cout << "Front: " << deque.front() << std::endl;
                std::cout << "Back: " << deque.back() << std::endl;

                deque.pop_front();
                deque.pop_back();
                
                std::cout << "\n\n0 elem: " << deque.at(0) << "\n\n";
                std::cout << "Size: " << deque.size() << std::endl;

                system("pause");
                break;
            }
        case 4:
            {
                system("cls");

                NNU9::time t;
                NNU9::list<my_type> list;
                std::list<my_type> l;

                t.start();
                std::cout << "\nList:\n";
                for (size_t i = 0; i < size; ++i)
                    list.push_front(init_arr[i]);
                t.end();
                std::cout << "\ntime std::list.push_front() for " << size << " elements: " << t.difference();

                t.start();
                for (size_t i = 0; i < size; ++i)
                    l.push_front(init_arr[i]);
                t.end();
                std::cout << "\ntime std::list.push_front() for " << size << " elements: " << t.difference();
                
                size_t i = 0;
                try
                {
                    for (const int& it : list)
                        std::cout << "it(" << i++ << "): " << it << "\n";
                }
                catch (std::exception& ex)
                {
                    std::cerr << ex.what();
                }
                
                
                t.start();
                NNU9::list<my_type> list2 = list;
                t.end();
                std::cout << "\ntime NNU9::list.operator= for " << list2.size() << " elements: " << t.difference();
   

                t.start();
                list.merge(list2);
                t.end();
                std::cout << "\ntime for NNU9::list.merge() for " << list.size() << " elements: " << t.difference() << '\n';

                t.start();
                list.sort();
                t.end();
                std::cout << "\ntime for NNU9::list.sort() for " << list.size() << " elements: " << t.difference() << '\n';

                t.start();
                list.insert_after(315, 11);
                t.end();
                std::cout << "\ntime for NNU9::list.insert_after() for " << list.size() << " elements: " << t.difference() << '\n';
                
                std::cout << "\nsize: " << list.size() << "\n";
                i = 0;
                for (const int& it : list)
                    std::cout << "it(" << i++ << "): " << it << "\n";

                list.sort();
                std::cout << "\nsize: " << list.size() << "\n";
                std::cout << "\nback: " << list.back() << "\n\n";

                list.print_list();
                std::cout << '\n';
                t.start();
                list.unique();
                t.end();
                std::cout << "\ntime for NNU9::list.unique() for " << list.size() << " unique elements: " << t.difference() << '\n';

                t.start();
                try
                {
                    std::cout << binary_search(list, 523);
                }
                catch (std::exception& ex)
                {
                    std::cerr << ex.what();
                }
                t.end();
                std::cout << "\ntime for NNU9::binary_search(list, 523) for " << list.size() << " elements: " << t.difference() << '\n';

                std::cout << '\n';
                list.print_list();
                list.clear();
                
                try
                {
                    list.print_list();
                }
                catch (std::exception& ex)
                {
                    std::cerr << ex.what();
                }

                system("pause");
                break;
            }
        case 5:
            delete[] init_arr;
            exit(EXIT_SUCCESS);
        default:
            break;
        }
    }

    


    
    return 0;
}
