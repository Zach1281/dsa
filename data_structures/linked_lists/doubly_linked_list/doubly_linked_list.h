#include <iostream>

/*
    --DOUBLY LINKED LIST--
    Fundamental Principles:
        - node based DS
        - NODE stores three pieces of info
            1. some data
            2. pointer to previous NODE
            3. pointer to next NODE
    Functions:
        - insertion:
            - prepend
            - append
            - insertAt
        - deletion:
            - deleteHead
            - deleteTail
            - deleteAt
        - destructor
        - print list
        - travserse list
*/

using namespace std;

class Node
{
public:
    int data;
    // pointer to next node
    Node *next;
    // pointer to prev node
    Node *prev;
    // default constructor
    Node()
    {
        next = nullptr;
        prev = nullptr;
    }
    // constructor with data
    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
        this->prev = nullptr;
    }
};

class DoublyLinkedList
{
private:
    int length = 0;
    Node *head;

public:
    // constructors
    DoublyLinkedList() { head = nullptr; }
    ~DoublyLinkedList();
    Node *getHead() { return this->head; };
    // functions
    void prepend(int);
    void append(int);
    void insertAt(int, int);
    void deleteHead();
    void deleteTail();
    void deleteNode(int);
    void printList();
    Node *traverseList(int);
};

DoublyLinkedList::~DoublyLinkedList()
{
    Node *curr = this->head;

    while (curr != nullptr)
    {
        Node *next = curr->next;
        delete curr;
        curr = next;
    }
    this->head = nullptr;
    delete head;
}

Node *DoublyLinkedList::traverseList(int idx)
{
    Node *curr = this->head;
    for (int i = 0; curr && i < idx; i++)
    {
        curr = curr->next;
    }
    return curr;
}

void DoublyLinkedList::prepend(int data)
{
    Node *newNode = new Node(data);

    this->length++;
    if (head == nullptr)
    {
        head = newNode;
        return;
    }

    newNode->next = this->head;
    newNode->prev = nullptr;
    this->head->prev = newNode;
    this->head = newNode;
}

void DoublyLinkedList::append(int data)
{
    if (head == nullptr)
    {
        this->prepend(data);
        return;
    }

    this->length++;
    Node *newNode = new Node(data);
    Node *curr = this->head;
    while (curr->next != nullptr)
    {
        curr = curr->next;
    }
    newNode->prev = curr;
    newNode->next = nullptr;
    curr->next = newNode;
}

void DoublyLinkedList::insertAt(int data, int idx)
{
    if (idx > this->length)
    {
        throw invalid_argument("Inserting node past length of list");
    }
    else if (idx == this->length)
    {
        this->append(data);
        return;
    }
    else if (idx == 0)
    {
        this->prepend(data);
        return;
    }

    this->length++;
    Node *curr = this->traverseList(idx);
    Node *newNode = new Node(data);
    newNode->next = curr->prev->next;
    newNode->prev = curr->prev;
    curr->prev->next = newNode;
    curr->prev = newNode;
}

void DoublyLinkedList::deleteHead()
{
    if (head == nullptr)
    {
        cout << "It's already gone buddy" << endl;
        return;
    }

    this->length--;
    Node *curr = this->head;
    this->head = this->head->next;
    this->head->prev = nullptr;
    delete curr;
}

void DoublyLinkedList::deleteTail()
{
    if (head == nullptr)
    {
        cout << "It's gone already bud" << endl;
        return;
    }

    this->length--;
    Node *curr = this->head;
    while (curr->next != nullptr)
    {
        curr = curr->next;
    }
    curr->prev->next = nullptr;
    delete curr;
}

void DoublyLinkedList::deleteNode(int idx)
{
    if (idx > this->length)
    {
        throw invalid_argument("Deleting node past length of list.");
    }
    if (idx == this->length)
    {
        this->deleteTail();
        return;
    }
    if (idx == 0)
    {
        this->deleteHead();
        return;
    }

    this->length--;

    Node *curr = this->traverseList(idx);
    curr->prev->next = curr->next;
    curr->next->prev = curr->prev;
    delete curr;
}

void DoublyLinkedList::printList()
{
    if (this->head == nullptr)
    {
        throw invalid_argument("No list to print");
    }

    Node *curr = this->head;
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