#include <iostream>
#include <windows.h>
#include "program.hpp"

#pragma execution_character_set("utf-8")

using namespace std;

int main()
{
    SetConsoleOutputCP(65001);

    Cqueue Burtu_rinda;

    cout << "----------------------------------" << endl
         << "Iespējamās darbības:" << endl
         << "'+ [burts]' - pievienot virknei burtu" << endl
         << "'-' - izņemt no virknes burts" << endl
         << "'?' - iegūt informāciju par virkni" << endl
         << "----------------------------------" << endl;

    int ok = 1;
    do
    {
        cout << "Ievadiet darbību! : ";
        char darbiba[4];
        cin.get(darbiba, 10);

        switch (darbiba[0])
        {
        case '+':
            if (Burtu_rinda.count() != 5)
                cout << "Burts '" << darbiba[2] << "' tika ielikts virknē." << endl;
            Burtu_rinda.enqueue(darbiba[2]);
            break;
        case '-':
            if (!Burtu_rinda.isEmpty())
                cout << "Burts '" << Burtu_rinda.dequeue() << "' tika izņemts no virknes." << endl;
            else
                cout << "Rinda ir tukša! Burts netika izņemts!" << endl;
            break;
        case '?':
            cout << (Burtu_rinda.isEmpty() ? "Rinda ir tukša." : "Rinda nav tukša.") << endl;
            if (!Burtu_rinda.isEmpty())
                cout << "Rinda ir " << Burtu_rinda.count() << " burti." << endl;
            break;
        default:
            ok = 0;
            break;
        }

        cin.ignore();
    } while (ok);

    return 0;
}