// B6. Doti naturāli skaitļi m un n. Atrast visus skaitļus, kas atrodas
// intervālā [n,m] un kuru ciparu k-tās pakāpes summa ir vienāda ar doto
// skaitli. (piemēram, 153 = 1+125 + 27). Risinājumā izmantot funkciju, kas
// izrēķina skaitļa ciparu k-tās pakāpes summu.

#include<iostream>
using namespace std;

///Funkcija priekš kāpināšanas
int power(int num, unsigned int n)
{
    if (n == 0)
        return 1;
    else if (n % 2 == 0)
        return power(num, n / 2) * power(num, n / 2);
    else
        return num * power(num, n / 2) * power(num, n / 2);
}

///funkcija, kas izrēķina skaitļa ciparu k-tās pakāpes summu
int paksumma(int n, int k)
{
    int psum=0, cip=0;

    if (n<10)
        return n;
    else{

        for(int i=n; i>0; i/=10){
            cip = n%10;
            psum += power(cip, k);
            n /= 10;
        }
        return psum;
    }

}


int main()
{
    int ok;
    do
    {
        int m;
        int n;

        do
        {
            // Nodrošina ieejas datu korektumu
            cout << "Ievadi naturālu skaitli m: ";
            cin >> m;
            if(m<1)
                cout << "Nekorekta vērtība, jāievada naturāls skaitlis m, m>=1: " << endl;
        }while(m<1);
        do
        {
            // Nodrošina ieejas datu korektumu
            cout << "Ievadi naturālu skaitli n: ";
            cin >> n;
            if(n<1)
                cout << "Nekorekta vērtība, jāievada naturāls skaitlis n, n>=1: " << endl;
        }while(n<1);



        for (int i=n;i<=m;i++){
            if(i<10){
               cout << i << ' ';
               continue;
            }

            else{
                int k=2;
            for(k; paksumma(i,k)<=i; k++){
                //cout << paksumma(i, k) << endl;
                if(i==paksumma(i, k))
                    cout << i << ' ';

            }
            }

        }


        cout << endl;
        cout << " Vai turpināt (1) vai beigt (0)?" << endl;
        cin >> ok;
    } while (ok == 1);
}