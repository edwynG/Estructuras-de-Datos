#include <iostream>

using namespace std;

template <class t>
struct Node
{
    t value;
    Node<t> *next;

    Node(t element, Node<t> *next)
    {
        this->next = next;
        this->value = element;
    }
};

template <class t>
class List
{
private:
    typedef Node<t> *pos;
    pos first;
    pos last;
    int lenght;

public:
    List()
    {
        first = NULL;
        last = NULL;
        lenght = 0;
    };
    ~List()
    {
        while (!(isEmpty()))
        {
            DeleteNodo(getFirst());
        }
    };
    int getLenght();
    Node<t> *getFirst();
    Node<t> *getLast();
    bool isEmpty();
    void Next(pos &nodo);
    t *get(pos nodo);
    void DeleteNodo(pos nodo);
    void SearchBefore(pos &nodo);
    void insert(t &valor, pos nodo, bool before = true)
    {
        pos newNode = new Node<t>(valor, nodo);
        if (isEmpty())
        {
            first = newNode;
            last = newNode;
            lenght++;
            return;
        }

        if (before)
        {
            if (nodo == getFirst())
            {
                first = newNode;
                lenght++;
                return;
            }
            pos temp = nodo;
            SearchBefore(temp);
            temp->next = newNode;
            lenght++;
            return;
        }
        else
        {
            if (nodo == getLast())
            {
                nodo->next = newNode;
                newNode->next = NULL;
                last = newNode;
                lenght++;
                return;
            }
            pos temp = nodo->next;
            newNode->next = temp;
            nodo->next = newNode;
            lenght++;
        }
    };
};

template <class t>
void List<t>::SearchBefore(pos &nodo)
{
    pos temp = getFirst();
    while (temp->next != nodo)
    {
        Next(temp);
    }
    nodo = temp;
}

template <class t>
int List<t>::getLenght()
{
    return lenght;
}

template <class t>
Node<t> *List<t>::getFirst()
{
    return first;
}

template <class t>
Node<t> *List<t>::getLast()
{
    return last;
}

template <class t>
void List<t>::Next(pos &nodo)
{
    if (nodo != NULL)
        nodo = nodo->next;
}

template <class t>
t *List<t>::get(pos nodo)
{
    if (nodo == NULL)
        return NULL;
    return &nodo->value;
};

template <class t>
bool List<t>::isEmpty()
{
    return lenght == 0;
};

template <class t>
void List<t>::DeleteNodo(pos nodo)
{
    if (nodo == NULL)
        return;
    if (nodo == getFirst())
    {
        first = nodo->next;
        delete nodo;
        lenght--;
        return;
    }

    if (nodo == getLast())
    {
        pos temp = nodo;
        SearchBefore(temp);
        last = temp;
        temp->next = NULL;
        delete nodo;
        lenght--;
        return;
    }
    pos temp = nodo;
    SearchBefore(temp);
    temp->next = nodo->next;

    delete nodo;
    lenght--;
};
