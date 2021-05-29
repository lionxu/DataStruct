#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>> &intervals) {
        int n = intervals.size();

        return n - intervalSchedule(intervals);
    }

private:
    int intervalSchedule(vector<vector<int>> &intervals) {
        sort(intervals.begin(), intervals.end(), my_comp);

        int count = 1;
        int x_end = intervals[0][1];

        int n = intervals.size();

        for (int i = 1; i < n; ++i) {
            if (intervals[i][0] >= x_end) {
                count++;
                x_end = intervals[i][1];
            }
        }

        return count;
    }

    static bool my_comp(const vector<int>& interval_a, const vector<int>& interval_b) {
        return interval_a[1] < interval_b[1];
    }
};

int main() {
    Solution solution;

    vector<vector<int>> intervals{{1, 2}, {2, 3}, {3, 4}, {1, 3}};

    cout << solution.eraseOverlapIntervals(intervals) << endl;

    return 0;
}
