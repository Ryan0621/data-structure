#include <iostream>
#include "linkedlist.h"
#include <vector>
using namespace std;

int main() {
    LinkedList<int>* l1 = new LinkedList<int>();

    l1->add(1);
    l1->add(3);
    l1->add(2);

    LinkedList<int>* l2 = new LinkedList<int>(l1);
    l2->remove(2);

    vector<int> temp1, temp2;
    temp1 = l1->toVector();
    temp2 = l2->toVector();

    for (int i=0; i<temp1.size(); i++) {
        cout << temp1[i] << ' ';
    }
    cout << endl;
    for (int i=0; i<temp2.size(); i++) {
        cout << temp2[i] << ' ';
    }

    return 0;
}
