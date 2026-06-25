#include <iostream>
#include <vector>
using namespace  std;

//Rotate Square Matrix by 90 Degrees Counterclockwise
void rotateMatrix(vector<vector<int>>& mat) {
    int x = mat.size();
    vector<vector<int>> res(x, vector<int>(x));
  
    // Rotate the matrix 90 degrees counterclockwise
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < x; j++) {
            res[x - j - 1][i] = mat[i][j];
        }
    }

    // Copy the rotated matrix back to original matrix
    mat = res;
}

int main() {
    vector<vector<int>> mat = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    rotateMatrix(mat);

    for (auto& row : mat) {
        for (int x : row) {
            cout << x << ' ';
        }
        cout << endl;
    }

    return 0;
}