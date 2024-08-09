#include <iostream>
#include "Doubly.h"

using namespace std;

template <class t>
class Stack
{
private:
    Doubly<t> List;

public:
    Stack(/* args */) {};
    ~Stack() {};
    void push(t value)
    {
        List.insert(value, List.getFirst());
    }

    t pop()
    {
        t result = *(List.get(List.getFirst()));
        List.deleteNodo(List.getFirst());
        return result;
    }

    bool isEmptyStack()
    {
        return List.isEmpty();
    }
};
