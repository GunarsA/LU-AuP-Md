#include <iostream>
#include "program.hpp"

using std::cin;
using std::cout;
using std::endl;

Cqueue::Cqueue()
{
    garums = 0;
    pozicija = 0;
}

Cqueue::~Cqueue()
{
    cout << "Rinda tika likvidēta! " << endl;
    if (garums)
        cout << "Likvidēto elementu skaits: " << garums << endl;
}

void Cqueue::enqueue(char elements)
{
    if (garums == 5)
    {
        cout << "Rinda ir pilna! Elements netika pievienots!" << endl;
        return;
    }

    rinda[pozicija] = elements;

    ++garums;
    ++pozicija;
    if (pozicija > 4)
    {
        pozicija = 0;
    }

    return;
}

char Cqueue::dequeue()
{
    if (isEmpty())
    {
        cout << "Rinda ir tukša! Elements netika izņemts!" << endl;
        return 0;
    }

    --garums;

    return rinda[((pozicija + 4) - garums) % 5];
}

int Cqueue::count()
{
    return garums;
}

bool Cqueue::isEmpty()
{
    return !(bool)garums;
}
