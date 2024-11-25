#pragma once

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
class priQueue
{
    priNode<T>* head;
public:
    priQueue() : head(nullptr) {}

    ~priQueue() {
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
            return;
        }

        priNode<T>* current = head;
        while (current->getNext() && priority <= current->getNext()->getPri()) {
            current = current->getNext();
        }
        newNode->setNext(current->getNext());
        current->setNext(newNode);
    }

    bool dequeue(T& topEntry, int& pri) {
        if (isEmpty())
            return false;

        topEntry = head->getItem(pri);
        priNode<T>* temp = head;
        head = head->getNext();
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
		while (current) {
			cout << valueOf(current->getItem(pri)) << ", ";
			current = current->getNext();
		}
		cout << endl;
	}
};
