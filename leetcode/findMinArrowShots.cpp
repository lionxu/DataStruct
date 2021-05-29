#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findMinArrowShots(vector<vector<int>> &points) {
        return intervalSchedule(points);
    }

private:
    int intervalSchedule(vector<vector<int>> &points) {
        sort(points.begin(), points.end(), my_comp);

        int count = 1;
        int x_end = points[0][1];
        int n = points.size();
        for (int i = 1; i < n; ++i) {
            if (points[i][0] > x_end) {
                count++;
                x_end = points[i][1];
            }
        }

        return count;
    }

    static bool my_comp(const vector<int> &point_a, const vector<int> &point_b) {
        return point_a[1] < point_b[1];
    }
};