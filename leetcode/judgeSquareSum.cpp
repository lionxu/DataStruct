#include <iostream>

using namespace std;

class Solution {
public:
    static bool judgeSquareSum(int c) {
        long left = 0;
        long right = (long ) sqrt(c);

        while (left <= right) {
            long sum = left * left + right * right;

            if (sum == c) {
                return true;
            } else if (sum < c) {
                left++;
            } else if (sum > c) {
                right++;
            }
        }

        return false;
    }
};

int test_judgeSquareSum() {
    int c = 5;

    cout << Solution::judgeSquareSum(c) << endl;

    return 0;
}