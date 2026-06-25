#include <iostream>
#include <vector>
using namespace  std;

//Is Matrix a magic square or not
bool MagicSquare(vector<vector<int>>& mat){
    int x = mat.size();
    int target = 0; 
    
    //first row's sum:
    for (int j = 0; j < x; j++)
        target += mat[0][j];
        
    //all unique
     vector<int> visited(x*x + 1, 0); 
     
     for (int i = 0; i < x; i++) {
        int rowSum = 0, colSum = 0;

        for (int j = 0; j < x; j++) {
            rowSum += mat[i][j];
            colSum += mat[j][i];

            int val = mat[i][j];

            // range + duplicate check
            if (val < 1 || val > x*x || visited[val])
                return false;
            visited[val] = 1;
        }

        if (rowSum != target || colSum != target)
            return false;
    }

    int d1 = 0, d2 = 0;

    // diagonals
    for (int i = 0; i < x; i++) {
        d1 += mat[i][i];
        d2 += mat[i][x-i-1];
    }

    return d1 == target && d2 == target;
}

int main() {
    vector<vector<int>> mat = {
        {2,7,6},
        {9,5,1},
        {4,3,8}
    };

    bool result = MagicSquare(mat);
    if (result == true) {
        cout << "Magic Square";
    } else {
        cout << "Not a Magic Square";
    }
    return 0;
}
    