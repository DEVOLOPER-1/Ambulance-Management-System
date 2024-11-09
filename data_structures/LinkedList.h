//
// Created by youss on 22-Oct-24.
//

#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <bits/stdc++.h>
#include "synthetic_queue.h"
#include "SyntheticNode.h"
using namespace std;


template<class T>
class LinkedList {
private:
    Node<T> *head ;
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
        Node<T>* new_node  = new Node<T>;
        new_node->SetData(new_item_value);
        
        if (IsEmpty()) {

            new_node->SetNextNode(nullptr); //Null Or nullptr , is there a difference ?
            head = new_node ;
        }
        else {

            new_node->SetNextNode(head);
            head = new_node ;
            
        }
        UsedSize++;
    }
    void Display() {
        Node<T>* temp_ptr = head ;
        while (temp_ptr != nullptr) {
            cout<<temp_ptr->GetData()<<" ";
            temp_ptr = temp_ptr->GetNextNode();
        }
    }
    
    int count() {
        Node<T>* temp_ptr = head;
        int counter = 0;
        while (temp_ptr != nullptr) {
            counter++;
            temp_ptr = temp_ptr->GetNextNode();
        }
        return counter;
    }
    
    bool IsFound(T user_entered_value) {
        Node<T> *temp_ptr = head ;
        while (temp_ptr != nullptr) {
            if (temp_ptr->GetData() == user_entered_value) return true;
            else {temp_ptr = temp_ptr->GetNextNode() ;}
        }
        return false;
    }
    
    void InsertBefore(T value_to_enter_before , T value_to_be_entered) {
        if (IsEmpty()) InsertFirstNode(value_to_be_entered);
        if (IsFound(value_to_enter_before)){
            Node<T>*temp_ptr = head ;
            Node<T> *NewNode = new Node<T>;
            NewNode->SetData(value_to_be_entered);
        
            while (temp_ptr!=nullptr && temp_ptr->GetNextNode()->GetData() != value_to_enter_before) {
                temp_ptr = temp_ptr->GetNextNode();
            }
            NewNode.SetNextNode(temp_ptr->GetNextNode());
            temp_ptr->SetNextNode(NewNode);
        }
    
        else cout<<"The value u want to enter before is not in the linked list! \n";
    }

    void Append(T AppendedValue) {
    if (IsEmpty()) InsertFirstNode(AppendedValue);

        
        else {
        Node<T>* temp_ptr = head;
        Node<T>* NewNode = new Node<T>;
        NewNode->SetData(AppendedValue);
        NewNode->SetNextNode(nullptr);

        while (temp_ptr->GetNextNode() != nullptr) {
            temp_ptr = temp_ptr->GetNextNode();
        }
        temp_ptr->SetNextNode(NewNode);
    }
    UsedSize++;
}
    
    void Delete(T the_value_we_want2delete) {
        if (IsEmpty()) cout<<"The linked list is Empty !\n";
        else {
            //if the Node we want to remove is the first one
            Node<T>* DelPtr = head;

            if(head->GetData() == the_value_we_want2delete) {
                head = head->GetNextNode();
                delete DelPtr ;
            }

            //if the Node we want to remove isn't the first one
            Node<T>* the_node_before_del_pointer  = nullptr;
            while (DelPtr->GetData()!= the_value_we_want2delete) {
                the_node_before_del_pointer = DelPtr;
                DelPtr = DelPtr->GetNextNode();
            }
            the_node_before_del_pointer->SetNextNode(DelPtr->GetNextNode());
            delete DelPtr;
            UsedSize--;
        }
    }
    
private:
    Node<T>*  FindMiddle() {
        if (!IsEmpty())
            {
            int middle_ = (count()/2) + 1 ;
            Node<T>*temp_node = head;
            int small_counter = 0 ;
            while (small_counter != middle_) {temp_node = temp_node->GetNextNode();}
            return temp_node ;
        }
        return nullptr;
    }

    Node<T>* Merge(Node<T>* left_node_ptr, Node<T>* right_node_ptr) {
        Node<T>* new_head = nullptr; 
        Node<T>* tail = nullptr;
        
        // Merge nodes from both lists until one is exhausted
        while (left_node_ptr && right_node_ptr) {
            Node<T>* next_node = nullptr;
            if (left_node_ptr->GetData() < right_node_ptr->GetData()) {
                next_node = left_node_ptr;
                left_node_ptr = left_node_ptr->GetNextNode();
            } else {
                next_node = right_node_ptr;
                right_node_ptr = right_node_ptr->GetNextNode();
            }

            if (!new_head) {
                new_head = tail = next_node; // Set both head and tail to the first Node
            } else {
                tail->SetNextNode(next_node); // Link the new Node to the end
                tail = next_node; // Update tail to point to the new last Node
            }
        }

        // Attach any remaining nodes from the non-exhausted list
        if (left_node_ptr) {
            if (!new_head) {
                new_head = left_node_ptr; // In case no merging happened, set new_head
            } else {
                tail->SetNextNode(left_node_ptr);
            }
        }
    }

public:
    Node<T>* Sort() {   //merge-sort [1,2][3][4,5]
    if (IsEmpty() or (count() == 1) ) cout<<"It's Already Sorted !\n";
        else {
                Node<T>* middle_positioned_ptr = FindMiddle(head);
                Node<T>* a = head;
                Node<T>* b = middle_positioned_ptr->GetNextNode();
                middle_positioned_ptr->SetNextNode(nullptr); // Split the list

                a = Sort(a);
                b = Sort(b);
                head = Merge(a, b);
                return head;
            }
    }
    
};



#endif //LINKEDLIST_H
