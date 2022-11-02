# B6. Doti naturāli skaitļi m un n. Atrast visus skaitļus, kas atrodas
# intervālā [n,m] un kuru ciparu k-tās pakāpes summa ir vienāda ar doto
# skaitli. (piemēram, 153 = 1+125 + 27). Risinājumā izmantot funkciju, kas
# izrēķina skaitļa ciparu k-tās pakāpes summu.


def exists(number, curr_number, curr_sum):
    if curr_number == 0:
        return True if number == curr_sum else False

    if curr_number % 10 == 1 or curr_number % 10 == 0:
        return exists(number, curr_number // 10, curr_sum + (curr_number % 10))

    nth_power_value = curr_number % 10
    while nth_power_value + curr_sum <= number:
        if exists(number, curr_number // 10, nth_power_value + curr_sum):
            return True
        nth_power_value *= curr_number % 10

    return False


def main():
    start = int(input())
    end = int(input())

    for i in range(start, end + 1):
        if exists(i, i, 0):
            print(i)


if __name__ == "__main__":
    main()
