// A2. Doti naturāli skaitļi m un n. Noskaidrot starpību starp m un n dažādo
// reizinātāju skaitu (piemēram, m=9, n=6, atbilde ir -1, jo m ir mazāk
// reizinātāju nekā n).

// Gunārs Ābeltiņš
// ga22008
// 2022.10.10

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int reizinatajuSkaits(int &x)
{
    int rezultats = 0;

    // Ciklu sāk no viens, jo nulle nevar būt reizinātājs.
    // Ciklu veic līdz kvadrātsaknei no x, lai optimizētu koda ātrumu.
    for (int i = 1; i * i <= x; ++i)
    {
        // Katru reizinātāju pieskaita kā divus.
        if (x % i == 0)
        {
            // Ja reizinātājs sakrīt ar skaitļa kvadrātsakni, to pieskaita, kā
            // vienu, jo tas atkārtojas tikai vienreiz.
            rezultats += (i * i == x ? 1 : 2);
        }
    }

    return rezultats;
}

int main()
{
    for (int turpinat = 1; turpinat;)
    {
        int m, n;
        cout << "Ievadi divus naturālus skaitļus!" << endl;

        do
        {
            cout << "Pirmais skaitlis: ";
            cin >> m;
        } while (m <= 0);

        do
        {
            cout << "Otrais skaitlis: ";
            cin >> n;
        } while (n <= 0);

        cout << "Dažādo reizinātāju starpība - " << reizinatajuSkaits(m) - reizinatajuSkaits(n) << endl;

        cout << "Atkārtot? (1 | 0) ";
        cin >> turpinat;
    }

    return 0;
}

//  Ievads | Izvads
//  -------|--------
//     9 8 | 1
//  -------|--------
//   10 10 | 0
//  -------|--------
//   11 10 | -2
//  -------|--------
//   -1 -1 | Pirmais skaitlis: 
//  -------|--------
