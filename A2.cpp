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

// Funkcija ir optimizēta lai strādātu kvadrātsakniskā laikā, jo katram
// skaitļa reizinātājam (izņemot gadījumu kad tas ir kvadrātsakne) 
// ir vielviens reizinātajs, ar kuru sareizinot iegūst pašu skaitli.
// Tāpēc for ciklam jāstrādā tikai lidz skaitļa kvadrātsaknei un 
// katrs atrsastais reizinātājs jāsakaita kā divi.

int reizinatajuSkaits(int &x)
{
    int rezultats = 0;

    for (int i = 1; i * i <= x; ++i)
    {
        if (x % i == 0)
        {
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
        cout << "Pirmais skaitlis - ";
        cin >> m;

        while (m <= 0)
        {
            cin >> m;
        }

        cin >> n;

        cout << "Dažādo reizinātāju starpība - " << reizinatajuSkaits(m) - reizinatajuSkaits(n) << endl;

        cout << "Atkārtot? (1 | 0) ";
        cin >> turpinat;
    }

    return 0;
}

//  Ievads | Izvads
//  -------|--------
//     9 8 | -1
//  -------|--------
//   10 10 | 0
//  -------|--------
//   11 10 | -2
//  -------|--------
