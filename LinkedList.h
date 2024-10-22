//
// Created by youss on 22-Oct-24.
//

#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <iostream>

#include "queue.h"
using namespace std;


template<class T>
class node {
private:
    T data ;
    node * next_node ;

public:
    node* get_next_node() const{return next_node ;}
    T get_data() const{return data;}
    
    void set_next_node(node* new_node) {
        next_node = new_node ;
    }
    void set_data(T data) {
        this->data = data ;
    }
};
template<class T>
class LinkedList {
private:
    node<T> *head ;
    int UsedSize;
    bool IsSorted;

public:
    
    LinkedList(): head(nullptr) , UsedSize(0), IsSorted(false) {}
    
    bool IsEmpty() {
        //     if (head == nullptr) return true;
        //     else return false;
        return (head == nullptr) ;
    }
    void InsertFirstNode(T new_item_value) {
        node<T>* new_node  = new node<T>;
        new_node->set_data(new_item_value);
        
        if (IsEmpty()) {

            new_node->set_next_node(nullptr); //Null Or nullptr , is there a difference ?
            head = new_node ;
        }
        else {

            new_node->set_next_node(head);
            head = new_node ;
            
        }
        UsedSize++;
    }
    void Display() {
        node<T>* temp_ptr = head ;
        while (temp_ptr != nullptr) {
            cout<<temp_ptr->get_data()<<" ";
            temp_ptr = temp_ptr->get_next_node();
        }
    }
    
    int count() {
        node<T>* temp_ptr = head;
        int counter = 0;
        while (temp_ptr != nullptr) {
            counter++;
            temp_ptr = temp_ptr->get_next_node();
        }
        return counter;
    }
    
    bool IsFound(T user_entered_value) {
        node<T> *temp_ptr = head ;
        while (temp_ptr != nullptr) {
            if (temp_ptr->get_data() == user_entered_value) return true;
            else {temp_ptr = temp_ptr->get_next_node() ;}
        }
        return false;
    }
    
    void InsertBefore(T value_to_enter_before , T value_to_be_entered) {
        if (IsEmpty()) InsertFirstNode(value_to_be_entered);
        if (IsFound(value_to_enter_before)){
            node<T>*temp_ptr = head ;
            node<T> NewNode = new node<T>;
            NewNode->set_data(value_to_be_entered);
        
            while (temp_ptr!=nullptr && temp_ptr->get_next_node()->get_data() != value_to_enter_before) {
                temp_ptr = temp_ptr->get_next_node();
            }
            NewNode.set_next_node(temp_ptr->get_next_node());
            temp_ptr->set_next_node(NewNode);
        }
    
        else cout<<"The value u want to enter before is not in the linked list! \n";
    }

    void Append(T AppendedValue) {
        if (IsEmpty()) InsertFirstNode(AppendedValue);
        else {
            node<T>temp_ptr = head;
            node<T> NewNode = new node<T>;
            NewNode->set_data(AppendedValue);
            while (temp_ptr!=nullptr && temp_ptr->get_next_node()!=nullptr) {
                temp_ptr = temp_ptr->get_next_node();
            }
            temp_ptr.get_next_node() = NewNode;
            NewNode.get_next_node() = nullptr;
        }
        UsedSize++;
    }
    
    void Delete(T the_value_we_want2delete) {
        if (IsEmpty()) cout<<"The linked list is Empty !\n";
        else {
            //if the node we want to remove is the first one
            node<T>* DelPtr = head;

            if(head->get_data() == the_value_we_want2delete) {
                head = head->get_next_node();
                delete DelPtr ;
            }

            //if the node we want to remove isn't the first one
            node<T>* the_node_before_del_pointer  = nullptr;
            while (DelPtr->get_data()!= the_value_we_want2delete) {
                the_node_before_del_pointer = DelPtr;
                DelPtr = DelPtr->get_next_node();
            }
            the_node_before_del_pointer->set_next_node(DelPtr->get_next_node());
            delete DelPtr;
            UsedSize--;
        }
    }

    node<T>*  FindMiddle() {
        if (!IsEmpty())
            {
            int middle_ = (count()/2) + 1 ;
            Node<T>*temp_node = head;
            int small_counter = 0 ;
            while (small_counter<middle_) {temp_node = temp_node->get_next_node();}
            return temp_node ;
        } 
    }

    node<T> Merge(Node<T>*left_node_ptr , Node<T>*right_node_ptr) {
        node<T>* new_node = new node<T> ;
        node<T>* tail  = new_node ;
        while (left_node_ptr!=nullptr && right_node_ptr!=nullptr) {
            if (left_node_ptr->get_data() < right_node_ptr->get_data()) {
                tail->set_next_node(left_node_ptr);
                left_node_ptr = left_node_ptr->get_next_node();
            }
            else {
                tail->set_next_node(right_node_ptr);
                right_node_ptr = right_node_ptr->get_next_node();                
            }
            tail = tail->get_next_node();
        }
        
        if (left_node_ptr!=nullptr) tail->set_next_node(left_node_ptr);
        else tail->set_next_node(right_node_ptr) ;

        return new_node->get_next_node();
        
        
    }
    
    node<T>* Sort(node<T> * head) {
        //merge-sort

        
        if (IsEmpty() || count() == 1 ) cout<<"It's Already Sorted !\n";
        else {
            node<T>* middle_positioned_ptr = FindMiddle(head);
            node<T>* left_head = head;
            node<T>* right_head = middle_positioned_ptr->get_next_node();
            middle_positioned_ptr->set_next_node(nullptr); // Split the list

            left_head = Sort(left_head);
            right_head = Sort(right_head);

            return Merge(left_head, right_head);
        }
    }
    
};



#endif //LINKEDLIST_H
