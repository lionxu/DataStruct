#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> shortestSeq(vector<int>& big, vector<int>& small){
        int m = small.size();
        int n = big.size();

        unordered_map<int, int> unorderedMap;
        int diff = 0;
        int min_length = n;
        vector<int> result;

        for (int i = 0; i < m; ++i) {
            unorderedMap[small[i]]++;
            diff++;
        }

        int left = 0;
        int right = 0;

        while (right < n){
            if (unorderedMap.find(big[right]) != unorderedMap.end() && --unorderedMap[big[right]] >= 0) --diff;
            while (diff == 0){
                if (right - left < min_length){
                    min_length = right - left;
                    result = {left, right};
                }
                if (unorderedMap.find(big[left]) != unorderedMap.end() && ++unorderedMap[big[left]] > 0) ++diff;
                left++;
            }
            right++;
        }

        return result;
    }
};

int test_shortestSeq() {

    Solution solution;

    vector<int> big;
    big = {7, 5, 9, 0, 2, 1, 3, 5, 7, 9, 1, 1, 5, 8, 8, 9, 7};
    vector<int> small;
    small = {1, 5, 9};

    vector<int> result = solution.shortestSeq(big, small);

    for (int i = 0; i < result.size(); ++i) {
        cout << result[i] << " ";
    }

    cout << endl;

    return 0;
}