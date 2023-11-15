#include <iostream>

/*
    --ARRAY LIST--
    An array that dynamically grows in size.
    It keeps track of the "length" and the capacity of the array.
        - length being the index of the most recent element
        - capacity being the actual size of the array
        - when length == capacity we grow the array by creating a new array and copying the old array into the new
*/
template <typename T>
class ArrayList
{
private:
    int length;
    int capacity;
    T *array;

public:
    ArrayList()
    {
        length = 0;
        capacity = 10;
        array = new Array(capacity);
    }
    ArrayList(int size)
    {
        length = 0;
        capacity = size;
        array = new Array(capacity);
    }
    ~ArrayList()
    {
        delete[] array;
    }
    // push a new element into the array at the end
    void push(const T &element)
    {
        // check to make sure that the array has the capacity to store more elements
        if (capacity == length)
        {
            capacity *= 2;
            T *newArray = new T[capacity];
            for (int i = 0; i < length; i++)
            {
                newArray[i] = array[i];
            }
            delete[] array;
            array = newArray;
        }
        else
        {
            array[length++] = element;
        }
    }
    T pop();
    T get(int);
    int size();
    void clear();
    bool contains(T);
    void remove(int);
};