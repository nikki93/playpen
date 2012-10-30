#include <iostream>
#include <stack>

using namespace std;

void check_parens(const char *s)
{
    stack<const char *> open;

    for (const char *c = s; *c; ++c)
        switch (*c)
        {
            case '(':
                open.push(c);
                break;

            case ')':
                if (open.empty())
                {
                    cout << "unmatched paren:" << endl;
                    cout << s << endl;

                    for (const char *d = s; d < c; ++d)
                        cout << ' ';
                    cout << '^' << endl;
                    return;
                }

                open.pop();
                break;
        }

    if (open.empty())
        cout << "good!" << endl;
    else
    {
        cout << "unmatched paren: " << endl;
        cout << s << endl;

        for (const char *d = s, *c = open.top(); 
                d < c; ++d)
            cout << ' ';
        cout << '^' << endl;
    }
}

int main(int argc, char **argv)
{
    if (argc < 2)
        cout << "usage: " << argv[0] << " str" << endl;
    else
        check_parens(argv[1]);

    return 0;
}
