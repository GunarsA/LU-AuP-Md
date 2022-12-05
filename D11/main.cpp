#include <iostream>
#include "program.hpp"

using namespace std;

int main()
{
    Cqueue Burtu_rinda;

    int ok = 1;
    do
    {
        char darbība[3];
        cin.get(darbība, 10);

        switch (darbība[0])
        {
        case '+':
            Burtu_rinda.Ielikt(darbība[2]);
            break;
        case '-':
            cout << Burtu_rinda.Izņemt() << endl;
            break;
        case '?':
            cout << Burtu_rinda.CikElementu() << endl;
            break;
        default:
            ok = 0;
            break;
        }

        cin.ignore();
    } while (ok);

    return 0;
}