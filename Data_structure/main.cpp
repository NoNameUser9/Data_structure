#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <windows.h>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>
// #include "opencv2/"

#define VER "1.4.1"
// #include <valarray>

#include "binary_tree/binary_search.hpp"
#include "binary_tree/binary_tree.h"
#include "deque_generic/deque.hpp"
#include "deque_generic/queue.hpp"
#include "deque_generic/stack.hpp"
#include "list/forward_list.hpp"
#include "supporting_finctions/bynary_tree_draw.h"
#include "supporting_finctions/io.h"
#include "supporting_finctions/struct.h"
#include "supporting_finctions/time.hpp"
#include "supporting_finctions/typedef.h"

  
std::string path = "C:\\Users\\User\\Documents\\Data_structure.csv";
auto nt = new node_time[10];
Table table(12, 3);

int main(int argc, char* argv[])
{
    std::stringstream ss;
    read_vec(table, path);
    srand(time(NULL));
    size_t t_s = rand()%10;
    while (t_s < 2000)
        t_s = rand()%5000;
 
    const size_t size = t_s;
    auto init_arr = new my_type[size];
    for (size_t i = 0; i < size; ++i)
        init_arr[i] = rand()%1000;
    NNU9::list<size_t> time_list;
    NNU9::list<my_type> ll;
    for (size_t i = 0; i < size; ++i)
        ll.push_front(init_arr[i]);
    
    while (true)
    {
        home:
        system("cls");
        // ClearScreen();
        size_t sw1 = 0;
        std::cout << "Program Data_Structure ver: "
        VER"\n"
                     "1.stack\n"
                     "2.queue\n"
                     "3.deque\n"
                     "4.forward_list\n"
                     "5.binary_tree\n"
                     "6.exit\n";
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
                            nt[0] = sort_type::deque_puf;
                            nt[0].set_time_NNU9(t.difference());
                            
                            std::cout << "\ntime NNU9::deque.pop_front() for " << deque.size() << '\n';
                            t.start();
                            for (size_t i = 0; i < size; ++i)
                                deque.pop_front();
                            t.end();
                            std::cout << " elements: " << t.difference() << '\n';
                            nt[1] = sort_type::deque_pf;
                            nt[1].set_time_NNU9(t.difference());
                            
                            t.start();
                            for (size_t i = 0; i < size; ++i)
                                deque.push_back(init_arr[i]);
                            t.end();
                            std::cout << "\ntime NNU9::deque.push_back() for " << deque.size() << " elements: " << t.difference() << '\n';
                            nt[2] = sort_type::deque_pub;
                            nt[2].set_time_NNU9(t.difference());
                            
                            std::cout << "\ntime NNU9::deque.pop_back() for " << deque.size() << '\n';
                            t.start();
                            for (size_t i = 0; i < size; ++i)
                                deque.pop_back();
                            t.end();
                            std::cout << " elements: " << t.difference() << '\n';
                            nt[3] = sort_type::deque_pb;
                            nt[3].set_time_NNU9(t.difference());
                            
                            for (size_t i = 0; i < deque.size(); ++i)
                                std::cout << "it(" << i << ")" << deque[i] << '\n';

                            t.start();
                            for (size_t i = 0; i < size; ++i)
                                deq.push_front(init_arr[i]);
                            t.end();
                            std::cout << "\ntime std::deque.push_front() for " << deq.size() << " elements: " << t.difference() << '\n';
                            // nt[0](sort_type::binary_search);
                            nt[0].set_time_std(t.difference());

                            std::cout << "\ntime std::deque.pop_front() for " << deq.size() << '\n';
                            t.start();
                            for (size_t i = 0; i < size; ++i)
                                deq.pop_front();
                            t.end();
                            std::cout << " elements: " << t.difference() << '\n';
                            nt[1].set_time_std(t.difference());

                            t.start();
                            for (size_t i = 0; i < size; ++i)
                                deq.push_back(init_arr[i]);
                            t.end();
                            std::cout << "\ntime std::deque.push_back() for " << deq.size() << " elements: " << t.difference() << '\n';
                            nt[2].set_time_std(t.difference());

                            std::cout << "\ntime std::deque.pop_back() for " << deq.size() << '\n';
                            t.start();
                            for (size_t i = 0; i < size; ++i)
                                deq.pop_back();
                            t.end();
                            std::cout << " elements: " << t.difference() << '\n';
                            nt[3].set_time_std(t.difference());

                            system("pause");
                            goto home;
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
                std::cout << "\nDeque:\n"
                             "1.time test\n"
                             "2.show list\n"
                             "3.pop\n"
                             "4.exit\n";
                NNU9::time t;
                NNU9::list<my_type> list;
                std::forward_list<my_type> l;
                std::forward_list<my_type> l2;
                
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
                        std::cout << "\ntime NNU9::list.push_front() for " << size << " elements: " << t.difference();
                        nt[4] = sort_type::list_puf;
                        nt[4].set_time_NNU9(t.difference());

                        for (size_t i = 0; i < size; ++i)
                            l2.push_front(init_arr[i]);
                        
                        t.start();
                        for (size_t i = 0; i < size; ++i)
                            l.push_front(init_arr[i]);
                        t.end();
                        std::cout << "\ntime std::list.push_front() for " << size << " elements: " << t.difference();
                        nt[4].set_time_std(t.difference());
                        
                        t.start();
                        NNU9::list<my_type> list2 = list;
                        t.end();
                        std::cout << "\ntime NNU9::list.operator= for " << list2.size() << " elements: " << t.difference();
                        
                        
                        t.start();
                        list.sort();
                        t.end();
                        std::cout << "\ntime for NNU9::list.sort() for " << list.size() << " elements: " << t.difference() << '\n';
                        nt[6] = sort_type::list_sort;
                        nt[6].set_time_NNU9(t.difference());

                        t.start();
                        l.sort();
                        t.end();
                        std::cout << "\ntime for std::list.sort() for " << l.max_size() << " elements: " << t.difference() << '\n';
                        nt[6].set_time_std(t.difference());
                        
                        t.start();
                        list.merge(list2);
                        t.end();
                        std::cout << "\ntime for NNU9::list.merge() for " << list.size() << " elements: " << t.difference() << '\n';
                        nt[5] = sort_type::list_merge;
                        nt[5].set_time_NNU9(t.difference());

                        l2.sort();
                        
                        t.start();
                        l.merge(l2);
                        t.end();
                        std::cout << "\ntime for std::list.merge() for " << l.max_size() << " elements: " << t.difference() << '\n';
                        nt[5].set_time_std(t.difference());
                        
                        t.start();
                        list.insert_after(315, 11);
                        t.end();
                        std::cout << "\ntime for NNU9::list.insert_after() for " << list.size() << " elements: " << t.difference() << '\n';
                        nt[7] = sort_type::list_ins_aft;
                        nt[7].set_time_NNU9(t.difference());
                        
                        list.sort();
                        std::cout << "\nsize: " << list.size() << "\n";
                        std::cout << "\nback: " << list.back() << "\n\n";

                        list.print_list();
                        std::cout << '\n';
                        t.start();
                        list.unique();
                        t.end();
                        nt[8] = sort_type::list_u;
                        nt[8].set_time_NNU9(t.difference());
                        std::cout << "\ntime for NNU9::list.unique() for " << list.size() << " unique elements: " << t.difference() << '\n';

                        std::cout << '\n';
                        t.start();
                        l.unique();
                        t.end();
                        nt[8].set_time_std(t.difference());
                        std::cout << "\ntime for std::list.unique() for " << l.max_size() << " unique elements: " << t.difference() << '\n';

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
                        nt[9] = sort_type::binary_search;
                        nt[9].set_time_NNU9(t.difference());
                        
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
            {
                BinaryTree<my_type> tree;
                tree = tree.create_balanced_tree(init_arr, 0, size);
                Node<my_type>* root = tree.get_root();
    
                // Создание изображения
                cv::Mat image(1000, 2500, CV_8UC3, cv::Scalar(255, 255, 255));
    
                // Отображение бинарного дерева
                drawBinaryTree(image, root, 1250, 50, 0, size);
    
                // Отображение изображения
                cv::imshow("Binary Tree", image);
                cv::waitKey(0);

                system("pause");
                break;
            }
        case 6:
            delete[] init_arr;
            table.at(11, 1) = std::to_string(size) + ';';
            write_vec(nt, table, path);
            exit(EXIT_SUCCESS);
        default:
            break;
        }
    }
}
