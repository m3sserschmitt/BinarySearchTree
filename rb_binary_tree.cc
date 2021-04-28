#include "rb_binary_tree.hh"

using namespace std;

RBBinarySearchTree::RBBinarySearchTree() : BinarySearchTree()
{
    this->nil = new RedBlackNode(0, BLACK);
    this->root = this->nil;
}

RBBinarySearchTree::~RBBinarySearchTree() 
{
    delete this->nil;
}

void RBBinarySearchTree::left_rotate(Node *x)
{
    // se presupune ca dreapta lui x este nenula;
    Node *y = (Node *)x->get_right();

    // dreapta lui x devine stanga lui y;
    x->set_right(y->get_left());

    // daca stanga lui y este nenula
    if (y->get_left() != this->nil)
    {
        // atunci stanga lui y primeste ca parinte pe x;
        Node *y_left = (Node *)y->get_left();
        y_left->set_parent(x);
    }

    // parintele lui x devine acum parintele lui y;
    y->set_parent(x->get_parent());

    Node *x_parent = (Node *)x->get_parent();

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

void RBBinarySearchTree::right_rotate(Node *x)
{
    // codul este perfect simetric cu cazul "left_rotate"
    // doar se interschimba "left" cu "right";

    Node *y = (Node *)x->get_left();
    x->set_left(y->get_right());

    if (y->get_right() != this->nil)
    {
        Node *y_right = (Node *)y->get_right();
        y_right->set_parent(x);
    }

    y->set_parent(x->get_parent());

    Node *x_parent = (Node *)x->get_parent();

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

void RBBinarySearchTree::insert_fixup(RedBlackNode *z)
{
    RedBlackNode *y;
    RedBlackNode *z_parent;
    RedBlackNode *z_grandpa;

    while (dynamic_cast<RedBlackNode *>((Node *)z->get_parent())->get_color() == RED)
    {
        z_parent = dynamic_cast<RedBlackNode *>((Node *)z->get_parent());
        z_grandpa = dynamic_cast<RedBlackNode *>((Node *)z->get_parent()->get_parent());

        if (z_parent == z_grandpa->get_left())
        {
            y = dynamic_cast<RedBlackNode *>((Node *)z_grandpa->get_right());

            if (y->get_color() == RED)
            {
                z_parent->set_color(BLACK);
                y->set_color(BLACK);
                z_grandpa->set_color(RED);
                z = z_grandpa;
            }
            else
            {
                if (z == z_parent->get_right())
                {
                    z = z_parent;
                    this->left_rotate(z);
                }

                z_parent->set_color(BLACK);
                z_grandpa->set_color(RED);
                right_rotate(z_grandpa);
            }
        }
        else
        {
            y = dynamic_cast<RedBlackNode *>((Node *)z_grandpa->get_left());

            if (y->get_color() == RED)
            {
                z_parent->set_color(BLACK);
                y->set_color(BLACK);
                z_grandpa->set_color(RED);
                z = z_grandpa;
            }
            else
            {
                if (z == z_parent->get_left())
                {
                    z = z_parent;
                    this->right_rotate(z);
                }

                z_parent->set_color(BLACK);
                z_grandpa->set_color(RED);
                left_rotate(z_grandpa);
            }
        }
    }

    dynamic_cast<RedBlackNode *>(this->root)->set_color(BLACK);
}

void RBBinarySearchTree::insert(Node n)
{
    // copiaza cheia lui n intr-un RedBlackNode;
    RedBlackNode *z = new RedBlackNode(n);

    // inserarea propriu-zisa nu tine cont de culoare
    // deci se poate apela metoda insert ca intr-un arbore simplu;
    BinarySearchTree::insert(z);
    
    // seteaza copiii lui z la nil;
    z->set_left(this->nil);
    z->set_right(this->nil);

    // insert_fixup este specifica unui RedBlackSearchTree
    // si restabileste regulile unui RB-Tree;
    this->insert_fixup(z);
}
