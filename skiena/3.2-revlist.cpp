#include <iostream>

using namespace std;

struct node
{
    const char *s;
    node *next;

    node(const char *S)
        : s(S)
    {
    }
};

node *list_insert_before(node *a, node *b)
{
    b->next = a;
    return b;
}

node *list_reverse(node *a)
{
    node *prev = NULL, *next;

    for ( ; a; a = next)
    {
        next = a->next;
        a->next = prev;
        prev = a;
    }

    return prev;
}

void list_free(node *a)
{
    node *next;

    for ( ; a; a = next)
    {
        next = a->next;
        delete a;
    }
}

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        cout << "usage: " << argv[0] << " elem1 elem2 ..."
            << endl;
        return 0;
    }

    // read
    node *l = NULL;
    while (--argc)
        l = list_insert_before(l, new node(*++argv));

    // print
    cout << "list:    ";
    for (node *n = l; n; n = n->next)
        cout << ' ' << n->s;
    cout << endl;

    // reverse
    l = list_reverse(l);
    
    // print
    cout << "reversed:";
    for (node *n = l; n; n = n->next)
        cout << ' ' << n->s;
    cout << endl;

    list_free(l);
    return 0;
}
