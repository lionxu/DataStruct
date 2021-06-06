#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) {
        int n = customers.size();
        int count = 0;

        for (int i = 0; i < n; ++i) {
            if (grumpy[i] == 0){
                count += customers[i];
            }
        }

        int res = 0;
        int cur = res;

        for (int i = 0; i < n; ++i) {
            if (grumpy[i] == 1){
                cur += customers[i];
            }
            if (i >= X && grumpy[i - X] == 1){
                cur -= customers[i - X];
            }
            res = max(cur, res);
        }

        return count + res;
    }
};

int test_maxSatisfied(){
    vector<int> customers;
    customers.push_back(1);
    customers.push_back(0);
    customers.push_back(1);
    customers.push_back(2);
    customers.push_back(1);
    customers.push_back(1);
    customers.push_back(7);
    customers.push_back(5);

    vector<int> grumpy;
    grumpy.push_back(0);
    grumpy.push_back(1);
    grumpy.push_back(0);
    grumpy.push_back(1);
    grumpy.push_back(0);
    grumpy.push_back(1);
    grumpy.push_back(0);
    grumpy.push_back(1);

    Solution solution;

    cout << solution.maxSatisfied(customers, grumpy, 3) << endl;

    return 0;
}