# A2. Doti naturāli skaitļi m un n. Noskaidrot starpību starp m un n dažādo
# reizinātāju skaitu (piemēram, m=9, n=6, atbilde ir -1, jo m ir mazāk
# reizinātāju nekā n).

# Gunārs Ābeltiņš
# ga22008
# 2022.10.10

# Funkcija ir optimizēta lai strādātu kvadrātsakniskā laikā, jo katram
# skaitļa reizinātājam (izņemot gadījumu kad tas ir kvadrātsakne) 
# ir vielviens reizinātajs, ar kuru sareizinot iegūst pašu skaitli.
# Tāpēc for ciklam jāstrādā tikai lidz skaitļa kvadrātsaknei un 
# katrs atrsastais reizinātājs jāsakaita kā divi.

def reizinatajuSkaits(x):
    rezultats = 0
    i = 1
    while i * i <= x:
        if x % i == 0:
            rezultats += 1 if i * i == x else 2
        i += 1
    
    return rezultats

def main():
    ok = 1;
    while ok:
        m = int(input("Ievadi naturalu skaitli: "))
        n = int(input("Ievadi vel:"))
        print(reizinatajuSkaits(m) - reizinatajuSkaits(n))

        ok = int(input("Atkartot: "))

if __name__ == "__main__":
    main()

# Ievads | Izvads
# -------|--------
#    9 8 | -1
# -------|--------
#  10 10 | 0
# -------|--------
#  11 10 | -2
# -------|--------
