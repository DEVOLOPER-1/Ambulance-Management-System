#include <iostream>

#include "queue.h"
using namespace  std;
#include "Stack.h"
#include "LinkedList.h"


int main()
{
    std::cout << "Hello, World!" << std::endl;
    Stack<int>s;
    queue<float>q;
    LinkedList<int>linked_list;
    linked_list.Append(6);
    linked_list.Append(2);
    cout<<"ll" ; linked_list.Display() ; cout<<endl;
    cout<<s.get_stack_members_count()<<endl;
    cout<<s.Is_stack_empty()<<endl;
    s.Push(1);
    s.Push(2);
    cout<<s.get_stack_members_count()<<endl;
    cout<<q.get_size()<<endl;
    return 0;
}
