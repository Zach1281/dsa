#include <iostream>

// STACK - FIRST IN LAST OUT
/*  Principles
    1. data can only be inserted at the end of the stack - push()
    2. data can only be deleted at the end of the stack - pop()
    3. only the last element of the stack can be read - peek()
*/

using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node()
    {
        this->next = nullptr;
    }
    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
    }
};

class Stack
{
private:
    int length = 0;
    Node *head;
    Node *tail;

public:
    Stack() { this->head = nullptr, this->tail = nullptr; }
    ~Stack();
    int getLength() { return this->length; };
    // functions
    int peek();
    void push(int);
    int pop();
};

Stack::~Stack()
{
    Node *curr = this->head;
    while (curr != nullptr)
    {
        curr = curr->next;
        delete this->head;
        this->head = curr;
    }
    delete this->head;
    delete this->tail;
}

int Stack::peek()
{
    if (this->head == nullptr)
    {
        cout << "No nodes in stack" << endl;
        return NULL;
    }
    return this->tail->data;
}

void Stack::push(int data)
{
    Node *newNode = new Node(data);
    if (this->head == nullptr)
    {
        this->head = newNode;
        this->tail = newNode;
        return;
    }
    if (this->head == this->tail)
    {
        newNode->next = this->head;
        this->tail = newNode;
        return;
    }
    newNode->next = this->tail;
    this->tail = newNode;
    return;
}

int Stack::pop()
{
    if (this->head == nullptr || this->tail == nullptr)
    {
        cout << "Nothing to pop" << endl;
        return NULL;
    }
    Node *temp = this->tail;
    int tailVal = this->tail->data;
    this->tail = this->tail->next;
    delete temp;
    return tailVal;
}