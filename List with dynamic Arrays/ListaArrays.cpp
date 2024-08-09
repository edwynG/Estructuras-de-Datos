#include <iostream>

using namespace std;

template <class t>
class List
{
private:
    /* data */
    const int step;
    int tam;
    t *arr;
    void Resize(int capacity);

public:
    int capacity;

    List(int longitud);
    ~List();
    int Size();
    t *Get(int n);
    void Push(t element);
    bool Remove(int pos);
    bool Insert(int pos, t element);
};

template <class t>
List<t>::List(int longitud) : step(longitud)
{
    this->capacity = step;
    tam = 0;
    arr = new t[step];
}

template <class t>
List<t>::~List()
{
    delete[] arr;
}

template <class t>
void List<t>::Push(t element)
{
    if (tam >= capacity)
        Resize(tam + step);
    tam++;
    arr[tam - 1] = element;
}

template <class t>
t *List<t>::Get(int n)
{
    if (!(n - 1 < tam && n - 1 >= 0))
        return NULL;
    return &arr[n - 1];
}

template <class t>
bool List<t>::Insert(int pos, t element)
{
    if (tam == capacity)
        Resize(capacity + step);
    if (!(pos - 1 < tam && pos > 0))
        return false;
    for (int i = tam - 1; i >= pos - 1; i--)
    {
        arr[i + 1] = arr[i];
    }
    arr[pos - 1] = element;
    tam++;
    return true;
}

template <class t>
int List<t>::Size()
{
    return tam;
}

template <class t>
void List<t>::Resize(int capacity)
{
    t *Temp = new t[capacity];
    for (int i = 0; i < tam; i++)
    {
        Temp[i] = arr[i];
    }
    delete[] arr;
    arr = Temp;
    delete[] Temp;
    this->capacity = capacity;
}

template <class t>
bool List<t>::Remove(int pos)
{
    if (!(pos - 1 < tam && pos - 1 >= 0))
        return false;
    arr[pos - 1] = 0;
    for (int i = pos - 1; i < tam - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
    tam--;
    if ((capacity - tam) > step)
        Resize((capacity - (capacity - tam)) + step);
    return true;
}

