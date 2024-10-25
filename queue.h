//
// Created by youss on 21-Oct-24.
//

#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>
#include <stdexcept>
using namespace std;
#include "Node.h"



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
        
        if (IsEmpty()) {front = rear = new_node ; }
        
        else  {rear->SetNextNode(new_node); rear = new_node;}
        used_size++;
    }
    
    void Dequeue() {
        if (IsEmpty()) throw out_of_range("Empty Queue! \n");
        //If we have 1 element only
        else if (rear == front) {delete front ; front = rear = nullptr ; used_size--;}
        //If we have multiple elements
        else {
            const Node<T>* delptr = front ;
            front = front->GetNextNode();
            delete delptr ;
            used_size--;
        }
    }
    bool IsFound(T value_item) {
        Node<T>*temp_ptr = front ;
        while (temp_ptr!=nullptr) {
            if (temp_ptr->GetData() == value_item) return true;
            temp_ptr = temp_ptr->GetNextNode();
        }
        return false;
    }
    
    void ClearQueue() {
        if (IsEmpty()) {throw out_of_range("Empty Queue! \n");}
        
        else {while (!IsEmpty()) Dequeue();}
        
    }
    
    void Display() {
        Node<T>* temp_ptr = front ;
        while (temp_ptr!=nullptr) {cout<<temp_ptr->GetData()<<" "; temp_ptr = temp_ptr->GetNextNode() ;}
    }
    
    int get_size() const {return used_size;}

    T get_most_front_one() const {return front->GetData();}
    T get_most_rear_one() const {return rear->GetData();}

    
};



#endif //QUEUE_H
