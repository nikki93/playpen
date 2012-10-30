#include <iostream>

using namespace std;

// 'r', 'w' or 'b'
int examine(char **a, int i)
{
    return *a[i];
}

void swap(char **a, int i, int j)
{
    char *t = a[i];
    a[i] = a[j];
    a[j] = t;
}

// rwb sort using only 'examine' and 'swap'
void rwbsort(char **a, int n)
{
    int i = 0, l = 0, h = n - 1;

    // invariant: 
    //    <l:       'r'
    //    >=l, <i:  'w'
    //    >=i, <=h:  unknown
    //    >h:       'b'

    // either i increases or h decreases so linear

    while (i <= h) // while more unknowns
        switch (examine(a, i))
        {
            case 'r':
                swap(a, i++, l++);
                break;

            case 'w':
                ++i;
                break;

            case 'b':
                swap(a, i, h--);
                break;
        }
}

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        cout << "usage: " << argv[0] << " r b w w ... "
            << endl;
        return 0;
    }

    // sort
    rwbsort(argv + 1, argc - 1);

    // print
    cout << "sorted:";
    while (--argc)
        cout << ' ' << *++argv;
    cout << endl;

    return 0;
}
