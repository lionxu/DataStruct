#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2) {
        vector<int> result;

        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        int index1 = 0;
        int index2 = 0;

        while (index1 < nums1.size() && index2 < nums2.size()) {
            if (nums1[index1] == nums2[index2]) {
                if (result.empty() || nums1[index1] != result.back()) {
                    result.push_back(nums1[index1]);
                }
                index1++;
                index2++;
            } else if (nums1[index1] < nums2[index2]) {
                index1++;
            } else {
                index2++;
            }
        }

        return result;
    }
};

int test_intersection() {

    Solution solution;

    vector<int> nums11{1, 2, 2, 1};
    vector<int> nums12{2, 2};
    vector<int> result11 = solution.intersection(nums11, nums12);

    for (int i = 0; i < result11.size(); ++i) {
        cout << result11[i] << " ";
    }
    cout << endl;

    vector<int> nums21{4, 9, 5};
    vector<int> nums22{9, 4, 9, 8, 4};
    vector<int> result22 = solution.intersection(nums21, nums22);
    for (int i = 0; i < result22.size(); ++i) {
        cout << result22[i] << " ";
    }
    cout << endl;

    return 0;
}