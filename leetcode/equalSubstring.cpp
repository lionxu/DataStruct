#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.size();
        vector<int> diff(n, 0);

        for (int i = 0; i < s.size(); ++i) {
            diff[i] = abs(s[i] - t[i]);
        }

        int left = 0;
        int sum = 0;
        int max_length = 0;
        for (int right = 0; right < n; ++right) {
            sum += diff[right];
            while (sum > maxCost){
                sum -= diff[left];
                left++;
            }
            max_length = max(max_length, right - left + 1);
        }

        return max_length;
    }
};

int test_equalSubstring() {
    string s1 = "abcd";
    string t1 = "bcdf";
    int maxCost1 = 3;

    Solution solution;

    cout << solution.equalSubstring(s1, t1, maxCost1) << endl;

    string s2 = "abcd";
    string t2 = "cdef";
    int maxCost2 = 3;
    cout << solution.equalSubstring(s2, t2, maxCost2) << endl;

    return 0;
}
