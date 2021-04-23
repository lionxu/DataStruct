#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>> &matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size();
        int ret = 0;

        int prefix[row][col];
        memset(prefix, 0, row * col);

        for (int x = 0; x < row; ++x) {
            for (int y = 0; y < col; ++y) {
                if (x == 0 && y == 0) prefix[x][y] = matrix[x][y];
                else if (x == 0) prefix[x][y] = matrix[x][y] + prefix[x][y - 1];
                else if (y == 0) prefix[x][y] = matrix[x][y] + prefix[x - 1][y];
                else prefix[x][y] = matrix[x][y] + prefix[x - 1][y] + prefix[x][y - 1] - prefix[x - 1][y - 1];

                for (int i = 0; i <= x; ++i) {
                    for (int j = 0; j <= y; ++j) {
                        int a = i && j ? prefix[i - 1][j - 1] : 0;
                        int b = j ? prefix[x][j - 1] : 0;
                        int c = i ? prefix[i - 1][y] : 0;
                        int tmp = prefix[x][y] - b - c + a;
                        if (tmp == target) ret++;
                    }
                }
            }
        }
        return ret;
    }
};

int test_numSubmatrixSumTarget(){
    vector<vector<int> > matrix1(3);
    matrix1[0].push_back(0);
    matrix1[0].push_back(1);
    matrix1[0].push_back(0);

    matrix1[1].push_back(1);
    matrix1[1].push_back(1);
    matrix1[1].push_back(1);

    matrix1[2].push_back(0);
    matrix1[2].push_back(1);
    matrix1[2].push_back(0);

    Solution solution;
    cout << solution.numSubmatrixSumTarget(matrix1, 0) << endl;

    vector<vector<int> > matrix2(2);
    matrix2[0].push_back(1);
    matrix2[0].push_back(-1);
    matrix2[1].push_back(-1);
    matrix2[1].push_back(1);
    cout << solution.numSubmatrixSumTarget(matrix2, 0) << endl;
}