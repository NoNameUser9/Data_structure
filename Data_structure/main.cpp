#include <iostream>
// #include <stack>
#include "stack.h"

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

    std::cout << "\nbefore:\n";

    // st.push(st2.pop());
    while (!st2.empty())
        st.push(st2.pop());

    // while (!st2.empty())
    //     st.push(st2.pop());
    
    while (!st3.empty())
        st.push(st3.pop());

    
    
    // auto temp = new int[st.size()];
    auto size = st.size();
    // std::cout << "\nsize:" << st.size() << "\n";

    while (!st.empty())
    {
        std::cout << st.pop() << "\n";
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
