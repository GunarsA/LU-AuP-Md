# B4. Noskaidrot, vai dotajā naturālajā skaitlī ir atrodami vienādi
# cipari. Ja ir, izdrukāt tos un skaitu, cik reižu dotais cipars
# ir sastopams. Skaitļa dalīšana ciparos jāveic skaitliski.

# Gunārs Ābeltiņš
# ga22008
# 2022.10.11


def izvaditVienadosCiparus(x):
    ciparuSkaits = [0] * 10
    while x > 0:
        # Visus ciparus var iegūt paņemot atlikumu dalot ar 10, jo ievads
        # tiek dots decimālajā skaitīšanas sistēmā.
        ciparuSkaits[int(x % 10)] += 1
        # Vajag dalit, kā veselu skaitli
        x //= 10

    atkartojas = False
    for i in range(0, 10):
        if ciparuSkaits[i] > 1:
            atkartojas = True
            print(f"Cipars {i} atkartojas {ciparuSkaits[i]} reizes.")

    # Ir iespējams ka neviens cipars neatkārtojas.
    if not atkartojas:
        print("Neviens cipars neatkartojas.")


def main():
    ok = 1
    while ok:
        x = 0
        while x < 1:
            x = int(
                input("Ievadi naturālu skaitli, kuram tiks noteikts vai cipari atkārtojas: "))
        izvaditVienadosCiparus(x)
        ok = int(input("Atkartot: "))


if __name__ == "__main__":
    main()


#  Ievads | Izvads
# --------|----------------------------------------------------------------------
#  413413 | Cipars 1 atkartojas 2 reizes.
#         | Cipars 3 atkartojas 2 reizes.
#         | Cipars 4 atkartojas 2 reizes.
# --------|----------------------------------------------------------------------
# 1000000 | Cipars 0 atkartojas 6 reizes.
# --------|----------------------------------------------------------------------
#     123 | Neviens cipars neatkārtojas.
# --------|----------------------------------------------------------------------
#     -10 | Ievadi naturālu skaitli, kuram tiks noteikts vai cipari atkārtojas:
