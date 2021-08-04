#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <sstream>

using namespace std;

class Solution {
public:
    string largestNumber(vector<int> &nums) {
        vector<string> str;
        str.reserve(nums.size());
        for (auto n: nums) {
            str.push_back(to_string(n));
        }

        auto cmp = [](string a, string b) {
            return a + b > b + a;
        };

        sort(str.begin(), str.end(), cmp);

        stringstream ss;
        for (int i = 0; i < str.size(); ++i) {
            ss << str[i];
        }

        string result = ss.str();

        if (result[0] == '0') return "0";

        return result;
    }
};

int main() {
    Solution solution;

    vector<int> nums{10, 2};

    cout << solution.largestNumber(nums) << endl;

    return 0;
}