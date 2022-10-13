// C7. Dots masīvs A(m,n), kas sastāv no veseliem skaitļiem. Atrast četrus
// skaitļus h,i,j,k, kas apzīmē apakšmatricu, kuras elementu kopsumma ir
// vislielākā (h,i apzīmē apakšmatricas kreiso augšējo stūri,
// bet j,k - labo apakšējo).

// Gunārs Ābeltiņš
// ga22008
// 2022.10.11

#include <iostream>
#define INF 0x3f3f3f3f

using std::cin, std::cout, std::endl, std::max;

int kadanesAlgorithm(int *Arr, int &Len)
{
    int max_so_far = Arr[0];
    int curr_max = Arr[0];
    for (int i = 1; i < Len; ++i)
    {
        curr_max = max(Arr[i], curr_max + Arr[i]);
        max_so_far = max(max_so_far, curr_max);
    }
    return max_so_far;
}

int maxRectangleSum(int **Matrix, int &lenY, int &lenX)
{
    int res = -INF;
    for (int top = 0; top < lenY; ++top)
    {
        int CurrRowSum[lenY]{};
        for (int bottom = top; bottom < lenY; ++bottom)
        {
            for (int i = 0; i < lenX; ++i)
            {
                CurrRowSum[i] += Matrix[bottom][i];
            }
            res = max(res, kadanesAlgorithm(CurrRowSum, lenX));
        }
    }
    return res;
}

int main()
{
    int side_len;
    cin >> side_len;
    int **Matrix;
    Matrix = new int *[side_len];
    for (int i = 0; i < side_len; i++)
    {
        Matrix[i] = new int[10];
    }

    for (int i = 0; i < side_len; ++i)
    {
        for (int j = 0; j < side_len; ++j)
        {
            cin >> Matrix[i][j];
        }
    }
    cout << maxRectangleSum(Matrix, side_len, side_len);
    return 0;
}