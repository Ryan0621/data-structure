#ifndef _NODE
#define _NODE
#include <iostream>
using namespace std;

template< class ItemType>
class Node {
    private:
        ItemType item;
        Node<ItemType>* next;
    public:
        Node();
        Node( const ItemType& anItem);
        Node( const ItemType& anItem, Node<ItemType>* nextNodePtr);
        void setItem( const ItemType& anItem);
        void setNext(Node<ItemType>* nextNodePtr);
        ItemType getItem() const ;
        Node<ItemType>* getNext() const ;
};
#endif

template< class ItemType>
Node<ItemType>::Node() {
    next = nullptr;
} // end default constructor

template< class ItemType>
Node<ItemType>::Node(const ItemType& anItem) {
    next = nullptr;
    item = anItem;
} // end constructor

template< class ItemType>
Node<ItemType>::Node(const ItemType& anItem, Node<ItemType>* nextNodePtr) {
    next = nextNodePtr;
    item = anItem;
} // end constructor

template< class ItemType>
void Node<ItemType>::setItem( const ItemType& anItem) {
    item = anItem;
} // end setItem

template< class ItemType>
void Node<ItemType>::setNext(Node<ItemType>* nextNodePtr) {
    next = nextNodePtr;
} // end setNext

template< class ItemType>
ItemType Node<ItemType>::getItem() const {
    return item;
} // end getItem

template< class ItemType>
Node<ItemType>* Node<ItemType>::getNext() const {
    return next;
} // end getNext


