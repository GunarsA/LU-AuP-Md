# A2. Doti naturāli skaitļi m un n. Noskaidrot starpību starp m un n dažādo
# reizinātāju skaitu (piemēram, m=9, n=6, atbilde ir -1, jo m ir mazāk
# reizinātāju nekā n).

# Gunārs Ābeltiņš
# ga22008
# 2022.10.11


def reizinatajuSkaits(x):
    rezultats = 0

    i = 1
    # Ciklu veic līdz kvadrātsaknei no x, jo katru reizinataju, kas mazaks par kvadratsakni
    # var ieskaitit divreiz.
    while i * i <= x:
        # Katru reizinātāju pieskaita kā divus.
        if x % i == 0:
            # Ja reizinātājs sakrīt ar skaitļa kvadrātsakni, to pieskaita, kā
            # vienu, jo tas atkārtojas tikai vienreiz.
            rezultats += 1 if i * i == x else 2
        i += 1

    return rezultats


def main():
    ok = 1
    while ok:
        m = -1
        while (m < 1):
            m = int(input("Ievadi 1. naturālo skaitli: "))

        n = -1
        while (n < 1):
            n = int(input("Ievadi 2. naturālo skaitli: "))

        print(f"Dažādo reizinātāju starpība - {reizinatajuSkaits(m) - reizinatajuSkaits(n)}")

        ok = int(input("Atkartot? (1 | 0): "))


if __name__ == "__main__":
    main()


# Ievads | Izvads
# -------|--------
#    8 9 | 1
# -------|--------
#  10 10 | 0
# -------|--------
#  11 10 | -2
# -------|--------
#    3 1 | 1
# -------|--------
#  -1 -1 | Pirmais skaitlis:
# -------|--------
