#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    int maxLength(vector<string> &arr) {
        int n = arr.size();

        vector<int> masks(n, 0);

        for (int i = 0; i < n; i++) {
            masks[i] = str2int(arr[i]);
        }

        return backtrack(masks, arr, 0, 0);
    }

private:
    int str2int(string str) {
        int mask = 0;

        for (auto c: str) {
            if ((mask & (1 << (c - 'a'))) == 0){
                mask |= 1 << (c - 'a');
            } else {
                return 0;
            }
        }

        return mask;
    }

    int backtrack(vector<int> &masks, vector<string> &arr, int i, int mask) {
        if (i == masks.size()) return 0;

        if (masks[i] == 0 || (mask & masks[i]) != 0) {
            return backtrack(masks, arr, i + 1, mask);
        }

        int a = backtrack(masks, arr, i + 1, mask | masks[i]) + arr[i].length();
        int b = backtrack(masks, arr, i + 1, mask);

        return max(a, b);
    }
};

int test_maxLength() {
    vector<string> arr{"un","iq","ue"};

    Solution solution;

    cout << solution.maxLength(arr) << endl;
}