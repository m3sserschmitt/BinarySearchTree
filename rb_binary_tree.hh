#ifndef RB_BINARY_TREE_HH
#define RB_BINARY_TREE_HH

#include "binary_tree.hh"
#include "rb_node.hh"

#define RB_PARENT(z) ((RedBlackNode<T> *)z->get_parent())
#define RB_GRANDPARENT(z) ((RedBlackNode<T> *)(z->get_parent()->get_parent()))

template <class T>
class RBBinarySearchTree : public BinarySearchTree<T>
{
    // rotatie spre stanga in jurul nodului x;
    void left_rotate(Node<T> *x);

    // rotatie la dreapta in jurul nodului x;
    void right_rotate(Node<T> *x);

    // restabileste culorile in arbore dupa inserarea unui nou nod;
    void insert_fixup(RedBlackNode<T> *z);

public:
    RBBinarySearchTree();
    ~RBBinarySearchTree();

    void insert(T x);
};

template <class T>
RBBinarySearchTree<T>::RBBinarySearchTree() : BinarySearchTree<T>()
{
    this->nil = new RedBlackNode<T>(0, BLACK);
    this->root = this->nil;
}

template <class T>
RBBinarySearchTree<T>::~RBBinarySearchTree()
{
    delete this->nil;
}

template <class T>
void RBBinarySearchTree<T>::left_rotate(Node<T> *x)
{
    // se presupune ca dreapta lui x este nenula;
    Node<T> *y = (Node<T> *)x->get_right();

    // dreapta lui x devine stanga lui y;
    x->set_right(y->get_left());

    // daca stanga lui y este nenula
    if (y->get_left() != this->nil)
    {
        // atunci stanga lui y primeste ca parinte pe x;
        Node<T> *y_left = (Node<T> *)y->get_left();
        y_left->set_parent(x);
    }

    // parintele lui x devine acum parintele lui y;
    y->set_parent(x->get_parent());

    Node<T> *x_parent = (Node<T> *)x->get_parent();

    // daca parintele lui x este nul (i.e. x este radacina)
    if (x_parent == this->nil)
    {
        // atunci y devine radacina
        this->root = y;
    }
    // daca x a fost copil stang
    else if (x == x_parent->get_left())
    {
        // atunci y devine si el copil stang;
        x_parent->set_left(y);
    }
    else // altfel devine copil drept;
    {
        x_parent->set_right(y);
    }

    // x este acum stanga lui y;
    y->set_left(x);

    // dupa care y devine parintele lui x;
    x->set_parent(y);
}

template <class T>
void RBBinarySearchTree<T>::right_rotate(Node<T> *x)
{
    // codul este perfect simetric cu cazul "left_rotate"
    // doar se interschimba "left" cu "right";

    Node<T> *y = (Node<T> *)x->get_left();
    x->set_left(y->get_right());

    if (y->get_right() != this->nil)
    {
        Node<T> *y_right = (Node<T> *)y->get_right();
        y_right->set_parent(x);
    }

    y->set_parent(x->get_parent());

    Node<T> *x_parent = (Node<T> *)x->get_parent();

    if (x_parent == this->nil)
    {
        this->root = y;
    }
    else if (x == x_parent->get_left())
    {
        x_parent->set_left(y);
    }
    else
    {
        x_parent->set_right(y);
    }

    y->set_right(x);
    x->set_parent(y);
}

template <class T>
void RBBinarySearchTree<T>::insert_fixup(RedBlackNode<T> *z)
{
    RedBlackNode<T> *y;

    while (RB_PARENT(z)->get_color() == RED)
    {
        if (z->get_parent() == RB_GRANDPARENT(z)->get_left())
        {
            y = (RedBlackNode<T> *)z->get_parent()->get_parent()->get_right();

            if (y->get_color() == RED)
            {
                RB_PARENT(z)->set_color(BLACK);
                y->set_color(BLACK);
                RB_GRANDPARENT(z)->set_color(RED);
                z = RB_GRANDPARENT(z);
            }
            else
            {
                if (z == z->get_parent()->get_right())
                {
                    z = RB_PARENT(z);
                    this->left_rotate(z);
                }

                RB_PARENT(z)->set_color(BLACK);
                RB_GRANDPARENT(z)->set_color(RED);
                this->right_rotate(RB_GRANDPARENT(z));
            }
        }
        else
        {
            y = (RedBlackNode<T> *)z->get_parent()->get_parent()->get_left();

            if (y->get_color() == RED)
            {
                RB_PARENT(z)->set_color(BLACK);
                y->set_color(BLACK);
                RB_GRANDPARENT(z)->set_color(RED);
                z = RB_GRANDPARENT(z);
            }
            else
            {
                if (z == z->get_parent()->get_left())
                {
                    z = RB_PARENT(z);
                    this->right_rotate(z);
                }

                RB_PARENT(z)->set_color(BLACK);
                RB_GRANDPARENT(z)->set_color(RED);
                this->left_rotate(RB_GRANDPARENT(z));
            }
        }
    }

    ((RedBlackNode<T> *)this->root)->set_color(BLACK);
}

template <class T>
void RBBinarySearchTree<T>::insert(T x)
{
    // copiaza cheia lui n intr-un RedBlackNode;
    RedBlackNode<T> *z = new RedBlackNode<T>(x);

    // inserarea propriu-zisa nu tine cont de culoare
    // deci se poate apela metoda insert ca intr-un arbore simplu;
    if (BinarySearchTree<T>::insert(z) != this->nil)
    {
        // seteaza copiii lui z la nil;
        z->set_left(this->nil);
        z->set_right(this->nil);

        // insert_fixup este specifica unui RedBlackSearchTree
        // si restabileste regulile unui RB-Tree;
        this->insert_fixup(z);
    }
}

#endif
