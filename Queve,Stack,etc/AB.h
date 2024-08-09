#include <iostream>

using namespace std;

template <class t>
struct Node
{
    t value;
    Node<t> *left;
    Node<t> *right;
    Node<t> *father;
    Node(t value)
    {
        this->value = value;
        this->left = NULL;
        this->right = NULL;
        this->father = NULL
    }
};

template <class t>
class Binary
{
private:
    typedef Node<t> *def;
    def root;
    int weight;

public:
    Binary(/* args */)
    {
        this->root = NULL;
        this->weight = 0;
    };
    ~Binary() {};
    int getWeight()
    {
        return this->weight;
    }
    def getRoot()
    {
        return root;
    }
    def getSubRaiz(t value, def raiz)
    {

        if (raiz->value == value)
        {
            return raiz;
        }

        if (raiz->left != NULL)
        {
            return getSubRaiz(value, raiz->left);
        }
        if (raiz->right != NULL)
        {
            return getSubRaiz(value, raiz->right);
        }
        return NULL;
    }
    void insertSheet(t value, def subroot = NULL, bool lateral = true)
    {
        def newSheet = new Node<t>(value);
        weight++;
        if (this->root == NULL)
        {
            this->root = newSheet;
            return;
        }
        if (lateral)
        {
            subroot->left = newSheet;
            newSheet->father = subroot;
            return;
        }
        subroot->right = newSheet;
        newSheet->father = subroot;
    }

    void deleteRaiz(def node)
    {
        def father = node->father;
    }

    void output(def raiz)
    {
        cout << raiz->value << " ";
        if (raiz->left != NULL)
        {
            this->output(raiz->left);
        }
        if (raiz->right != NULL)
        {
            this->output(raiz->right);
        }
    }
};
