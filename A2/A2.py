# A2. Doti naturāli skaitļi m un n. Noskaidrot starpību starp m un n dažādo
# reizinātāju skaitu (piemēram, m=9, n=6, atbilde ir -1, jo m ir mazāk
# reizinātāju nekā n).

# Gunārs Ābeltiņš
# ga22008
# 2022.10.10

def reizinatajuSkaits(x):
    rezultats = 0
    # Ciklu sāk no viens, jo nulle nevar būt reizinātājs.
    i = 1
    # Ciklu veic līdz kvadrātsaknei no x, lai optimizētu koda ātrumu.
    while i * i <= x:
        # Ja reizinātājs sakrīt ar skaitļa kvadrātsakni, to pieskaita, kā
        # vienu, jo tas atkārtojas tikai vienreiz.
        if x % i == 0:
            rezultats += 1 if i * i == x else 2
        i += 1

    return rezultats

def main():
    ok = 1
    while ok:
        m = -1
        while(m < 1):
            m = int(input("Ievadi naturalu skaitli: "))

        n = -1
        while(n < 1):
            n = int(input("Ievadi vel:"))
        
        print(reizinatajuSkaits(m) - reizinatajuSkaits(n))

        ok = int(input("Atkartot? (1 | 0): "))

if __name__ == "__main__":
    main()

# Ievads | Izvads
# -------|--------
#    9 8 | 1
# -------|--------
#  10 10 | 0
# -------|--------
#  11 10 | -2
# -------|--------
#  -1 -1 | Pirmais skaitlis: 
# -------|--------
