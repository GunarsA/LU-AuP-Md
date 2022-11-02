// B6. Doti naturāli skaitļi m un n. Atrast visus skaitļus, kas atrodas
// intervālā [n,m] un kuru ciparu k-tās pakāpes summa ir vienāda ar doto
// skaitli. (piemēram, 153 = 1+125 + 27). Risinājumā izmantot funkciju, kas
// izrēķina skaitļa ciparu k-tās pakāpes summu.

#include <iostream>

using namespace std;

// The function takes an integer and returns whether it's possible for its
// digits raised to the n'th power equal the number itself.
// It works by checking all the possible valid options starting from the last
// digit.
bool exists(int number, int curr_number = -1, int curr_sum = 0)
{
    // Initializes the curr_number value for the first time.
    if (curr_number == -1)
    {
        curr_number = number;
    }

    // If the current number is 0 it means that the whole number has been
    // parsed and now it can be checked whether current sum matches the
    // number. If it matches an answer has been found so recursion can be
    // stoped.
    if (curr_number == 0)
    {
        return (number == curr_sum ? true : false);
    }

    // If the current number ends with 1 or 0 there is no need to raise these
    // digits because they will always stay the same.
    if (curr_number % 10 == 1 || curr_number % 10 == 0)
    {
        return exists(number, curr_number / 10, curr_sum + (curr_number % 10));
    }

    // Check all the powers of the last digit as long it in combination with
    // current computed sum is less the the original number, because if it's
    // larger it's impossible for it to be equal after more addition.
    for (int nth_power_value = curr_number % 10;
         nth_power_value + curr_sum <= number;
         nth_power_value *= curr_number % 10)
    {
        // Pass the current number without last digit to next level of
        // recursion add the current power value to the sum and pass it to the
        // function. This will check whether it's possible to solve this task
        // if the last digit is raised to the n'th power.
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
        if (exists(i))
        {
            cout << i << endl;
        }
    }

    return 0;
}