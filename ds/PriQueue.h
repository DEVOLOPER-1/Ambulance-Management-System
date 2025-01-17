#pragma once
#include <iostream>
using namespace std;

template < typename T>
class priNode
{
private:
    T item;		// A data item
    int pri;	//priority of the item
    priNode<T>* next; // Pointer to next node
public:
    priNode(const T& r_Item, int PRI)
    {
        setItem(r_Item, PRI);
        next = nullptr;
    }
    void setItem(const T& r_Item, int PRI)
    {
        item = r_Item;
        pri = PRI;
    }
    void setNext(priNode<T>* nextNodePtr)
    {
        next = nextNodePtr;
    }

    T getItem(int& PRI) const
    {
        PRI = pri;
        return item;
    }

    priNode<T>* getNext() const
    {
        return next;
    }

    int getPri() const
    {
        return pri;
    }
}; // end Node

//This class impelements the priority queue as a sorted list (Linked List)
//The item with highest priority is at the front of the queue
template <typename T>
class PriQueue
{
protected:
    int MembersCount;
    priNode<T>* head;
public:
    PriQueue() : head(nullptr) , MembersCount(0) {}

    ~PriQueue() {
        T tmp;
        int p;
        while (dequeue(tmp, p));
    }

    //insert the new node in its correct position according to its priority
    void enqueue(const T& data, int priority) {
        priNode<T>* newNode = new priNode<T>(data, priority);

        if (head == nullptr || priority > head->getPri())
        {

            newNode->setNext(head);
            head = newNode;
            MembersCount++;
            return;
        }

        priNode<T>* current = head;
        while (current->getNext() && priority <= current->getNext()->getPri()) {
            current = current->getNext();
        }
        newNode->setNext(current->getNext());
        current->setNext(newNode);
        MembersCount++;
    }

    bool dequeue(T& topEntry, int& pri) {
        if (isEmpty())
            return false;

        topEntry = head->getItem(pri);
        priNode<T>* temp = head;
        head = head->getNext();
        MembersCount--;
        delete temp;
        return true;
    }

    bool peek(T& topEntry, int& pri) {
        if (isEmpty())
            return false;

        topEntry = head->getItem(pri);
        pri = head->getPri();
        return true;
    }

    bool isEmpty() const {
        return head == nullptr;
    }

	void print() {
		priNode<T>* current = head;
		int pri;
		while (current) 
        {
			if (current->getNext() == nullptr)
				cout << current->getItem(pri);
			else
				cout << current->getItem(pri) << ", ";
			current = current->getNext();
		}
		//cout << endl;
	}

    int GetMembersCount() {
        return MembersCount;
    }
};

template <typename T>
class TraversablePriQueue : public PriQueue<T> {
public:
    TraversablePriQueue() : PriQueue<T>() {}

    // traversal & check a patient ID
    bool isPatientPickedUp(int patientID) {
        priNode<T>* current = this->head;  
        while (current) {
            T item;
            int priority;
            item = current->getItem(priority);
            if (item->getPatientID() == patientID && 
                item->getStatus() == "Loaded") {
                return true;
            }
            current = current->getNext();
        }
        return false;
    }

    // traversal with predicate
    template<typename Predicate>
    bool findIf(Predicate pred) {
        priNode<T>* current = this->head;
        while (current) {
            T item;
            int priority;
            item = current->getItem(priority);
            if (pred(item)) {
                return true;
            }
            current = current->getNext();
        }
        return false;
    }
};