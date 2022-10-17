// C7. Dots masīvs A(m,n), kas sastāv no veseliem skaitļiem. Atrast četrus
// skaitļus h,i,j,k, kas apzīmē apakšmatricu, kuras elementu kopsumma ir
// vislielākā (h,i apzīmē apakšmatricas kreiso augšējo stūri,
// bet j,k - labo apakšējo).

// Gunārs Ābeltiņš
// ga22008
// 2022.10.11

#include <iostream>

using std::cin, std::cout, std::endl;

struct Apaksmatrica
{
    int augsa;
    int laba_puse;
    int apaksa;
    int kreisa_puse;
    int summa;

    // Apaksmatrica(int augsa = 0, int laba_puse = 0, int apaksa = 0, int kreisa_puse = 0, int summa = 0)
    // {
    //     this->augsa = augsa;
    //     this->laba_puse = laba_puse;
    //     this->apaksa = apaksa;
    //     this->kreisa_puse = kreisa_puse;
    //     this->summa = summa;
    // }
};

int max(int a, int b)
{
    return (a > b ? a : b);
}

Apaksmatrica kadaneAlgoritms(int *Masivs, int &garums)
{
    Apaksmatrica rezultats;
    rezultats.summa = Masivs[0];
    rezultats.kreisa_puse = 0;
    rezultats.laba_puse = 0;

    int tagadeja_summa = Masivs[0];
    for (int i = 1; i < garums; ++i)
    {
        tagadeja_summa = max(Masivs[i], tagadeja_summa + Masivs[i]);
        if(tagadeja_summa > rezultats.summa){
            
        }
        rezultats.summa = max(rezultats.summa, tagadeja_summa);
    }
    return rezultats;
}

Apaksmatrica iegutApaksmatricuArLielakoSummmu(int **Matrica, int &garums_y, int &garums_x)
{
    Apaksmatrica rezultats;
    rezultats.summa = INT_MIN;
    for (int augsa = 0; augsa < garums_y; ++augsa)
    {
        int tagadeja_rindu_summa[garums_y]{};
        for (int apaksa = augsa; apaksa < garums_y; ++apaksa)
        {
            for (int i = 0; i < garums_x; ++i)
            {
                tagadeja_rindu_summa[i] += Matrica[apaksa][i];
            }

            Apaksmatrica pagaidu_mainigais = kadaneAlgoritms(tagadeja_rindu_summa, garums_x);

            if (pagaidu_mainigais.summa > rezultats.summa)
            {
                rezultats = pagaidu_mainigais;
                rezultats.augsa = augsa;
                rezultats.apaksa = apaksa;
            }
        }
    }

    return rezultats;
}

int main()
{
    int malas_garums;
    cin >> malas_garums;
    int **Matrica;
    Matrica = new int *[malas_garums];
    for (int i = 0; i < malas_garums; i++)
    {
        Matrica[i] = new int[10];
    }

    for (int i = 0; i < malas_garums; ++i)
    {
        for (int j = 0; j < malas_garums; ++j)
        {
            cin >> Matrica[i][j];
        }
    }

    Apaksmatrica rezultats = iegutApaksmatricuArLielakoSummmu(Matrica, malas_garums, malas_garums);
    cout << "[" << rezultats.augsa << "," << rezultats.kreisa_puse << "]["
         << rezultats.apaksa << "," << rezultats.laba_puse << "] " << rezultats.summa << endl;

    return 0;
}

// save streak 2