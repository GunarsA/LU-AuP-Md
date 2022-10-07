#include <iostream>

using std::cin;
using std::cout;
using std::endl;

void izvaditVienadosCiparus(int x)
{
    int ciparuSkaits[10]{};
    while (x > 0)
    {
        ciparuSkaits[(x % 10) - 1]++;
        x /= 10;
    }

    bool atkartojas = false;
    for (int i = 0; i < 10; ++i)
    {
        if (ciparuSkaits[i] > 1)
        {
            atkartojas = 1;
            cout << "Cipars " << i + 1 << " atkartojas " << ciparuSkaits[i] << " reizes." << endl;
        }
    }
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
        } while (!(x > 0));

        izvaditVienadosCiparus(x);
        cout << "Atkārtot? (1 | 0): ";
        cin >> ok;
    }

    return 0;
}