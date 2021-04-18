#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> numMovesStonesII(vector<int> &stones) {
        int n = stones.size();
        vector<int> result;

        sort(stones.begin(), stones.end());

        int left = 0;
        int right = 0;
        int window_size = 0;
        int stone_size = 0;
        int min_moves = INT_MAX;
        int max_moves = 0;
        while (right < n) {
            window_size = stones[right] - stones[left] + 1;
            stone_size = right - left + 1;

            if (window_size > n) {
                left++;
                continue;
            }

            if (window_size == n - 1 && stone_size == n - 1) {
                min_moves = min(min_moves, 2);
            } else {
                min_moves = min(min_moves, n - stone_size);
            }

            right++;
        }

        result.push_back(min_moves);

        if (stones[1] == stones[0] + 1 || stones[n - 1] == stones[n - 2] + 1) {
            max_moves = stones[n - 1] - stones[0] + 1 - n;
        } else {
            max_moves = max(stones[n - 2] - stones[0], stones[n - 1] - stones[1]) - n + 2;
        }

        result.push_back(max_moves);

        return result;
    }
};

int test_numMovesStonesII() {

    Solution solution;

    vector<int> stones1;
    stones1.push_back(7);
    stones1.push_back(4);
    stones1.push_back(9);

    vector<int> result1 = solution.numMovesStonesII(stones1);

    cout << result1[0] << ", " << result1[1] << endl;

    vector<int> stones2;
    stones2.push_back(6);
    stones2.push_back(5);
    stones2.push_back(4);
    stones2.push_back(3);
    stones2.push_back(10);
    vector<int> result2 = solution.numMovesStonesII(stones2);
    cout << result2[0] << ", " << result2[1] << endl;

    vector<int> stones3;
    stones3.push_back(100);
    stones3.push_back(101);
    stones3.push_back(104);
    stones3.push_back(102);
    stones3.push_back(103);
    vector<int> result3 = solution.numMovesStonesII(stones3);
    cout << result3[0] << ", " << result3[1] << endl;


    return 0;
}