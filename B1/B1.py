#  B1. Dots naturāls skaitis n. Atrast visus tādus naturālu skaitļu pārīšus a
#  un b, kuri nepārsniedz n, lai a būtu  vienāds ar visu b dalītāju summu
#  (izņemot b), un b būtu vienāds ar visu a dalītāju summu (izņemot a).
#  Risinājumā izmantot funkciju, kas atpazīst pirmskaitļus.

def divisorSum(x):
    sum = 1

    i = 2
    while (i * i <= x):
        if not (x % i):
            if i * i == x:
                sum += i
            else:
                sum += i + (x // i)
        i += 1

    return sum


def outputPairsUnderN(n):
    i = 1
    while (i <= n):
        if i == divisorSum(divisorSum(i)) and i >= divisorSum(i):
            print(f'{i} {divisorSum(i)}')
        i += 1


def main():
    n = int(input())

    outputPairsUnderN(n)


if __name__ == '__main__':
    main()
