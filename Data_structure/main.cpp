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

                stack.push(10);
                stack.push(20);
                stack.push(30);

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

                for (size_t i = 0; i < deque.size(); ++i)
                    std::cout << deque[i] << '\n';
                
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
                std::cout << "\nList:\n\n";

                NNU9::list<my_type> list;
                std::list<my_type> l;
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
            
                list.push_front(3);
                list.push_front(13);


                list.push_front(5);
                list.push_front(53);
                list.push_front(1);
                list.push_front(12);

                NNU9::list<my_type> list2 = list;
                list2.push_front(32);
                list2.push_front(32);
                list2.push_front(32);
                list2.push_front(1);
                list2.push_front(15);
                list2.push_front(523);
                list2.push_front(19);
                list2.push_front(21);

                t.start();
                list.merge(list2);
                t.end();
                std::cout << "\ntime for merge:" << t.difference() << '\n';

                t.start();
                list.sort();
                t.end();
                std::cout << "\ntime for sort:" << t.difference() << '\n';
                
                list.insert_after(315, 11);
                std::cout << "\nsize: " << list.size() << "\n";
                i = 0;
                for (const int& it : list)
                    std::cout << "it(" << i++ << "): " << it << "\n";

                list.sort();
                std::cout << "\nsize: " << list.size() << "\n";
                std::cout << "\nback: " << list.back() << "\n\n";

                list.print_list();
                std::cout << '\n';
                list.unique();
                std::cout << binary_search(list, 523);
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
            exit(EXIT_SUCCESS);
        default:
            break;
        }
    }

    


    
    return 0;
}
