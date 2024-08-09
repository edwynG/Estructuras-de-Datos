#include <iostream>
#include "Doubly.h"

using namespace std;

template <class t>
class Queve
{
private:
    typedef Node<t> *pos;
    Doubly<t> COLA;

public:
    Queve(/* args */) {};
    void push(t valor)
    {
        COLA.insert(valor, COLA.getLast(), 0);
    };

    t pop()
    {
        int res = COLA.getFirst()->value;
        COLA.deleteNodo(COLA.getFirst());
        return res;
    };

    bool isEmptyQueve()
    {
        return COLA.isEmpty();
    };

    int getCapacity()
    {
        return COLA.getLenght();
    };
};
