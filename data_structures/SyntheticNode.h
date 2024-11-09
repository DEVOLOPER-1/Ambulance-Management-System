//
// Created by youss on 25-Oct-24.
//

#ifndef NODE_H
#define NODE_H
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
    void SetNextNode(Node* new_node) {
        next_node = new_node;
    }
    T GetData() const {return data ;}
    Node* GetNextNode() const {return next_node ; }
};



#endif //NODE_H
