#ifndef _LINKED_LIST
#define _LINKED_LIST
#include "BagInterface.h"
#include "Node.h"
#include <vector>
using namespace std;

template < class ItemType>
class LinkedList : public BagInterface<ItemType> {
    private :
        Node<ItemType>* headPtr;
        int itemCount;
        Node<ItemType>* getPointerTo( const ItemType& target) const ;
    public :
        LinkedList();
        LinkedList( const LinkedList<ItemType>& aBag);
        virtual ~LinkedList();
        int getCurrentSize() const ;
        bool isEmpty() const ;
        bool add( const ItemType& newEntry);
        bool remove( const ItemType& anEntry);
        void clear();
        bool contains( const ItemType& anEntry) const ;
        int getFrequencyOf( const ItemType& anEntry) const;
        vector<ItemType> toVector() const ;
};
#endif

template < class ItemType>
LinkedList<ItemType>::LinkedList() {
    headPtr = nullptr;
    itemCount = 0;
}

template < class ItemType>
bool LinkedList<ItemType>::add( const ItemType& newEntry) {
    Node<ItemType>* newNode = new Node<ItemType>(newEntry, headPtr);
    headPtr = newNode;
    itemCount++;

    return true;
}

template < class ItemType>
LinkedList<ItemType>::~LinkedList() {
    clear();
}

template < class ItemType>
vector<ItemType> LinkedList<ItemType>::toVector() const {
    Node<ItemType>* currentPtr = headPtr;
    vector<ItemType> v;
    while (currentPtr!=nullptr) {
        v.push_back(currentPtr->getItem());
        currentPtr = currentPtr->getNext();
    }
    return v;
}

template < class ItemType>
bool LinkedList<ItemType>::isEmpty() const {
    return (itemCount == 0);
}

template < class ItemType>
int LinkedList<ItemType>::getCurrentSize() const {
    return itemCount;
}

template < class ItemType>
int LinkedList<ItemType>::getFrequencyOf( const ItemType& anEntry) const {
    int frequency = 0;
    Node<ItemType>* curPtr = headPtr;
    while (curPtr != nullptr) {
        if (anEntry == curPtr->getItem()) {
            frequency++;
        }
        curPtr = curPtr->getNext();
    }
    return frequency;
}

template < class ItemType>
bool LinkedList<ItemType>::contains( const ItemType& anEntry) const {
    Node<ItemType>* curPtr = headPtr;
    while (curPtr != nullptr) {
        if(anEntry == curPtr->getItem()) {
            return true;
        }
        curPtr = curPtr->getNext();
    }
    return false;
}

template < class ItemType>
Node<ItemType>* LinkedList<ItemType>::getPointerTo( const ItemType& target) const {
    Node<ItemType>* curPtr = headPtr;
    while (curPtr != nullptr) {
        if(target == curPtr->getItem()) {
            return curPtr;
        }
        curPtr = curPtr->getNext();
    }
    return nullptr;
}

template < class ItemType>
bool LinkedList<ItemType>::remove( const ItemType& anEntry) {
    Node<ItemType>* curPtr = getPointerTo(anEntry);
    curPtr->setItem(headPtr->getItem());
    Node<ItemType>* nodeToDeletePtr = headPtr;
    headPtr = headPtr->getNext();
    delete nodeToDeletePtr;
    itemCount--;
    return true;
}

template < class ItemType>
void LinkedList<ItemType>::clear() {
    Node<ItemType>* nodeToDeletePtr = headPtr;
    Node<ItemType>* nextPtr;
    while (nodeToDeletePtr != nullptr) {
        nextPtr = nodeToDeletePtr->getNext();
        delete nodeToDeletePtr;
        itemCount--;
        nodeToDeletePtr = nextPtr;
    }
}

template < class ItemType>
LinkedList<ItemType>::LinkedList( const LinkedList<ItemType>& aBag) {
    itemCount = aBag->itemCount;
    Node<ItemType>* origChainPtr = aBag->headPtr;
    if (origChainPtr == nullptr )
        headPtr = nullptr ; // Original bag is empty; so is copy
    else {
        // Copy first node
        headPtr = new Node<ItemType>();
        headPtr->setItem(origChainPtr ->getItem());
        // Copy remaining nodes
        Node<ItemType>* newChainPtr = headPtr;
        // Last-node pointer
        while (origChainPtr != nullptr ) {
            origChainPtr = origChainPtr ->getNext(); // Advance pointer
            // Get next item from original chain
            ItemType nextItem = origChainPtr->getItem();
            // Create a new node containing the next item
            Node<ItemType>* newNodePtr = new Node<ItemType>(nextItem);
            // Link new node to end of new chain
            newChainPtr->setNext(newNodePtr);
            // Advance pointer to new last node
            newChainPtr = newChainPtr->getNext();
        }
        newChainPtr->setNext( nullptr ); // Flag end of new chain
    }
}

//#include <iostream>
//#ifndef LINKEDLIST_H
//#define LINKEDLIST_H
//using namespace std;
//
//template <class T>
//struct Node {
//    T key;
//    Node* next;
//};
//
//template <class U>
//class LinkedList {
//    private:
//        Node<U>* head;
//    public:
//        LinkedList() { head = nullptr; }
//        bool listSearch(U k);
//        void listAppend(U k);
//        void listPrint();
//        void listDelete(U k);
//};
//#endif
//
//// Let temp represent temporary variable for storing head value or iteration
//// Let x represent a new node creation with key value
//// Note: head variable stores address, doesn't contain attributes next or key
//template <class U>
//bool LinkedList<U>::listSearch(U k) {
//    Node<U>* temp;
//    temp = head;
//    while (temp!=nullptr && temp->key!=k) {
//        temp = temp->next;
//    }
//    if (temp!=nullptr) {
//        return true;
//    }
//    else return false;
//}
//
//template <class U>
//void LinkedList<U>::listPrint() {
//    Node<U>* temp;
//    temp = head;
//    while (temp!=nullptr) {
//        cout << temp->key << endl;
//        temp = temp->next;
//    }
//}
//
//template <class U>
//void LinkedList<U>::listAppend(U k) {
//    Node<U>* temp;
//    Node<U>* x = new Node<U>;
//    x->key = k;
//    if (head == nullptr) {
//        head = x;
//    }
//    else {
//        temp = head;
//        while (temp->next!=nullptr) {
//            temp = temp->next;
//        }
//        temp->next = x;
//    }
//}
//
//template <class U>
//void LinkedList<U>::listDelete(U k) {
//    Node<U>* temp;
//    Node<U>* prev;
//    temp = head;
//    if (temp->key==k)
//    while (temp->key!=k && temp!=nullptr) {
//        prev = temp;
//        temp = temp->next;
//    }
//    if(temp!=nullptr) {
//        prev->next = temp->next;
//    }
//    delete temp;
//}
