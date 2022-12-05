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
    cout << "Rinda garumā " << garums << " tika likvidēta!" << endl;
}

void Cqueue::Ielikt(char elements)
{
    for(int i = 0; i < 5; ++i){
        cout << (int)rinda[i] << "|";
    }
    cout << endl;
    if (garums == 5)
    {
        cout << "Rinda ir pilna! Elements netika pievienots!" << endl;
        return;
    }

    rinda[pozicija] = elements;

    for(int i = 0; i < 5; ++i){
        cout << (int)rinda[i] << "|";
    }
    cout << endl;

    ++garums;
    ++pozicija;
    if (pozicija > 4)
    {
        pozicija = 0;
    }

    return;
}

char Cqueue::Izņemt()
{
    if (garums == 0)
    {
        cout << "Rinda ir tukša! Elements netika izņemts!" << endl;
        return 0;
    }

    --garums;

    return rinda[((pozicija + 4) - garums) % 5];
}

int Cqueue::CikElementu()
{
    return garums;
}

bool Cqueue::VaiTukša()
{
    return (garums);
}
