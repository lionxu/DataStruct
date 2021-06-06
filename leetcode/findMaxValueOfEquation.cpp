#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>> &points, int k) {
        int n = points.size();
        int left = 0;
        int right = 0;
        int max_value = -1e9;
        while (right < n) {
            if (left >= right) {
                right++;
                continue;
            }

            if (points[right][0] - points[left][0] > k) {
                left++;
                continue;
            }

            max_value = max(max_value, points[right][1] + points[left][1] + points[right][0] - points[left][0]);

            if ((points[right][1] - points[right][0]) > (points[left][1] - points[left][0])) {
                left++;
                continue;
            }
            right++;
        }

        return max_value;
    }
};

int test_findMaxValueOfEquation() {

    Solution solution;

    vector<vector<int>> points1;
    vector<int> sub_points1;
    sub_points1.push_back(1);
    sub_points1.push_back(3);
    points1.push_back(sub_points1);
    vector<int> sub_points2;
    sub_points2.push_back(2);
    sub_points2.push_back(0);
    points1.push_back(sub_points2);
    vector<int> sub_points3;
    sub_points3.push_back(5);
    sub_points3.push_back(10);
    points1.push_back(sub_points3);
    vector<int> sub_points4;
    sub_points4.push_back(6);
    sub_points4.push_back(-10);
    points1.push_back(sub_points4);
    int k1 = 1;

    cout << solution.findMaxValueOfEquation(points1, k1) << endl;

    int k2 = 3;
    vector<vector<int>> points2;
    vector<int> sub_points5;
    sub_points5.push_back(0);
    sub_points5.push_back(0);
    points2.push_back(sub_points5);
    vector<int> sub_points6;
    sub_points6.push_back(3);
    sub_points6.push_back(0);
    points2.push_back(sub_points6);
    vector<int> sub_points7;
    sub_points7.push_back(9);
    sub_points7.push_back(2);
    points2.push_back(sub_points7);

    cout << solution.findMaxValueOfEquation(points2, k2) << endl;

    vector<vector<int>> points3;
    vector<int> sub_points8;
    sub_points8.push_back(-13);
    sub_points8.push_back(19);
    points3.push_back(sub_points8);
    vector<int> sub_points9;
    sub_points9.push_back(-6);
    sub_points9.push_back(-16);
    points3.push_back(sub_points9);
    vector<int> sub_points10;
    sub_points10.push_back(2);
    sub_points10.push_back(-7);
    points3.push_back(sub_points10);
    vector<int> sub_points11;
    sub_points11.push_back(6);
    sub_points11.push_back(-13);
    points3.push_back(sub_points11);
    vector<int> sub_points12;
    sub_points12.push_back(8);
    sub_points12.push_back(-16);
    points3.push_back(sub_points12);
    vector<int> sub_points13;
    sub_points13.push_back(13);
    sub_points13.push_back(6);
    points3.push_back(sub_points13);
    vector<int> sub_points14;
    sub_points14.push_back(14);
    sub_points14.push_back(-13);
    points3.push_back(sub_points14);
    vector<int> sub_points15;
    sub_points15.push_back(20);
    sub_points15.push_back(4);
    points3.push_back(sub_points15);
    int k3 = 3;

    cout << solution.findMaxValueOfEquation(points3, k3) << endl;


    return 0;
}