#include <iostream>

/* --LINKED LIST--
    Fundamental Principles:
        - node based data structure
        - where a NODE stores a value and a pointer to the next NODE in the list
    Functions:
        - insert a node
            - prepend
            - append
            - insertAt
        - delete list
            - ~SinglyLinkedList
        - delete a node
            - deleteHead
            - deleteTail
            - deleteAt
        - print the list
            - printList
        - traverse list
*/

using namespace std;

// template class to allow any data type to exist inside the node
class Node
{
public:
    int data;
    // pointer to next node
    Node *next;
    // default constructor
    Node()
    {
        next = nullptr;
    }
    // constructor w/ argument
    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
    }
};

class SinglyLinkedList
{
private:
    int length = 0;
    Node *head;

public:
    SinglyLinkedList() { head = nullptr; }
    ~SinglyLinkedList();

    void prepend(int);
    void append(int);
    void insertAt(int, int);
    void printList();
    void deleteNode(int);
    void deleteHead();
    void deleteTail();
};

// insert new node at head position
void SinglyLinkedList::prepend(int data)
{
    Node *newNode = new Node(data);

    this->length++;
    if (head == nullptr)
    {
        head = newNode;
        return;
    }
    newNode->next = this->head;
    this->head = newNode;
}

// insert new node to the right of the designated point in list
void SinglyLinkedList::insertAt(int data, int idx)
{
    if (idx > this->length)
    {
        throw invalid_argument("Inserting node past length of list");
    }
    if (idx == this->length)
    {
        this->append(data);
        return;
    }
    if (idx == 0)
    {
        this->prepend(data);
        return;
    }

    this->length++;
    Node *curr = this->head;
    for (int i = 0; curr && i < idx; i++)
    {
        curr = curr->next;
    }

    Node *newNode = new Node(data);
    newNode->next = curr->next;
    curr->next = newNode;
}

// insert new node at end of list
void SinglyLinkedList::append(int data)
{
    Node *newNode = new Node(data);

    // assign to head
    if (head == nullptr)
    {
        this->prepend(data);
        delete newNode;
        return;
    }

    // traverse to end of list
    this->length++;
    Node *curr = head;
    while (curr->next != nullptr)
    {
        // update temp
        curr = curr->next;
    }

    // insert at last
    curr->next = newNode;
}

// delete a node at specified index
void SinglyLinkedList::deleteNode(int idx)
{
    if (idx > this->length)
    {
        throw invalid_argument("Deleting node past length of list");
    }
    else if (idx == this->length)
    {
        this->deleteTail();
        return;
    }
    else if (idx == 0)
    {
        this->deleteHead();
        return;
    }

    // otherwise, traverse to the node before the one we want to delete
    this->length--;
    // traverse to previous node
    Node *prev_node = this->head;
    Node *del_node = new Node();
    for (int i = 0; prev_node && i < idx - 1; i++)
    {
        prev_node = prev_node->next;
    }
    // get the node we want to delete
    del_node = prev_node->next;
    // set the previous node's next pointer to the deletion node's next pointer
    prev_node->next = prev_node->next->next;
    // delete the node
    delete del_node;
}

// delete node that is at the head position
void SinglyLinkedList::deleteHead()
{
    // check if list exists
    // check if list has more than one element
    if (head == nullptr)
    {
        cout << "It's already gone buddy" << endl;
        return;
    }

    this->length--;
    // otherwise, move head to next node and delete the node at the previous head location
    Node *curr = this->head;
    this->head = this->head->next;
    delete curr;
}

// delete node that is at the tail position
void SinglyLinkedList::deleteTail()
{
    if (head == nullptr)
    {
        return;
    }
    // check if the list is just one node
    if (head->next == nullptr)
    {
        cout << "You're just deleting the list" << endl;
        this->~SinglyLinkedList();
        return;
    }
    // otherwise it should be fine to delete the tail
    // this should involve: traversing the node and setting it to a nullptr
    this->length--;
    Node *second_last = head;
    while (second_last->next->next != nullptr)
    {
        second_last = second_last->next;
    }
    delete (second_last->next);
    second_last->next = nullptr;
}

// print the linked list from head to tail
void SinglyLinkedList::printList()
{
    // check if the list exists
    if (this->head == nullptr)
    {
        throw invalid_argument("No list to print");
    }

    // if it does exist, print the list
    Node *curr = new Node();
    curr = head;
    for (int i = 0; curr && i < length; i++)
    {
        if (i == length - 1)
        {
            cout << curr->data << endl;
            return;
        }
        cout << curr->data << ", ";
        curr = curr->next;
    }
    delete curr;
}

// unsure if this destructor is actually deleting everything but if does then it deletes the list
SinglyLinkedList::~SinglyLinkedList()
{
    Node *curr = head;

    while (curr != nullptr)
    {
        Node *next = curr->next;
        delete curr;
        curr = next;
    }
    this->head = nullptr;
    delete head;
}