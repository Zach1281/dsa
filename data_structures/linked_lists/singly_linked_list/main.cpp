#include "singly_linked_list.h"

int main()
{
    SinglyLinkedList *list = new SinglyLinkedList();

    cout << "Prepend: " << endl;
    // check prepend function
    list->prepend(192);
    list->prepend(64);
    list->prepend(23);
    list->printList();

    cout << "Append: " << endl;
    // check append function
    list->append(250);
    list->append(900);
    list->printList();

    cout << "Insert At: " << endl;
    // check insertAt function
    list->insertAt(45, 3);
    list->printList();

    cout << "Delete Head: " << endl;
    list->deleteHead();
    list->printList();

    cout << "Delete Tail: " << endl;
    list->deleteTail();
    list->printList();

    // check deleteNode function
    cout << "Delete At Index 2: " << endl;
    list->deleteNode(2);
    list->printList();

    cout << "Delete At Index 1: " << endl;
    list->deleteNode(1);
    list->printList();

    // delete allocated memory for linked list
    list->~SinglyLinkedList();
    return 0;
}