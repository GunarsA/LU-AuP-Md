#include <iostream>
#include "program.hpp"

using namespace std;

int main()
{
    Cqueue Burtu_rinda;

    int ok = 1;
    do
    {
        for (int i = 0; i < 5; ++i)
        {
            cout << (int)Burtu_rinda.rinda[i] << "|";
        }
        cout << endl;

        char darbība[4];

        for (int i = 0; i < 5; ++i)
        {
            cout << (int)Burtu_rinda.rinda[i] << "|";
        }
        cout << endl;

        cin.get(darbība, 10);

        for (int i = 0; i < 5; ++i)
        {
            cout << (int)Burtu_rinda.rinda[i] << "|";
        }
        cout << endl;

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

        for (int i = 0; i < 5; ++i)
        {
            cout << (int)Burtu_rinda.rinda[i] << "|";
        }
        cout << endl;

        cin.ignore();
    } while (ok);

    return 0;
}