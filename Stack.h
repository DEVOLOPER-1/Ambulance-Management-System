//
// Created by youss on 17-Oct-24.
//

#ifndef STACK_H
#define STACK_H
#include<iostream>
using namespace std;


template<class T>
class node {
private:
    node * next_node ;
    T node_data;

public:
    node() : next_node(nullptr)  {}
    void set_next_node(node* new_node) {
        next_node = new_node ;
    }
    void set_data(T node_data) {
        this->node_data = node_data ;
    }
    node* get_next_node()const{return next_node ;}
    T get_data()const{return node_data;}
};


template<class T>
class Stack {
private:
    int size ;
    node<T> * top ;

public:
    Stack() : size(0) , top(nullptr) {}
    
    bool Is_stack_empty() {
        return(top == nullptr);
    }
    
    void Push(T user_entered_value) {
        node<T> * NewNode = new node<T>; //Is there a problem when duplicating the type name ?
        NewNode->set_data(user_entered_value);

        if (Is_stack_empty()) {
            NewNode->set_next_node(nullptr);
            top = NewNode ;
        }
        else {
            NewNode->set_next_node(top);
            top = NewNode;
        }
        size++;
    }
    T Pop() {
        if (Is_stack_empty()) {
            cout<<"Stack Is Empty! "<<endl; 
        }
        else {
            node<T>* del_ptr = top;
            T value = top->get_data();
            top  = top->get_next_node();
            delete del_ptr;
            size--;
            return value;
            }
        }


    void PeekLook() {
        if (Is_stack_empty()!=true)
            cout<<"The Value on Top of The Stack Is "<<top->get_data()<<endl;
        else  cout<<"Stack Is Empty! "<<endl; 


    }
         
    

    void Display() {
        node<T>* temp = top ;
        while (temp!=nullptr) {
            cout<<temp->get_data()<<" ";
            temp = temp->get_next_node();
        }
    }
    
    int get_stack_members_count()const{return size;}

    bool Search(T user_entered_value) {
        node<T> temp_ptr = top;
        
        while (temp_ptr!= nullptr) {
            if (temp_ptr.get_data()==user_entered_value) return true;
            temp_ptr = temp_ptr.get_next_node();
        }
        return false;
    }
};



#endif //STACK_H
