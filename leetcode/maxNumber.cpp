#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    static vector<int> maxNumber(vector<int> &num1, vector<int> &num2, int k) {

        int m = num1.size();
        int n = num2.size();

        vector<int> maxSubSequence(k, 0);
        int start = max(0, k - n);
        int end = min(k, m);

        for (int i = start; i <= end; ++i) {
            vector<int> subSequence1(getMaxSubSequence(num1, i));
            vector<int> subSequence2(getMaxSubSequence(num2, k - i));
            vector<int> curMaxSubSequence(merge(subSequence1, subSequence2));
            if (compare(curMaxSubSequence, 0, maxSubSequence, 0) > 0) {
                maxSubSequence.swap(curMaxSubSequence);
            }
        }

        return maxSubSequence;
    }

    static vector<int> getMaxSubSequence(vector<int> &nums, int k) {

        vector<int> stack(k, 0);

        int length = nums.size();

        int remain = length - k;

        int top = -1;

        for (int i = 0; i < length; ++i) {
            int num = nums[i];

            while (top >= 0 && stack[top] < num && remain > 0) {
                top--;
                --remain;
            }

            if (top < k - 1) {
                stack[++top] = num;
            } else {
                remain--;
            }
        }

        return stack;
    }

    static vector<int> merge(vector<int> &num1, vector<int> &num2) {

        int m = num1.size();
        int n = num2.size();

        if (m == 0) return num2;
        if (n == 0) return num1;

        int mergeLength = m + n;

        vector<int> merged(mergeLength, 0);

        int index1 = 0;
        int index2 = 0;
        for (int i = 0; i < mergeLength; ++i) {
            if (compare(num1, index1, num2, index2) > 0) {
                merged[i] = num1[index1++];
            } else {
                merged[i] = num2[index2++];
            }
        }

        return merged;
    }

    static int compare(vector<int> &num1, int index1, vector<int> &num2, int index2) {

        int m = num1.size();
        int n = num2.size();

        while (index1 < m && index2 < n) {
            int diff = num1[index1] - num2[index2];
            if (diff != 0) return diff;
            index1++;
            index2++;
        }

        return (m - index1) - (n - index2);
    }
};

int test_maxNumber() {

    vector<int> num1{3, 4, 6, 5};
    vector<int> num2{9, 1, 2, 5, 8, 3};

    vector<int> result = Solution::maxNumber(num1, num2, 5);

    for (auto r: result) {
        cout << r << endl;
    }

    return 0;
}