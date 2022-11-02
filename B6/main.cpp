// B6. Doti naturāli skaitļi m un n. Atrast visus skaitļus, kas atrodas
// intervālā [n,m] un kuru ciparu k-tās pakāpes summa ir vienāda ar doto
// skaitli. (piemēram, 153 = 1+125 + 27). Risinājumā izmantot funkciju, kas
// izrēķina skaitļa ciparu k-tās pakāpes summu.


#include <iostream>

using namespace std;

bool exists(int number, int curr_number, int curr_sum)
{
    if (curr_number == 0)
    {
        return (number == curr_sum ? true : false);
    }

    if (curr_number % 10 == 1 || curr_number % 10 == 0)
    {
        return exists(number, curr_number / 10, curr_sum + (curr_number % 10));
    }

    for (int nth_power_value = curr_number % 10;
         nth_power_value + curr_sum <= number;
         nth_power_value *= curr_number % 10)
    {
        if (exists(number, curr_number / 10, nth_power_value + curr_sum))
        {
            return true;
        }
    }

    return false;
}

int main()
{
    int start, end;

    cin >> start >> end;

    for (int i = start; i <= end; i++)
    {
        if (exists(i, i, 0))
        {
            cout << i << endl;
        }
    }

    return 0;
}