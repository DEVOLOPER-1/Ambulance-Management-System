#include <iostream>
using namespace  std;
#include "Stack.h"
int main()
{
    std::cout << "Hello, World!" << std::endl;
    Stack<int>s;
    cout<<s.get_stack_members_count()<<endl;
    cout<<s.Is_stack_empty()<<endl;
    s.Push(1);
    s.Push(2);
    cout<<s.get_stack_members_count()<<endl;
    return 0;
}
