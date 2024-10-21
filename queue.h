//
// Created by youss on 21-Oct-24.
//

#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>
#include <stdexcept>
using namespace std;


template<class T>
class Node {
private:
    T data ;
    Node * next_node ; 
public:
    Node(): next_node(nullptr){}
    void SetData(T data) {
        this->data = data ;
    }
    void set_next_node(Node* new_node) {
        next_node = new_node;
    }
    T get_data() const {return data ;}
    Node* get_next_node() const {return next_node ; }
};

template<class T>

class queue {
private:
    Node<T>*front = new Node<T>;
    Node<T>*rear = new Node<T>;
    int used_size  ;
public:
    queue(): front(nullptr) , rear(nullptr) , used_size(0){}
    bool IsEmpty() {
        return (front ==nullptr && rear == nullptr);
    }
    void Enqueue(T user_entered_value) {
        Node<T>* new_node = new Node<T>;
        new_node->SetData(user_entered_value);
        
        if (IsEmpty()) {front = rear = new_node ; used_size++;}
        
        else  {rear->set_next_node(new_node); rear = new_node; used_size++;}
    }
    
    void Dequeue() {
        if (IsEmpty()) throw out_of_range("Empty Queue! \n");
        //If we have 1 element only
        else if (rear == front) {delete front ; front = rear = nullptr ; used_size--;}
        //If we have multiple elements
        else {
            const Node<T>* delptr = front ;
            front = front->get_next_node();
            delete delptr ;
            used_size--;
        }
    }
    bool IsFound(T value_item) {
        Node<T>*temp_ptr = front ;
        while (temp_ptr!=nullptr) {
            if (temp_ptr->get_data() == value_item) return true;
            temp_ptr = temp_ptr->get_next_node();
        }
        return false;
    }
    
    void ClearQueue() {
        if (IsEmpty()) {throw out_of_range("Empty Queue! \n");}
        
        else {while (!IsEmpty()) Dequeue();}
        
    }
    
    void Display() {
        Node<T>* temp_ptr = front ;
        while (temp_ptr!=nullptr) {cout<<temp_ptr->get_data()<<" "; temp_ptr = temp_ptr->get_next_node() ;}
    }
    
    int get_size() const {return used_size;}

    T get_most_front_one() const {return front->get_data();}
    T get_most_rear_one() const {return rear->get_data();}

    
};



#endif //QUEUE_H
