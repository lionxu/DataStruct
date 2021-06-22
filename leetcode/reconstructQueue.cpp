#include <vector>
#include <iostream>
#include <algorithm>
#include <list>

using namespace std;

class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>> &people) {
        sort(people.begin(), people.end(), comp);

        list<vector<int>> result;

        for (auto &i : people) {
            int position = i[1];
            auto iter = result.begin();
            while (position--){
                iter++;
            }
            result.insert(iter, i);
        }

        return vector<vector<int>>(result.begin(), result.end());
    }

private:
    bool static comp(vector<int> &a, vector<int> &b) {
        return a[0] == b[0] ? a[1] < b[1] : a[0] > b[0];
    }
};

int reconstructQueue() {
    Solution solution;

    vector<vector<int>> people{{7, 0},
                               {4, 4},
                               {7, 1},
                               {5, 0},
                               {6, 1},
                               {5, 2}};

    vector<vector<int>> result = solution.reconstructQueue(people);

    for (auto &i : result) {
        for (int j : i) {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}