#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H
#include "Node.h"
#include <string>
#include <iostream>
#include <iomanip>
#include <sstream>

//////////////////////////////////////////////////////////////////////////////
//                         class template definition                        //
//////////////////////////////////////////////////////////////////////////////

template<typename T>
class DoublyLinkedList {
public:
    /* uncomment the declarations as you implement them */
    DoublyLinkedList();
    DoublyLinkedList(T data);
    DoublyLinkedList(const DoublyLinkedList<T>&);
    DoublyLinkedList<T>& operator=(const DoublyLinkedList<T>&);
    ~DoublyLinkedList();
    unsigned int size() const { return sz; }
    T& front();
    const T& front() const;
    T& back();
    const T& back() const;
    void push_back(T data);
    void push_front(T);
    void pop_back();
    void pop_front();
    void erase(unsigned int);
    void insert(T data, unsigned int idx);
    void clear();
    std::string to_str() const;
    // breaks encapsulation... gives operator== access to private data... not great approach, but makes the homework easier for you since we haven't talked about iterators :).
    // template<typename U> friend bool operator==(DoublyLinkedList<U> const&, DoublyLinkedList<U> const&);
private:
    // do not change ordering.
    Node<T> *head;
    Node<T> *tail;
    unsigned int sz;
};

//////////////////////////////////////////////////////////////////////////////
//                       helper function declarations                       //
//////////////////////////////////////////////////////////////////////////////
template<typename T> std::ostream& operator<<(std::ostream &, DoublyLinkedList<T> const&);

template<typename T> bool operator==(DoublyLinkedList<T> const&, DoublyLinkedList<T> const&);

template<typename T> bool operator!=(DoublyLinkedList<T> const&, DoublyLinkedList<T> const&);

//////////////////////////////////////////////////////////////////////////////
//                     member template function definitions                 //
//////////////////////////////////////////////////////////////////////////////
template<typename T>
std::string DoublyLinkedList<T>::to_str() const
{
    std::stringstream os;
    const Node<T> *curr = head;
    os << std::endl << std::setfill('-') << std::setw(80) << '-' << std::setfill(' ') << std::endl;
    os << "head: " << head << std::endl;
    os << "tail: " << tail << std::endl;
    os << "  sz: " << sz << std::endl;
    os << std::setw(16) << "node" << std::setw(16) << "node.prev" << std::setw(16) << "node.data" <<  std::setw(16) << "node.next" << std::endl;
    while (curr) {
        os << std::setw(16) << curr;
        os << std::setw(16) << curr->prev;
        os << std::setw(16) << curr->data;
        os << std::setw(16) << curr->next;
        os << std::endl;
        curr = curr->next;
    }
    os << std::setfill('-') << std::setw(80) << '-' << std::setfill(' ') << std::endl;
    return os.str();
}
// Default Constructor
template<typename T>
DoublyLinkedList<T>::DoublyLinkedList() : head(nullptr), tail(nullptr), sz(0) {}

// Parametrized Constructor
template<typename T>
DoublyLinkedList<T>::DoublyLinkedList(T data) : head(nullptr), tail(nullptr), sz(0) {
	Node<T>* node = new Node<T>(data);
	head = node;
	tail = node;
	sz++;
}

// Copy Constructor
template<typename T>
DoublyLinkedList<T>::DoublyLinkedList(const DoublyLinkedList<T>& copyList) : head(nullptr), tail(nullptr), sz(0){
	Node<T>* currNode = copyList.head;
	while (currNode) {
		this->push_back(currNode->data);
		currNode = currNode->next;
	}
}

// Copy Assignment Operator
template<typename T>
DoublyLinkedList<T>& DoublyLinkedList<T>::operator=(const DoublyLinkedList<T>& rhs) {
	if (this == &rhs) {
		return *this;
	}
	clear();
	Node<T>* currNode = rhs.head;
	while (currNode) {
		this->push_back(currNode->data);
		currNode = currNode->next;
	}
	return *this;
}

// Destructor
template<typename T> 
DoublyLinkedList<T>::~DoublyLinkedList() {
	clear();
}

// Front
template<typename T>
T& DoublyLinkedList<T>::front() {
	return head->data;
}

// Front const
template<typename T>
const T& DoublyLinkedList<T>::front() const {
	return head->data;
}

// Back
template<typename T>
T& DoublyLinkedList<T>::back() {
	return tail->data;
}

// Back const
template<typename T>
const T& DoublyLinkedList<T>::back() const {
	return tail->data;
} 

// Clear
template<typename T>
void DoublyLinkedList<T>::clear() {
	Node<T>* currNode = head;
	while(currNode) {
		Node<T>* nextNode = currNode->next;
		delete currNode;
		currNode = nextNode;
	}
	head = nullptr;
	tail = nullptr;
	sz = 0;
}

// Insert
template<typename T>
void DoublyLinkedList<T>::insert(T data, unsigned int idx) {
	if (idx >= size()) {
		return;
	}
	Node<T>* insertNode = head;
	if (head == nullptr || idx == 0) {
		push_front(data);
	} else if (idx == sz - 1) {
		push_back(data);
	} else {
		int cnt = 0;
		while (insertNode && cnt != idx) {
			insertNode = insertNode->next;
			cnt++;
		}
		Node<T>* insertPrev = insertNode->prev;
		Node<T>* insertNext = insertNode->next;
		insertPrev->next = insertNext;
		if (insertNext != nullptr) {
			insertNext->prev = insertPrev;
		}
		sz++;
	}
}

// Erase
template<typename T>
void DoublyLinkedList<T>::erase(unsigned int idx) {
	if (idx >= size()) {
		return;
	}
	Node<T>* deleteNode = head;
	if (head == nullptr) {
		tail = nullptr;
		return;
	} else {
		int cnt = 0;
		while (deleteNode && cnt != idx) {
			deleteNode = deleteNode->next;
			cnt++;
		}
		if (idx == 0) {
			head = deleteNode->next;
			head->prev = nullptr;
			sz--;
		} else if (idx == sz - 1) {
			tail = tail->prev;
			tail->next = nullptr;
			sz--;
		} else if (cnt == idx) {
			Node<T>* deletePrev = deleteNode->prev;
			Node<T>* deleteNext = deleteNode->next;
			deletePrev->next = deleteNext;
			if (deleteNext != nullptr) {
				deleteNext->prev = deletePrev;
			}
			sz--;
		}
	}
}

// Push Back
template<typename T>
void DoublyLinkedList<T>::push_back(T data) {
	Node<T>* pushNode = new Node<T>(data);
	if (tail == nullptr) {
		tail = pushNode;
		head = pushNode;
		sz = 1;
	} else {
		tail->next = pushNode;
		pushNode->prev = tail;
		tail = pushNode;
		sz++;
	}
}

// Pop Back
template<typename T>
void DoublyLinkedList<T>::pop_back() {
	if (tail == nullptr) {
		return;
	} else if (tail == head) {
		delete tail;
		head = nullptr;
		tail = nullptr;
		sz--;
	} else {
		Node<T>* newTailNode = nullptr;
		newTailNode = tail->prev;
		newTailNode->next = nullptr;
		delete tail;
		tail = newTailNode;
		sz--;
	}
}

// Push Front
template<typename T>
void DoublyLinkedList<T>::push_front(T data) {
	Node<T>* pushNode = new Node<T>(data);
	if (head == nullptr) {
		head = pushNode;
		tail = pushNode;
		sz = 1;
	} else {
		head->prev = pushNode;
		pushNode->next = head;
		head = pushNode;
		sz++;
	}
}
// Pop Front
template<typename T>
void DoublyLinkedList<T>::pop_front() {
	if (head == nullptr) {
		return;
	} else if (head == tail) {
		delete head;
		head = nullptr;
		tail = nullptr;
		sz--;
	} else {
		Node<T>* newHeadNode = nullptr;
		newHeadNode = head->next;
		newHeadNode->prev = nullptr;
		delete head;
		head = newHeadNode;
		sz--;
	}
}



//////////////////////////////////////////////////////////////////////////////
//                     helper template function definitions                 //
//////////////////////////////////////////////////////////////////////////////
template<typename T>
bool operator==(DoublyLinkedList<T> const& lhs, DoublyLinkedList<T> const& rhs)
{
    if (lhs.head->data == rhs.head->data && lhs.tail->data == rhs.tail->data) {
		return true;
	} else {
		return false;
	}
    
}

template<typename T>
std::ostream& operator<<(std::ostream& os, DoublyLinkedList<T> const& rhs)
{
    os << rhs.to_str();
    return os;
}

#endif

