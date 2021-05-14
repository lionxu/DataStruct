#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void merge(vector<int> &A, int m, vector<int> &B, int n) {
        int pa = m - 1;
        int pb = n - 1;
        int tail = m + n - 1;
        int cur = 0;

        while (pa >= 0 || pb >= 0) {
            if (pa < 0) {
                cur = B[pb--];
            } else if (pb < 0) {
                cur = A[pa--];
            } else if (A[pa] > B[pb]) {
                cur = A[pa--];
            } else {
                cur = B[pb--];
            }
            A[tail--] = cur;
        }
    }
};

int test_merge() {
    vector<int> A{1, 2, 3, 0, 0, 0};
    vector<int> B{2, 5, 6};
    int m = 3;
    int n = 3;
    Solution solution;
    solution.merge(A, m, B, n);
    for (int i = 0; i < A.size(); ++i) {
        cout << A[i] << ",";
    }
    cout << endl;

    return 0;
}