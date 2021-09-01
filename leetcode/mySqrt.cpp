#include <iostream>

using namespace std;

class Solution {
public:
    static int mySqrt(int x) {
        if (x == 0) return 0;

        int left = 1;
        int right = x;
        int mid;
        int sqrt;

        while (left <= right) {
            mid = left + (right - left) / 2;
            sqrt = x / mid;
            if (sqrt == mid) {
                return mid;
            } else if (mid > sqrt) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return right;
    }
};

int test_mySqrt() {
    int x = 8;

    cout << Solution::mySqrt(x) << endl;

    return 0;
}