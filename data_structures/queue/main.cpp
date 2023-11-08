#include "queue.h"

int main()
{
    Queue *q = new Queue();

    // check enqueue
    q->enqueue(1);
    cout << "Head: " << q->peek()->data << endl;
    cout << "Length: " << q->getLength() << endl;
    q->enqueue(2);
    cout << "Head: " << q->peek()->data << endl;
    cout << "Length: " << q->getLength() << endl;
    q->enqueue(3);
    cout << "Head: " << q->peek()->data << endl;
    cout << "Length: " << q->getLength() << endl;

    // check deque
    cout << "Pop: " << q->deque() << endl;
    cout << "Length: " << q->getLength() << endl;
    cout << "Head: " << q->peek()->data << endl;
    cout << "Pop: " << q->deque() << endl;
    cout << "Length: " << q->getLength() << endl;
    cout << "Head: " << q->peek()->data << endl;
    q->~Queue();
    return 0;
}