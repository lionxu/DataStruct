#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int coinChange(vector<int> coins, int amount){
        vector<int> result(amount + 1, amount + 1);
        result[0] = 0;

        for (int i = 0; i < result.size(); ++i) {
            for (int coin : coins) {
                if (i - coin < 0) continue;
                result[i] = min(result[i], 1 + result[i - coin]);
            }
        }

        return result[amount] == amount + 1 ? -1 : result[amount];
    }
};

int test_coinChange(){
    Solution solution;
    vector<int> coins1{1, 2, 5};
    int amount1 = 11;
    cout << solution.coinChange(coins1, 11) << endl;
    return 0;
}