// C7. Dots masīvs A(m,n), kas sastāv no veseliem skaitļiem. Atrast četrus 
// skaitļus h,i,j,k, kas apzīmē apakšmatricu, kuras elementu kopsumma ir
// vislielākā (h,i apzīmē apakšmatricas kreiso augšējo stūri,
// bet j,k - labo apakšējo).

// Gunārs Ābeltiņš
// ga22008
// 2022.10.11

#include <iostream>

using std::cin, std::cout, std::endl;

int kadanesAlgorithm(vector <int> &Vec, int &Len){ 
   int max_so_far = Vec[0]; 
   int curr_max = Vec[0]; 
   for(int i = 1; i < Len; ++i){ 
        curr_max = max(Vec[i], curr_max + Vec[i]); 
        max_so_far = max(max_so_far, curr_max); 
   } 
   return max_so_far; 
} 
int maxRectangleSum(vector< vector<int> > &Matrix){
    int lenY = (int)Matrix.size();
    int lenX = (int)Matrix.front().size();
    int res = -INF;
    for(int top = 0; top < lenY; ++top){
        vector <int> CurrRowSum(lenY, 0);
        for(int bottom = top; bottom < lenY; ++bottom){
            for(int i = 0; i < lenX; ++i){
                CurrRowSum[i] += Matrix[bottom][i];
            }
            res = max(res, KadanesAlgorithm(CurrRowSum, lenX));
        } 
    }
    return res;
}

int main()
{

    return 0;
}