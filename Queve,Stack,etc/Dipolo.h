#include <iostream>
#include "Doubly.h"
// dependecia archivo Doubly.h
using namespace std;

template <class t>
class Dipolo : protected Doubly<t>
{
private:
    /* data */
public:
    Dipolo(/* args */) {};
    ~Dipolo() {};
    bool isEmptyDipo()
    {
        return this->isEmpty();
    }

    int getLenghtDipo()
    {
        return this->getLenght();
    };

    void push(t valor)
    {
        this->insert(valor, this->getLast(), 0);
    };

    void unShift(t valor)
    {
        this->insert(valor, this->getFirst());
        return;
    }

    t pop()
    {
        t value = *(this->get(this->getLast()));
        this->deleteNodo(this->getLast());
        return value;
    };

    t shift()
    {
        t value = *(this->get(this->getFirst()));
        this->deleteNodo(this->getFirst());
        return value;
    }
};
