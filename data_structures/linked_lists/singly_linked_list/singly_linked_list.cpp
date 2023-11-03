#include <iostream>

/* --LINKED LIST--
    Principles
    node based data structure
    where a NODE stores a value and a pointer to the next NODE in the list
*/

using namespace std;

// template class to allow any data type to exist inside the node
class Node {
    public: 
    int data;
    //pointer to next node
    Node* next;
    // default constructor
    Node() {
        data = 0;
        next = nullptr;
    }
    // constructor w/ argument
    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

class SinglyLinkedList {    
    private: 
        int length = 0;
        Node* head = nullptr;
    public:
        SinglyLinkedList() { head = nullptr; }
        ~SinglyLinkedList();

        void prepend(int);
        void append(int);
        void insertAt(int, int);
        void printList();
        void deleteNode(int);
};

int main() {
    SinglyLinkedList* list = new SinglyLinkedList();

    list->prepend(192);
    list->prepend(64);
    list->prepend(23);
    list->printList();

    // list->insertAt(1, 2);

    list->~SinglyLinkedList();
    return 0;
}

// insert new node at head position
void SinglyLinkedList::prepend(int data) {
    Node* newNode = new Node(data);

    this->length++;
    if ( head == nullptr ) {
        head = newNode;
        return;
    }
    newNode->next = this->head;
    this->head = newNode;
}

// insert new node at designated point in list
void SinglyLinkedList::insertAt(int data, int idx) {
    if (idx > this->length) {
        throw invalid_argument("Inserting node past length of list");
    } else if (idx == this->length) {
        this->append(data);
        return;
    } else if (idx == 0) {
        this->prepend(data);
        return;
    }

    this->length++;
    Node* curr = this->head;
    for(int i = 0; curr && i < idx; i++){
        curr = curr->next;
    }
    delete curr;
}

// insert new node at end of list
void SinglyLinkedList::append(int data) {
    Node* newNode = new Node(data);

    // assign to head
    if( head == nullptr ) {
        head = newNode;
        return;
    }

    // traverse to end of list
    this->length++;
    Node* curr = head;
    while( curr->next != nullptr ) {
        //update temp
        curr = curr->next;
    }

    // insert at last
    curr->next = newNode;
    delete curr;
}

void SinglyLinkedList::printList() {
    if (this->head == nullptr) {
        throw invalid_argument("No list to print");
    }

    Node* curr = new Node();
    curr = head;
    for(int i = 0; curr && i < length; i++){
        if (i == length - 1) {
            cout << curr->data << endl;
        }
        cout << curr->data << ", ";
        curr = curr->next;
    }
    delete curr;
}

SinglyLinkedList::~SinglyLinkedList() {
    Node* curr = head;

    while (curr != nullptr) {
        Node* next = curr->next;
        delete curr;
        curr = next;
    }
    this->head = nullptr;
    delete head;
}