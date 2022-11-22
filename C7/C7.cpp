// C7. Dots masīvs A(m,n), kas sastāv no veseliem skaitļiem. Atrast četrus
// skaitļus h,i,j,k, kas apzīmē apakšmatricu, kuras elementu kopsumma ir
// vislielākā (h,i apzīmē apakšmatricas kreiso augšējo stūri,
// bet j,k - labo apakšējo).

// Gunārs Ābeltiņš
// ga22008
// 2022.11.22

#include <iostream>

using std::cin, std::cout, std::endl;

// int kadaneAlgoritms(const int *Masivs, int &sakums, int &beigas, const int &garums);
// Funkcija kadaneAlgoritms(Masivs, sakums, beigas, garums) -
// atgriež dotā veselu skaiļu masīva (Masivs) apakšmasīva summu, kurā ir lielākā iespējamā.
// Atgriež tā sākuma un beigu pozīcijas kā references parametrus sakums un beigas.
// Funkcijai nepieciešams masīva (Masivs) garums (garums). Funkcija strādā O(garums) laikā.
int kadaneAlgoritms(const int *Masivs, int &sakums, int &beigas, const int &garums)
{
    int rezultats = Masivs[0];
    int tagadeja_summa = Masivs[0];
    int tagadejais_sakums = 0;

    // Vajag uzlikt vērtības kā 0, lai izvadītu pareizu atbildi stūra gadījuma,
    // kad lielākais apakšmasīvs ir viens pats pirmais elements.
    sakums = 0;
    beigas = 0;

    for (int i = 1; i < garums; ++i)
    {
        // Palielina summu, kamēr tā ir pozitīva.
        // Kad summu paliek negatīva to vairs nav jēgas palielināt, jo
        // tā tālāko summu samazinās nevis palielinās.
        if (tagadeja_summa > 0)
        {
            tagadeja_summa += Masivs[i];
        }
        else
        {
            tagadeja_summa = Masivs[i];
            tagadejais_sakums = i;
        }

        if (tagadeja_summa > rezultats)
        {
            rezultats = tagadeja_summa;
            sakums = tagadejais_sakums;
            beigas = i;
        }
    }

    return rezultats;
}

// int iegutLielakoApaksmatricasSummu(int **Matrica, const int &garums_y, const int &garums_x);
// Funkcija iegutLielakoApaksmatricasSummu(Matrica, garums_y, garums_x) -
// atrod dotās veselu skaitļu matricas (Matrica) apakšmatricu ar lielāko iespējamo elementu summmu
// un izvāda tās stūru koordinātas, izmantojot 2 dimensiju Kadane Algoritma
// implementāciju, lai ieģūtu kubisku laika sarežģītību. Funkcijai nepieciešams masīva y (y_garums) un x (x_garums) dimensiju
// garums.
int iegutLielakoApaksmatricasSummu(int **Matrica, const int &garums_y, const int &garums_x)
{
    int rezultats = INT_MIN,
        galejais_kreisais, galejais_labais, galeja_augsa, galeja_apaksa;

    for (int augsa = 0; augsa < garums_y; ++augsa)
    {
        // Saglabā visu rindu summas sākot no augšas iterātoram lidz apakšas,
        // iterātoram, lai uz tām izmanototu Kadane algortimu.
        int tagadeja_rindu_summa[garums_x];
        for (int i = 0; i < garums_x; ++i)
        {
            tagadeja_rindu_summa[i] = 0;
        }

        for (int apaksa = augsa; apaksa < garums_y; ++apaksa)
        {
            // Katrā cikla iterācijā tiek apskātīta apakšmatrica kas ir par
            // vienu rindu uz apakšu lielāka nekā iepriekšējā, tāpēc var izmantot
            // iepriekšējās rindu summas vērtibas, tās palielinot.
            for (int i = 0; i < garums_x; ++i)
            {
                tagadeja_rindu_summa[i] += Matrica[apaksa][i];
            }

            // Funkcija iegūst maksimālo apakšmatricas summu, ja apakšmatrica
            // sākas augšas rindā un beidzas apakšas rindā.
            int kreisais, labais,
                tagadejais_rezulats = kadaneAlgoritms(tagadeja_rindu_summa, kreisais, labais, garums_x);
            if (tagadejais_rezulats > rezultats)
            {
                rezultats = tagadejais_rezulats;
                galejais_kreisais = kreisais;
                galejais_labais = labais;
                galeja_augsa = augsa;
                galeja_apaksa = apaksa;
            }
        }
    }

    cout << "(Kreisais, Augšējais)"
         << " (" << galejais_kreisais << ", " << galeja_augsa << ")" << endl;
    cout << "(Labais, Apakšējais)"
         << " (" << galejais_labais << ", " << galeja_apaksa << ")" << endl;

    return rezultats;
}

int main()
{
    int ok;
    do
    {
        cout << "Ievadīt matricas dimensijas (vertikālās un horizontālās malas garumi)!: ";
        int m, n;
        cin >> m >> n;
        while (m < 1 || n < 1)
        {
            cout << "Ievadiet korektu malas garumu (Viena vai abas no malām nebija naturāli skaitļi)!: ";
            cin >> m >> n;
        }

        int **Matrica;
        Matrica = new int *[m];
        for (int i = 0; i < m; i++)
        {
            Matrica[i] = new int[n];
        }

        cout << "Ievadīt matricu " << m << "x" << n << " dimensijās!" << endl;
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                cin >> Matrica[i][j];
            }
        }

        cout << iegutLielakoApaksmatricasSummu(Matrica, m, n) << endl;

        for (int i = 0; i < m; i++)
        {
            delete[] Matrica[i];
        }
        delete[] Matrica;

        cout << "Atkārtot programas izpildi? (1 | 0): ";
        cin >> ok;
    } while (ok);

    return 0;
}

//     Ievads | Izvads
// -----------|----------------------------------------------------------------------
//        4 4 | (Kreisais, Augšējais) (0, 1)
//  0 -2 -7 0 | (Labais, Apakšējais) (1, 3)
//   9 2 -6 2 | 15
//  -4 1 -4 1 |
//  -1 8 0 -2 |
// -----------|----------------------------------------------------------------------
//        2 3 | (Kreisais, Augšējais) (1, 1)
//   -4 -3 -5 | (Labais, Apakšējais) (1, 1)
//   -8 -1 -2 | -1
// -----------|----------------------------------------------------------------------
//       -3 0 | Ievadiet korektu malas garumu (Viena vai abas no malām nebija naturāli skaitļi)!:
