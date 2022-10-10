# B4. Noskaidrot, vai dotajā naturālajā skaitlī ir atrodami vienādi
# cipari. Ja ir, izdrukāt tos un skaitu, cik reižu dotais cipars 
# ir sastopams. Skaitļa dalīšana ciparos jāveic skaitliski.

# Gunārs Ābeltiņš
# ga22008
# 2022.10.10

def izvaditVienadosCiparus(x):
    ciparuSkaits = [0] * 10
    while x > 0:
        ciparuSkaits[int((x % 10) - 1)] += 1
        x /= 10
    
    atkartojas = False
    for i in range (0, 10):
        if ciparuSkaits[i] > 1:
            atkartojas = True;
            print(f"Cipars {i + 1} atkartojas {ciparuSkaits[i]} reizes.")
    
    if not atkartojas:
        print("Neviens cipars neatkartojas.")

def main():
    ok = 1;
    while ok:
        x = int(input("Ievadi naturālu skaitli, kuram tiks noteikts vai cipari atkārtojas: "))
        print(izvaditVienadosCiparus(x))
        ok = int(input("Atkartot: "))

if __name__ == "__main__":
    main()    

#   Ievads | Izvads
#  --------|----------------------------------------------------------------------
#   413413 | Cipars 1 atkartojas 2 reizes.
#          | Cipars 3 atkartojas 2 reizes.
#          | Cipars 4 atkartojas 2 reizes.
#  --------|----------------------------------------------------------------------
#  1000000 | Cipars 0 atkartojas 6 reizes.
#  --------|----------------------------------------------------------------------
#      -10 | Ievadi natur─ülu skaitli, kuram tiks noteikts vai cipari atk─ürtojas: