#include "TreeNode.h"
#include <vector>

using namespace std;

class Solution {
public:
    int numTrees(int n) {
        vector<vector<int> > history(n + 1, vector<int>(n + 1));

        return count(1, n, history);
    }

    int count(int low, int high, vector<vector<int>>& history){
        if (low > high) return 1;

        if (history[low][high] != 0){
            return history[low][high];
        }

        int res = 0;
        int left = 0;
        int right = 0;

        for (int i = low; i <= high; ++i) {
            left = count(low, i - 1, history);
            right = count(i + 1, right, history);
            res += left * right;
        }

        history[low][high] = res;

        return res;
    }
};