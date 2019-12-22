#include <iostream>
#include "linkedlist.h"
#include <vector>
using namespace std;

int main() {
    LinkedList<int>* l1 = new LinkedList<int>();

    l1->add(1);
    l1->add(3);
    l1->add(2);

    LinkedList<int>* l2 = l1;
    l2->remove(2);
    cout << l1->getCurrentSize() << endl << l2->getCurrentSize();

    return 0;
}
