// D11. Izveidot klasi "Burtu rinda" - Cqueue (queue, pa vienu pusi ieliek, pa 
// otru izņem!), kurā glabājas masīvs ar burtiem (char) garumā pieci un
// rindas elementu skaits. Klasei izveidot šādas metodes: (1) konstruktors,
// (2) destruktors, kurš paziņo par objekta likvidēšanu un likvidēto elementu
// skaitu (ja likvidēšanas brīdī rinda nav tukša), (3) metode "Ielikt" - enqueue,
// kas pievieno rindai elementu, ja tā nav pilna, (4) metode "Izņemt" - dequeue,
// kas izņem no rindas elementu un atgriež tā vērtību, (5) metode 
// "CikElementu" - count, kas atgriež elementu skaitu rindā, (6) metode 
// "VaiTukša" - isEmpty, kas noskaidro, vai rinda ir tukša.  
// Pirms uzdevuma veikšanas precīzi noskaidrot, ko nozīmē jēdziens rinda (queue).

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
            if (Burtu_rinda.count() != 5 && ((darbiba[2] >= 'a' && darbiba[2] <= 'z') || (darbiba[2] >= 'A' && darbiba[2] <= 'Z')))
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
                cout << "Rindā ir " << Burtu_rinda.count() << " burti." << endl;
            break;
        default:
            ok = 0;
            break;
        }

        cin.ignore();
    } while (ok);

    return 0;
}

// Ievads | Izvads
// -------|----------------------------------------------------------------------
//      ? | Rinda ir tukša
//    + a | Burts 'a' tika ielikts virknē.
//    + b | Burts 'b' tika ielikts virknē.
//    + c | Burts 'c' tika ielikts virknē.
//      ? | Rindā nav tukša.
//        | Rinda ir 3 burti.
//    + b | Burts 'e' tika ielikts virknē.
//    + e | Burts 'f' tika ielikts virknē.
//      ? | Rinda nav tukša
//        | Rindā ir 5 burti.
//    + h | Rinda ir pilna! Elements netika pievienots!
//      - | Burts 'a' tika izņemts no virknes.
//      - | Burts 'b' tika izņemts no virknes.
//      - | Burts 'c' tika izņemts no virknes.
//      - | Burts 'd' tika izņemts no virknes.
//      - | Burts 'e' tika izņemts no virknes.
//      - | Rinda ir tukša! Burts netika izņemts!
//    +   | Elements nav burts! Elements netika pievienots!
//        | Rinda tika likvidēta!
// -------|----------------------------------------------------------------------
//    + a | Burts 'a' tika izņemts no virknes.
//        | Rinda tika likvidēta!
//        | Likvidēto elementu skaits: 1