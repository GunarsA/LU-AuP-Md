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
