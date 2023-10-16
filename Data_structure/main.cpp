#include <iostream>
#include "stack.h"

int main(int argc, char* argv[])
{
    Stack<int> stack;

    stack.push(10);
    stack.push(20);
    stack.push(30);

    std::cout << "Size of the stack: " << stack.size() << std::endl;
    std::cout << "Top element: " << stack.top() << std::endl;

    stack.pop();

    std::cout << "Size of the stack after popping: " << stack.size() << std::endl;
    std::cout << "Top element after popping: " << stack.top() << std::endl;

    return 0;
}