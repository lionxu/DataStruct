#include <iostream>

using namespace std;

class Solution {
public:
    int fib(int n){
        if (n < 1) return 0;
        if (n == 1 || n == 2) return 1;
        int prev = 1;
        int cur = 1;
        int sum = 0;
        for (int i = 3; i <= n; ++i) {
            sum = cur + prev;
            prev = cur;
            cur = sum;
        }
        return cur;
    }
};

int test_fib(){
    Solution solution;
    cout << solution.fib(2) << endl;
    return 0;
}