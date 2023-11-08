#include "stack.h"

int main()
{
    Stack *stack = new Stack();

    stack->push(0);
    stack->push(1);
    cout << "Peek: " << stack->peek() << endl;
    cout << "Pop: " << stack->pop() << endl;
    cout << "Peek: " << stack->peek() << endl;
    stack->push(2);
    stack->push(3);
    stack->push(4);
    cout << "Peek: " << stack->peek() << endl;
    cout << "Pop: " << stack->pop() << endl;
    cout << "Peek: " << stack->peek() << endl;
    return 0;
}