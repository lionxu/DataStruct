#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<vector<string>> result;

        if (n == 0) {
            return vector<string>(1, "");
        } else if (n == 1) {
            return vector<string>(1, "()");
        } else {

            result.push_back(vector<string>(1, ""));
            result.push_back(vector<string>(1, "()"));

            for (int i = 2; i < n + 1; ++i) {
                vector<string> now;
                for (int j = 0; j < i; ++j) {
                    vector<string> h1 = result[j];
                    vector<string> h2 = result[i - 1 - j];
                    for (auto v1: h1) {
                        for (auto v2: h2) {
                            now.push_back("(" + v1 + ")" + v2);
                        }
                    }
                }
                result.push_back(now);
            }

            return result[n];
        }
    }
};

int test_generateParenthesis() {
    Solution solution;

    vector<string> result = solution.generateParenthesis(0);

    for (int i = 0; i < result.size(); ++i) {
        cout << result[i] << endl;
    }

    return 0;
}