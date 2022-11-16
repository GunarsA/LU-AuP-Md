/*******************************
C6. Doti naturāls skaitlis n un veseli skaitļi a(1), a(2), ... a(n).
Atrast skaitli, kurš dotajā virknē atkārtojas  visvairāk reižu pēc kārtas.
Cik reizes? Ja tādi skaitļi ir vairāki, tad izdrukāt lielāko.
*******************************/
//Autors: Markuss Jākobsons mj22024
//Izveidots: 14.11.2022.

#include<iostream>
using namespace std;

/********************************
int vissBiez(int* arr, int n);
Funkcija vissBiez(arr, n) -
atgriež kā rezultātu skaitli, kurš dotajā virknē atkārtojas visvairāk reižu pēc kārtas
un cik reizes, ja tādi skaitļi ir vairāki, tad izdrukā lielāko skaitli.
********************************/
int vissBiez(int* arr, int n)
{
    int lielsk = 0;        //lielākais skaits
    int biezsk = arr[0];   //biežāk atkārtojušais skaitlis
    int lielbiezsk = 0;    //lielākais un biežāk atkārtojušais skaitlis
    int skaits = 1;
    for (int i=1; i<n; i++) {  ///iet cauri masīvam  3 3 1 9 9
        if(arr[i]==arr[i-1]){  ///ja pašreizējais skaitlis ir vienāds ar iepriekšējo
            skaits++;          ///tad palielina skaitu pa viens
        }
        else{
            if(biezsk>lielbiezsk && lielsk>=skaits){ ///ja pašreizējais skaitlis ir lielāks par pēdējo skaitli, kurš atkārtojās tikpat vai vairāk reizes
                lielbiezsk=biezsk;   ///tad tas saglabājas kaa lielākais un biežākais skaitlis
            }
            if(skaits>lielsk){     ///ja skaits lielaaks nekaa lielaakais skaits
                lielsk = skaits;   ///tad lielaakais skaits saglabājas kā skaits vērtība
                biezsk = arr[i];   ///un 
            }
            skaits=1;
        }
    }

    return lielbiezsk; //3
}
/*
for (int j=0; j<n; j++) {
            if (arr[i] == arr[j])
                skaits++;
        }*/

int main()
{
    int ok;
    do
    {
        int n;
        int* arr;
        do
        {
            // Nodrošina ieejas datu korektumu
            cout << "Ievadi naturālu skaitli n: ";
            cin >> n;
            if(n<1)
                cout << "Nekorekta vērtība, jāievada naturāls skaitlis n, n>=1: " << endl;
        }while(n<1);
        arr = new int[n];
        for (int i=0;i<n;i++){
            cout << "Ievadi veselu skaitli: ";
            cin >> arr[i];
        }


        cout << vissBiez(arr, n);

        delete [] arr;

        /*
        int n = sizeof(arr) / sizeof(arr[0]);
        cout << mostFrequent(arr, n);*/

        cout << endl;
        cout << " Vai turpināt (1) vai beigt (0)?" << endl;
        cin >> ok;
    } while (ok == 1);
    return 0;
}