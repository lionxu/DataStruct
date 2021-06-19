#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    bool canPlaceFlowers(vector<int> &flowerbed, int n) {
        flowerbed.insert(flowerbed.begin(), 0);
        flowerbed.push_back(0);

        int count = 0;

        for (int i = 1; i < flowerbed.size() - 1; ++i) {
            if (flowerbed[i] == 0 && flowerbed[i - 1] == 0 && flowerbed[i + 1] == 0) {
                flowerbed[i] = 1;
                count++;
            }
        }

        return count >= n;
    }
};

int test_canPlaceFlowers() {
    vector<int> flowerbed{1, 0, 0, 0, 1};

    Solution solution;

    cout << solution.canPlaceFlowers(flowerbed, 1) << endl;

    return 0;
}