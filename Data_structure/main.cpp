#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <windows.h>
#include "deque_generic/stack.hpp"
#include "deque_generic/queue.hpp"
#include "deque_generic/deque.hpp"
#include "list/forward_list.hpp"
#include "supporting_finctions/time.hpp"
#include "binary_search.hpp"

typedef int my_type;

int main(int argc, char* argv[])
{
    const size_t size = static_cast<size_t>(rand())%100;
    
    auto init_arr = new my_type[size];
    for (size_t i = 0; i < size; ++i)
        init_arr[i] = rand();
    
    while (true)
    {
        home:
        system("cls");
        // ClearScreen();
        size_t sw1 = 0;
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

                std::cout << "\nStack:\n\n";
                
                NNU9::stack<my_type> stack;
                for (size_t i = 0; i < size; ++i)
                    stack.push(init_arr[i]);

                std::stack<my_type> st;
                for (size_t i = 0; i < size; ++i)
                    st.push(init_arr[i]);

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

                NNU9::queue<my_type> queue;
                for (size_t i = 0; i < size; ++i)
                    queue.push(init_arr[i]);
                
                std::queue<my_type> que;
                for (size_t i = 0; i < size; ++i)
                    que.push(init_arr[i]);
                
                for (size_t i = 0; i < size; ++i)
                    queue.push(init_arr[i]);
                std::cout << "Front element: " << queue.front() << std::endl;

                queue.pop();

                std::cout << "Front element: " << queue.front() << std::endl;
                
                system("pause");
                break;
            }
        case 3:
            {
                // case3:
                system("cls");
                std::cout << "\nDeque:\n"
                             "1.time test\n"
                             "2.show list\n"
                             "3.pop\n"
                             "4.exit\n";

                NNU9::deque<my_type> deque;
                for (size_t i = 0; i < size; ++i)
                    deque.push_back(init_arr[i]);
                
                std::deque<my_type> deq;
                for (size_t i = 0; i < size; ++i)
                    deq.push_back(init_arr[i]);

                while (true)
                {
                    size_t sw3;
                    std::cin >> sw3;
                    switch (sw3)
                    {
                    case 1:
                        {
                            system("cls");

                            deque.clear();
                            NNU9::time t;
                            t.start();
                            for (size_t i = 0; i < size; ++i)
                                deque.push_front(init_arr[i]);
                            t.end();
                            std::cout << "\ntime NNU9::deque.push_front() for " << deque.size() << " elements: " << t.difference() << '\n';

                            std::cout << "\ntime NNU9::deque.pop_front() for " << deque.size() << '\n';
                            t.start();
                            for (size_t i = 0; i < size; ++i)
                                deque.pop_front();
                            t.end();
                            std::cout << " elements: " << t.difference() << '\n';

                            t.start();
                            for (size_t i = 0; i < size; ++i)
                                deque.push_back(init_arr[i]);
                            t.end();
                            std::cout << "\ntime NNU9::deque.push_back() for " << deque.size() << " elements: " << t.difference() << '\n';

                            std::cout << "\ntime NNU9::deque.pop_back() for " << deque.size() << '\n';
                            t.start();
                            for (size_t i = 0; i < size; ++i)
                                deque.pop_back();
                            t.end();
                            std::cout << " elements: " << t.difference() << '\n';
                            
                            for (size_t i = 0; i < deque.size(); ++i)
                                std::cout << "it(" << i << ")" << deque[i] << '\n';

                            t.start();
                            for (size_t i = 0; i < size; ++i)
                                deq.push_front(init_arr[i]);
                            t.end();
                            std::cout << "\ntime std::deque.push_front() for " << deq.size() << " elements: " << t.difference() << '\n';

                            std::cout << "\ntime std::deque.pop_front() for " << deq.size() << '\n';
                            t.start();
                            for (size_t i = 0; i < size; ++i)
                                deq.pop_front();
                            t.end();
                            std::cout << " elements: " << t.difference() << '\n';

                            t.start();
                            for (size_t i = 0; i < size; ++i)
                                deq.push_back(init_arr[i]);
                            t.end();
                            std::cout << "\ntime std::deque.push_back() for " << deq.size() << " elements: " << t.difference() << '\n';

                            std::cout << "\ntime std::deque.pop_back() for " << deq.size() << '\n';
                            t.start();
                            for (size_t i = 0; i < size; ++i)
                                deq.pop_back();
                            t.end();
                            std::cout << " elements: " << t.difference() << '\n';
                            system("pause");
                            // system("cls");
                            // goto case3;
                            break;
                        }
                    case 2:
                        {
                            system("cls");
                            for (size_t i = 0; i < deque.size(); ++i)
                                std::cout << "it(" << i << "): " << deque.at(i) << '\n';
                            system("pause");
                            break;
                        }
                    case 3:
                        {
                            try
                            {
                                std::cout << "Front: " << deque.front() << std::endl
                                << "Back: " << deque.back() << std::endl;
                            }
                            catch (std::exception& ex)
                            {
                                std::cerr << ex.what();
                            }

                            try
                            {
                                deque.pop_front();
                                deque.pop_back();
                                
                                std::cout << "\n0 elem: " << deque.at(0) << "\n\n"
                                << "Size: " << deque.size() << std::endl;
                            }
                            catch (std::exception& ex)
                            {
                                std::cerr << ex.what();
                            }
                            
                            system("pause");
                            break;
                        }
                    case 4:
                        goto home;
                    default:
                        break;
                    }
                }
            }
        case 4:
            {
                system("cls");
                // ClearScreen();
                std::cout << "\nDeque:\n"
                             "1.time test\n"
                             "2.show list\n"
                             "3.pop\n"
                             "4.exit\n";
                NNU9::time t;
                NNU9::list<my_type> list;
                std::list<my_type> l;
                
                size_t sw4;
                std::cin >> sw4;
                switch (sw4)
                {
                case 1:
                    {
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
                            std::cout << "\nbinary_search(): " << binary_search(list, 523) << '\n';
                        }
                        catch (std::exception& ex)
                        {
                            std::cerr << ex.what();
                        }
                        t.end();
                        std::cout << "\ntime for NNU9::binary_search(list, 523) for " << list.size() << " elements: " << t.difference() << '\n';
                        
                        break;
                    }
                case 2:
                    {
                        for (size_t i = 0; i < size; ++i)
                            list.push_front(init_arr[i]);
                        
                        try
                        {
                            list.print_list();
                        }
                        catch (std::exception& ex)
                        {
                            std::cerr << ex.what();
                        }
                        
                        std::cout << "\nsize: " << list.size() << "\n";
                        try
                        {
                            size_t i = 0;
                            for (const int& it : list)
                                std::cout << "it(" << i++ << "): " << it << "\n";
                            
                        }
                        catch (std::exception& ex)
                        {
                            std::cerr << ex.what();
                        }
                        break;
                    }
                default:
                    break;
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
}
