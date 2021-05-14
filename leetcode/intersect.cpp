#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int> &nums1, vector<int> &nums2) {
        int length1 = nums1.size();
        int length2 = nums2.size();
        int index1 = 0;
        int index2 = 0;
        vector<int> result;

        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        while (index1 < length1 && index2 < length2) {
            if (nums1[index1] < nums2[index2]) {
                index1++;
            } else if (nums1[index1] > nums2[index2]) {
                index2++;
            } else if (nums1[index1] == nums2[index2]) {
                result.push_back(nums1[index1]);
                index1++;
                index2++;
            }
        }

        return result;
    }
};

int test_intersect() {

    Solution solution;

    vector<int> nums11{1, 2, 2, 1};
    vector<int> nums12{2, 2};

    vector<int> result1 = solution.intersect(nums11, nums12);

    for (int i = 0; i < result1.size(); ++i) {
        cout << result1[i] << ",";
    }

    cout << endl;

    vector<int> nums21{4, 9, 5};
    vector<int> nums22{9, 4, 9, 8, 4};
    vector<int> result2 = solution.intersect(nums21, nums22);
    for (int i = 0; i < result2.size(); ++i) {
        cout << result2[i] << ",";
    }

    cout << endl;
}