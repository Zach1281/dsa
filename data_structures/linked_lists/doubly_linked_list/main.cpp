#include "doubly_linked_list.h"

int main()
{
    DoublyLinkedList *list = new DoublyLinkedList();

    cout << "Prepend: " << endl;
    // check prepend function
    list->prepend(0);
    list->printList();
    list->prepend(1);
    list->printList();
    list->prepend(2);
    list->printList();

    cout << "Append: " << endl;
    // check append function
    list->append(3);
    list->printList();
    list->append(4);
    list->printList();

    cout << "Insert At: " << endl;
    // check insertAt function
    list->insertAt(25, 2);
    list->printList();
    list->insertAt(60, 1);
    list->printList();

    // check deleteHead function
    list->deleteHead();
    list->printList();

    // check deleteTail function
    list->deleteTail();
    list->printList();

    // check deleteNode function
    list->deleteNode(2);
    list->printList();

    // call destructor
    list->~DoublyLinkedList();
    return 0;
}