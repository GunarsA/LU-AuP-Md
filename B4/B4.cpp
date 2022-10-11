// B4. Noskaidrot, vai dotajā naturālajā skaitlī ir atrodami vienādi
// cipari. Ja ir, izdrukāt tos un skaitu, cik reižu dotais cipars
// ir sastopams. Skaitļa dalīšana ciparos jāveic skaitliski.

// Gunārs Ābeltiņš
// ga22008
// 2022.10.11


#include <iostream>

using std::cin;
using std::cout;
using std::endl;

void izvaditVienadosCiparus(int x)
{
    int ciparuSkaits[10]{};
    while (x > 0)
    {
        // Visus ciparus var iegūt paņemot atlikumu dalot ar 10, jo ievads
        // tiek dots decimālajā skaitīšanas sistēmā.
        ciparuSkaits[x % 10]++;
        x /= 10;
    }

    bool atkartojas = false;
    for (int i = 0; i < 10; ++i)
    {
        if (ciparuSkaits[i] > 1)
        {
            atkartojas = 1;
            cout << "Cipars " << i << " atkartojas " << ciparuSkaits[i] << " reizes." << endl;
        }
    }

    // Ir iespējams ka neviens cipars neatkārtojas.
    if (!atkartojas)
    {
        cout << "Neviens cipars neatkārtojas." << endl;
    }

    return;
}

int main()
{
    for (int ok = 1; ok;)
    {
        int x;
        do
        {
            cout << "Ievadi naturālu skaitli, kuram tiks noteikts vai cipari atkārtojas: ";
            cin >> x;
        } while (x < 1);

        izvaditVienadosCiparus(x);
        cout << "Atkārtot? (1 | 0): ";
        cin >> ok;
    }

    return 0;
}


//  Ievads | Izvads
// --------|----------------------------------------------------------------------
//  413413 | Cipars 1 atkartojas 2 reizes.
//         | Cipars 3 atkartojas 2 reizes.
//         | Cipars 4 atkartojas 2 reizes.
// --------|----------------------------------------------------------------------
// 1000000 | Cipars 0 atkartojas 6 reizes.
// --------|----------------------------------------------------------------------
//     123 | Neviens cipars neatkārtojas.
// --------|----------------------------------------------------------------------
//     -10 | Ievadi naturālu skaitli, kuram tiks noteikts vai cipari atkārtojas: