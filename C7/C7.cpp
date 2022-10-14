// C7. Dots masīvs A(m,n), kas sastāv no veseliem skaitļiem. Atrast četrus
// skaitļus h,i,j,k, kas apzīmē apakšmatricu, kuras elementu kopsumma ir
// vislielākā (h,i apzīmē apakšmatricas kreiso augšējo stūri,
// bet j,k - labo apakšējo).

// Gunārs Ābeltiņš
// ga22008
// 2022.10.11

#include <iostream>

using std::cin, std::cout, std::endl, std::max;

int kadaneAlgoritms(int *Masivs, int &garums)
{
    int rezultats = Masivs[0];
    int tagadeja_summa = Masivs[0];
    for (int i = 1; i < garums; ++i)
    {
        tagadeja_summa = max(Masivs[i], tagadeja_summa + Masivs[i]);
        rezultats = max(rezultats, tagadeja_summa);
    }
    return rezultats;
}

int iegutLielakoApaksmatricasSummu(int **Matriks, int &garums_y, int &garums_x)
{
    int rezultats = -INT_MAX;

    for (int augsa = 0; augsa < garums_y; ++augsa)
    {
        int tagadeja_rindu_summa[garums_y]{};
        for (int apaksa = augsa; apaksa < garums_y; ++apaksa)
        {
            for (int i = 0; i < garums_x; ++i)
            {
                tagadeja_rindu_summa[i] += Matriks[apaksa][i];
            }
            rezultats = max(rezultats, kadaneAlgoritms(tagadeja_rindu_summa, garums_x));
        }
    }

    return rezultats;
}

int main()
{
    int malas_garums;
    cin >> malas_garums;
    int **Matriks;
    Matriks = new int *[malas_garums];
    for (int i = 0; i < malas_garums; i++)
    {
        Matriks[i] = new int[10];
    }

    for (int i = 0; i < malas_garums; ++i)
    {
        for (int j = 0; j < malas_garums; ++j)
        {
            cin >> Matriks[i][j];
        }
    }

    cout << iegutLielakoApaksmatricasSummu(Matriks, malas_garums, malas_garums);

    return 0;
}