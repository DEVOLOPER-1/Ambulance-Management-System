//
// Created by youss on 17-Oct-24.
//

#ifndef STACK_H
#define STACK_H
#include<iostream>
#include "Node.h"
using namespace std;





template<class T>
class Stack {
private:
    int size ;
    Node<T> * top ;

public:
    Stack() : size(0) , top(nullptr) {}
    
    bool Is_stack_empty() {
        return(top == nullptr);
    }
    
    void Push(T user_entered_value) {
        Node<T> * NewNode = new Node<T>; //Is there a problem when duplicating the type name ?
        NewNode->SetData(user_entered_value);

        if (Is_stack_empty()) {
            NewNode->SetNextNode(nullptr);
            top = NewNode ;
        }
        else {
            NewNode->SetNextNode(top);
            top = NewNode;
        }
        size++;
    }
    T Pop() {
        if (Is_stack_empty()) {
            cout<<"Stack Is Empty! "<<endl; 
        }
        else {
            Node<T>* del_ptr = top;
            T value = top->GetData();
            top  = top->GetNextNode();
            delete del_ptr;
            size--;
            return value;
            }
        }


    void PeekLook() {
        if (Is_stack_empty()!=true)
            cout<<"The Value on Top of The Stack Is "<<top->GetData()<<endl;
        else  cout<<"Stack Is Empty! "<<endl; 


    }
         
    

    void Display() {
        Node<T>* temp = top ;
        while (temp!=nullptr) {
            cout<<temp->GetData()<<" ";
            temp = temp->GetNextNode();
        }
    }
    
    int get_stack_members_count()const{return size;}

    bool Search(T user_entered_value) {
        Node<T> temp_ptr = top;
        
        while (temp_ptr!= nullptr) {
            if (temp_ptr.GetData()==user_entered_value) return true;
            temp_ptr = temp_ptr.GetNextNode();
        }
        return false;
    }
};



#endif //STACK_H
