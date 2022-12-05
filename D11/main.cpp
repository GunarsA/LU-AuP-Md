#include <iostream>
#include "program.hpp"

using namespace std;

int main()
{
    Cqueue Burtu_rinda;

    int ok = 1;
    do
    {
        cout << "Ievadiet darbību! : "; 
        char darbība[4];
        cin.get(darbība, 10);

        switch (darbība[0])
        {
        case '+':
            Burtu_rinda.Ielikt(darbība[2]);
            cout << "Elements " << darbība[2] << " tika ielikts virknē." << endl;
            break;
        case '-':
        {
            char pagaidu = Burtu_rinda.Izņemt();
            if (pagaidu)
                cout << "Simbols " << Burtu_rinda.Izņemt() << " tika izņemts no virknes." << endl;
            break;
        }
        case '?':
            cout << (Burtu_rinda.VaiTukša() ? "Rinda ir tukša." : "Rinda nav tukša.") << endl;
            if (!Burtu_rinda.VaiTukša())
                cout << "Rinda ir " << Burtu_rinda.CikElementu() << " elementi." << endl;
            break;
        default:
            ok = 0;
            break;
        }

        cin.ignore();
    } while (ok);

    return 0;
}