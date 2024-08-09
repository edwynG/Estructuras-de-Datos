#include <iostream>

using namespace std;

template <class t>
class Heap
{
private:
    t *arr;
    int size;
    int cant;
    const int step;

public:
    Heap(int step = 4) : step(step)
    {
        this->size = 0;
        this->cant = 0;
        this->arr = NULL;
        this->resize();
    };

    ~Heap()
    {
        delete[] arr;
    };

    void resize()
    {
        if (arr == NULL)
        {
            this->arr = new t[(this->step)];
            this->cant += step;
            return;
        }
        this->cant += step;
        t *newArr = new t[(size + step)];

        for (int i = 0; i < this->size; i++)
        {
            newArr[i] = this->arr[i];
        }
        delete[] arr;
        arr = newArr;
        delete[] newArr;
    }

    void print()
    {
        for (int i = 0; i < this->size; i++)
        {
            cout << this->arr[i] << " ";
        }
        cout << endl;
    }

    void insert(t value)
    {
        if (this->size == 0)
        {
            this->size++;
            arr[0] = value;
            return;
        }
        arr[size] = value;
        this->size++;
        if (this->cant - this->size < 2)
            resize();

        for (int i = size - 1; i > 0; i--)
        {
            if (arr[(i - 1) / 2] < arr[i])
            {
                t temp = arr[i];
                arr[i] = arr[((i - 1) / 2)];
                arr[((i - 1) / 2)] = temp;
                i = (i - 1) / 2;
            }
        }
    }
};
