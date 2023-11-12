// ReSharper disable CppClangTidyConcurrencyMtUnsafe
// ReSharper disable CppClangTidyClangDiagnosticUnusedLabel
// ReSharper disable CppClangTidyCppcoreguidelinesAvoidGoto
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <windows.h>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>
// #define DEBUG

#define VER "1.5.0"

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

  
const std::string path = "C:\\Users\\User\\Documents\\Data_structure.csv";
const size_t nt_size = 27;
const auto nt = new node_time[nt_size];
Table table(nt_size, 3);

int main(int argc, char* argv[])
{
    NNU9::time t;
    // std::stringstream ss;
    unsigned int ntn = 0;
    read_vec(table, path);
    
    for(size_t i = 0; i < nt_size - 1; ++i)
    {
        nt[i] = table.at(i + 1, 0);
        nt[i].set_time_std(std::stoul(table.at(i + 1, 1)));
        nt[i].set_time_NNU9(std::stoul(table.at(i + 1, 2)));
    }
    
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
        size_t sw1 = 0;
        std::cout << "Program Data_Structure ver: "
        VER"\n"
                     "1.stack\n"
                     "2.queue\n"
                     "3.deque\n"
                     "4.forward_list\n"
                     "5.binary_tree\n"
                     "6.print_time\n"
                     "7.exit\n";
        std::cin >> sw1;
        switch (sw1)
        {
        case 1:
            {
                ntn = 0;
                system("cls");

                std::cout << "\nStack:\n\n";
                
                NNU9::stack<my_type> stack;
                // stack.push;
                t.start();
                for (size_t i = 0; i < size; ++i)
                    stack.push(init_arr[i]);
                t.end();
                std::cout << "\ntime NNU9::stack.push_back() for " << stack.size() << " elements: " << t.difference() << '\n';
                nt[ntn] = sort_type::stack_pub;
                nt[ntn].set_time_NNU9(t.difference());

                std::stack<my_type> st;
                t.start();
                for (size_t i = 0; i < size; ++i)
                    st.push(init_arr[i]);
                t.end();
                std::cout << "\ntime std::stack.push_back() for " << st.size() << " elements: " << t.difference() << '\n';
                nt[ntn++].set_time_std(t.difference());

                // stack.size;
                t.start();
                auto ts = stack.size();
                t.end();
                nt[ntn] = sort_type::stack_sz;
                nt[ntn].set_time_NNU9(t.difference());

                t.start();
                auto tss = st.size();
                t.end();
                nt[ntn++].set_time_std(t.difference());

                // stack.top;
                t.start();
                int tp = stack.top();
                t.end();
                std::cout << "\ntime NNU9::stack.top() for " << stack.size() << " elements: " << t.difference() << '\n';
                nt[ntn] = sort_type::stack_top;
                nt[ntn].set_time_NNU9(t.difference());

                t.start();
                int tps = st.top();
                t.end();
                std::cout << "\ntime NNU9::stack.top() for " << st.size() << " elements: " << t.difference() << '\n';
                nt[ntn++].set_time_std(t.difference());
                
                std::cout << "\ntime std::stack.pop_back() for " << stack.size() << " elements: ";
                t.start();
                while (!stack.empty())
                    stack.pop();
                t.end();
                std::cout << t.difference() << '\n';
                nt[ntn] = sort_type::stack_pb;
                nt[ntn].set_time_NNU9(t.difference());

                t.start();
                std::cout << "\ntime std::stack.pop_back() for " << st.size() << " elements: ";
                while (!st.empty())
                    st.pop();
                t.end();
                std::cout << t.difference() << '\n';
                nt[ntn++].set_time_std(t.difference());

                std::cout << "Size of the stack after popping: " << stack.size() << std::endl;

                system("pause");
                break;
            }
        case 2:
            {
                system("cls");
                ntn = 4;
                std::cout << "\nQueue:\n\n";

                NNU9::queue<my_type> queue;
                t.start();
                for (size_t i = 0; i < size; ++i)
                    queue.push(init_arr[i]);
                t.end();
                nt[ntn] = sort_type::queue_pub;
                nt[ntn].set_time_NNU9(t.difference());
                
                std::queue<my_type> que;
                t.start();
                for (size_t i = 0; i < size; ++i)
                    que.push(init_arr[i]);
                t.end();
                nt[ntn++].set_time_std(t.difference());

                t.start();
                std::cout << "Front element(NNU9::): " << queue.front() << std::endl;
                t.end();
                nt[ntn] = sort_type::queue_f;
                nt[ntn].set_time_NNU9(t.difference());

                t.start();
                std::cout << "Front element(std::): " << que.front() << std::endl;
                t.end();
                nt[ntn++].set_time_std(t.difference());

                t.start();
                std::cout << "Back element(NNU9::): " << queue.back() << std::endl;
                t.end();
                nt[ntn] = sort_type::queue_b;
                nt[ntn].set_time_NNU9(t.difference());

                t.start();
                std::cout << "Back element(std::): " << que.back() << std::endl;
                t.end();
                nt[ntn++].set_time_std(t.difference());

                t.start();
                auto qs = queue.size();
                t.end();
                nt[ntn] = sort_type::queue_sz;
                nt[ntn].set_time_NNU9(t.difference());

                t.start();
                auto qss = que.size();
                t.end();
                nt[ntn++].set_time_std(t.difference());

                t.start();
                while (!queue.empty())
                    queue.pop();
                t.end();
                nt[ntn] = sort_type::queue_pf;
                nt[ntn].set_time_NNU9(t.difference());

                t.start();
                while (!que.empty())
                    que.pop();
                t.end();
                nt[ntn++].set_time_std(t.difference());

                system("pause");
                break;
            }
        case 3:
            {
                ntn = 9;
                system("cls");
                std::cout << "\nDeque:\n"
                             "1.time test\n"
                             "2.show list\n"
                             "3.pop\n"
                             "4.exit\n";

                NNU9::deque<my_type> deque;
                std::deque<my_type> deq;
                
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
                            deq.clear();
                            t.start();
                            for (size_t i = 0; i < size; ++i)
                                deque.push_front(init_arr[i]);
                            t.end();
                            std::cout << "\ntime NNU9::deque.push_front() for " << deque.size() << " elements: " << t.difference() << '\n';
                            nt[ntn] = sort_type::deque_puf;
                            nt[ntn].set_time_NNU9(t.difference());

                            t.start();
                            for (size_t i = 0; i < size; ++i)
                                deq.push_front(init_arr[i]);
                            t.end();
                            std::cout << "\ntime std::deque.push_front() for " << deq.size() << " elements: " << t.difference() << '\n';
                            nt[ntn++].set_time_std(t.difference());

                            std::cout << "\ntime NNU9::size() for " << deque.size() << " elements: ";
                            t.start();
                            auto ds = deque.size();
                            t.end();
                            std::cout << t.difference() << '\n';
                            nt[ntn] = sort_type::deque_sz;
                            nt[ntn].set_time_NNU9(t.difference());
                            
                            std::cout << "\ntime std::size() for " << deq.size() << " elements: ";
                            t.start();
                            auto dss = deq.size();
                            t.end();
                            std::cout << t.difference() << '\n';
                            nt[ntn++].set_time_std(t.difference());

                            std::cout << "\ntime std::front() for " << deque.size() << " elements: ";
                            t.start();
                            auto df = deque.front();
                            t.end();
                            std::cout << t.difference() << '\n';
                            nt[ntn] = sort_type::deque_f;
                            nt[ntn].set_time_NNU9(t.difference());

                            std::cout << "\ntime std::front() for " << deq.size() << " elements: ";
                            t.start();
                            auto dfs = deq.front();
                            t.end();
                            std::cout << t.difference() << '\n';
                            nt[ntn++].set_time_std(t.difference());

                            std::cout << "\ntime NNU9::front() for " << deque.size() << " elements: ";
                            t.start();
                            auto db = deque.back();
                            t.end();
                            std::cout << t.difference() << '\n';
                            nt[ntn] = sort_type::deque_b;
                            nt[ntn].set_time_NNU9(t.difference());

                            std::cout << "\ntime std::front() for " << deq.size() << " elements: ";
                            t.start();
                            auto dbs = deq.back();
                            t.end();
                            std::cout << t.difference() << '\n';
                            nt[ntn++].set_time_std(t.difference());

                            std::cout << "\ntime NNU9::clear() for " << deque.size() << " elements: ";
                            t.start();
                            deque.clear();
                            t.end();
                            std::cout << t.difference() << '\n';
                            nt[ntn] = sort_type::deque_cl;
                            nt[ntn].set_time_NNU9(t.difference());

                            std::cout << "\ntime std::clear() for " << deq.size() << " elements: ";
                            t.start();
                            deq.clear();
                            t.end();
                            std::cout << t.difference() << '\n';
                            nt[ntn++].set_time_std(t.difference());

                            for (size_t i = 0; i < size; ++i)
                                deque.push_front(init_arr[i]);
                
                            for (size_t i = 0; i < size; ++i)
                                deq.push_front(init_arr[i]);
                            
                            std::cout << "\ntime NNU9::deque.pop_front() for " << deque.size() << " elements: ";
                            t.start();
                            while (!deque.empty())
                                deque.pop_front();
                            t.end();
                            std::cout << t.difference() << '\n';
                            nt[ntn] = sort_type::deque_pf;
                            nt[ntn].set_time_NNU9(t.difference());

                            std::cout << "\ntime std::deque.pop_front() for " << deq.size() << " elements: ";
                            t.start();
                            while (!deq.empty())
                                deq.pop_front();
                            t.end();
                            std::cout << t.difference() << '\n';
                            nt[ntn++].set_time_std(t.difference());
                            
                            t.start();
                            for (size_t i = 0; i < size; ++i)
                                deque.push_back(init_arr[i]);
                            t.end();
                            std::cout << "\ntime NNU9::deque.push_back() for " << deque.size() << " elements: " << t.difference() << '\n';
                            nt[ntn] = sort_type::deque_pub;
                            nt[ntn].set_time_NNU9(t.difference());

                            t.start();
                            for (size_t i = 0; i < size; ++i)
                                deq.push_back(init_arr[i]);
                            t.end();
                            std::cout << "\ntime std::deque.push_back() for " << deq.size() << " elements: " << t.difference() << '\n';
                            nt[ntn++].set_time_std(t.difference());
                            
                            std::cout << "\ntime NNU9::deque.pop_back() for " << deque.size() << " elements: ";
                            t.start();
                            while (!deque.empty())
                                deque.pop_back();
                            t.end();
                            std::cout << t.difference() << '\n';
                            nt[ntn] = sort_type::deque_pb;
                            nt[ntn].set_time_NNU9(t.difference());

                            std::cout << "\ntime std::deque.pop_back() for " << deq.size() << " elements: ";
                            t.start();
                            while (!deq.empty())
                                deq.pop_back();
                            t.end();
                            std::cout << t.difference() << '\n';
                            nt[ntn++].set_time_std(t.difference());
                            
                            for (size_t i = 0; i < deque.size(); ++i)
                                std::cout << "it(" << i << ")" << deque[i] << '\n';
                            

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
                ntn = 17;
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
                        nt[ntn] = sort_type::list_puf;
                        nt[ntn].set_time_NNU9(t.difference());

                        t.start();
                        for (size_t i = 0; i < size; ++i)
                            l.push_front(init_arr[i]);
                        t.end();
                        std::cout << "\ntime std::list.push_front() for " << size << " elements: " << t.difference();
                        nt[ntn++].set_time_std(t.difference());

                        NNU9::list<my_type> list2 = list;

                        t.start();
                        list.sort();
                        t.end();
                        std::cout << "\ntime for NNU9::list.sort() for " << list.size() << " elements: " << t.difference() << '\n';
                        nt[ntn] = sort_type::list_sort;
                        nt[ntn].set_time_NNU9(t.difference());

                        t.start();
                        l.sort();
                        t.end();
                        std::cout << "\ntime for std::list.sort() for " << l.max_size() << " elements: " << t.difference() << '\n';
                        nt[ntn++].set_time_std(t.difference());
                        
                        t.start();
                        list.merge(list2);
                        t.end();
                        std::cout << "\ntime for NNU9::list.merge() for " << list.size() << " elements: " << t.difference() << '\n';
                        nt[ntn] = sort_type::list_merge;
                        nt[ntn].set_time_NNU9(t.difference());

                        l2.sort();
                        
                        t.start();
                        l.merge(l2);
                        t.end();
                        std::cout << "\ntime for std::list.merge() for " << l.max_size() << " elements: " << t.difference() << '\n';
                        nt[ntn++].set_time_std(t.difference());
                        
                        list.sort();
                        std::cout << "\nsize: " << list.size() << "\n";
                        std::cout << "\nback: " << list.back() << "\n\n";

                        list.print_list();
                        std::cout << '\n';
                        t.start();
                        list.unique();
                        t.end();
                        nt[ntn] = sort_type::list_u;
                        nt[ntn].set_time_NNU9(t.difference());
                        std::cout << "\ntime for NNU9::list.unique() for " << list.size() << " unique elements: " << t.difference() << '\n';

                        std::cout << '\n';
                        t.start();
                        l.unique();
                        t.end();
                        nt[ntn++].set_time_std(t.difference());
                        std::cout << "\ntime for std::list.unique() for " << l.max_size() << " unique elements: " << t.difference() << '\n';

                        t.start();
                        std::cout << "\nList:\n";
                        for (size_t i = 0; i < size; ++i)
                            list.front();
                        t.end();
                        std::cout << "\ntime NNU9::list.front() for " << size << " elements: " << t.difference();
                        nt[ntn] = sort_type::list_f;
                        nt[ntn].set_time_NNU9(t.difference());

                        t.start();
                        for (size_t i = 0; i < size; ++i)
                            l.front();
                        t.end();
                        std::cout << "\ntime std::list.front() for " << size << " elements: " << t.difference();
                        nt[ntn++].set_time_std(t.difference());
                        
                        t.start();
                        std::cout << "\nList:\n";
                        while (!list.empty())
                            list.pop_front();
                        t.end();
                        std::cout << "\ntime NNU9::list.pop_front() for " << size << " elements: " << t.difference();
                        nt[ntn] = sort_type::list_pf;
                        nt[ntn].set_time_NNU9(t.difference());
                        
                        t.start();
                        while (!l.empty())
                            l.pop_front();
                        t.end();
                        std::cout << "\ntime std::list.pop_front() for " << size << " elements: " << t.difference();
                        nt[ntn++].set_time_std(t.difference());

                        for (size_t i = 0; i < size; ++i)
                            list.push_front(init_arr[i]);

                        for (size_t i = 0; i < size; ++i)
                            l.push_front(init_arr[i]);

                        t.start();
                        std::cout << "\nList:\n";
                        list.clear();
                        t.end();
                        std::cout << "\ntime NNU9::list.push_front() for " << size << " elements: " << t.difference();
                        nt[ntn] = sort_type::list_cl;
                        nt[ntn].set_time_NNU9(t.difference());

                        t.start();
                        l.clear();
                        t.end();
                        std::cout << "\ntime std::list.push_front() for " << size << " elements: " << t.difference();
                        nt[ntn++].set_time_std(t.difference());
                        
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
                ntn = 24;
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
            {
                deb_now:
                int size_col = 1900;
                int size_row = 1050;
                cv::Mat plot = cv::Mat::zeros(size_row, size_col, CV_8UC3);
                unsigned int start = static_cast<int>(nt_size);
                unsigned int end = static_cast<int>(nt_size);
                unsigned int sz = 0;
                unsigned int step = 10;
                
                std::cout << "Choose diagrams(pages 0-" << (nt_size - 1) / step << "): ";
                std::cin >> sz;
                start = step * sz;
                end = start + step;


                for (unsigned int i = 0, ii = start; i < end - start && ii < nt_size - 2; ++i, ++ii)
                {
                    for (int j = 0; j < 2; j++)
                    {
                        int bar_height = 0;
                        
                        // ReSharper disable once CppDefaultCaseNotHandledInSwitchStatement
                        switch (j)  // NOLINT(hicpp-multiway-paths-covered)
                        {
                        case 0:
                            {
                                bar_height = static_cast<int>(nt[ii].get_time_std() / 1000);
                                cv::rectangle(plot, cv::Point(50, i*100 + 50), cv::Point(50 + bar_height, i*100 + 60), cv::Scalar(255, 0, 0), -1);
                                cv::putText(plot, nt[ii].get_name() + " for std:: = " + std::to_string(nt[ii].get_time_std()), cv::Point(50, i*100 + 70), cv::FONT_HERSHEY_SIMPLEX, 0.5, cv::Scalar(255, 255, 255), 1, cv::LINE_AA);
                                break;
                            }
                        case 1:
                            {
                                bar_height = static_cast<int>(nt[ii].get_time_NNU9() / 1000);
                                cv::rectangle(plot, cv::Point(50, i*100 + 100), cv::Point(50 + bar_height, i*100 + 110), cv::Scalar(255, 255, 0), -1);
                                cv::putText(plot, nt[ii].get_name() + " for NNU9:: = " + std::to_string(nt[ii].get_time_NNU9()), cv::Point(50, i*100 + 120), cv::FONT_HERSHEY_SIMPLEX, 0.5, cv::Scalar(255, 255, 255), 1, cv::LINE_AA);
                                break;
                            }
                        }
                    }
                }
                cv::imshow("Function Speed Comparison", plot);
                cv::waitKey(0);
                system("exit");
                break;
            }
        case 7:
            delete[] init_arr;
            table.at(nt_size - 1, 1) = std::to_string(size) + ';';
            write_vec(nt, table, path);
            exit(EXIT_SUCCESS);
        default:
            break;
        }
    }
}
