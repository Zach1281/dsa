#include <iostream>

/*
    --QUEUE--
    Fundamental Principles:
        - First In First Out (FIFO)
        - can be thought of as a line
    Functionality
        - enqueue(item)
        - deque()
        - peek()
*/

// i'm going to implement it as a singly linked list
// the head is going to be where we deque so we have no need for traversal

using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node()
    {
        this->next = nullptr;
        this->prev = nullptr;
    }
    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
        this->prev = nullptr;
    }
};

class Queue
{
private:
    int length = 0;
    Node *head;
    Node *tail;

public:
    Queue() { head = nullptr; }
    ~Queue();
    int getLength() { return this->length; };
    // functions
    Node *peek();
    void enqueue(int);
    int deque();
};

Queue::~Queue()
{
    Node *curr = this->head;

    while (curr != nullptr)
    {
        Node *next = curr->next;
        delete curr;
        curr = next;
    }
    this->head = nullptr;
    this->tail = nullptr;
    delete tail;
    delete head;
}

Node *Queue::peek()
{
    if (this->head == nullptr)
    {
        throw invalid_argument("List does not exist");
    }

    return this->head;
}

// add a new node to the queue at the tail end
void Queue::enqueue(int data)
{
    Node *newNode = new Node(data);
    this->length++;
    // if the queue does not exist then initialize
    if (this->head == nullptr || this->tail == nullptr)
    {
        this->head = newNode;
        this->tail = newNode;
        return;
    }
    // if the queue only has one node, special case entry
    if (this->head == this->tail)
    {
        // set next node to head
        newNode->next = this->head;
        // set prev to null since it is at the back
        newNode->prev = nullptr;
        // set tail to new newNode
        this->tail = newNode;
        // set head prev to the newNode
        this->head->prev = newNode;
        return;
    }

    // otherwise get the tail and add the new node
    newNode->next = this->tail;
    this->tail->prev = newNode;
    this->tail = newNode;
}

int Queue::deque()
{
    // check if queue exists
    if (this->head == nullptr || this->tail == nullptr)
    {
        cout << "No node to remove, queue is empty" << endl;
        return NULL;
    }
    this->length--;
    // if it does, then pop off the head node and move the head down the queue
    int headVal = this->head->data;
    head->prev->next = nullptr;
    delete head;
    head = head->prev;
    return headVal;
}
