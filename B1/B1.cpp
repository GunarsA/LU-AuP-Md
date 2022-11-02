// B1. Dots naturāls skaitis n. Atrast visus tādus naturālu skaitļu pārīšus a
// un b, kuri nepārsniedz n, lai a būtu  vienāds ar visu b dalītāju summu
// (izņemot b), un b būtu vienāds ar visu a dalītāju summu (izņemot a).
// Risinājumā izmantot funkciju, kas atpazīst pirmskaitļus.

#include <iostream>

using namespace std;

int divisorSum(int x)
{
    int sum = 1;

    for (int i = 2; i * i <= x; i++)
    {
        if (!(x % i))
        {
            if (i * i == x)
            {
                sum += i;
            }
            else
            {
                sum += i + (x / i);
            }
        }
    }

    return sum;
}

void outputPairsUnderN(int &n)
{
    for (int i = 1; i * 2 <= n; i++)
    {
        if (divisorSum(i) > n)
        {
            continue;
        }
        if (i == divisorSum(divisorSum(i)) && i <= divisorSum(i))
        {
            cout << i << " " << divisorSum(i) << endl;
        }
    }
}

int main()
{
    int n;
    cin >> n;

    outputPairsUnderN(n);

    return 0;
}