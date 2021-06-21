#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.length();

        vector<int> last(26, 0);

        for (int i = 0; i < n; ++i) {
            last[s[i] - 'a'] = i;
        }

        vector<int> result;
        int start = 0;
        int end = 0;

        for (int i = 0; i < n; ++i) {
            end = max(end, last[s[i] - 'a']);
            if (i == end) {
                result.push_back(end - start + 1);
                start = end + 1;
            }
        }

        return result;
    }
};

int test_partitionLabels() {
    string s = "ababcbacadefegdehijhklij";

    Solution solution;

    vector<int> result = solution.partitionLabels(s);

    for (int i : result) {
        cout << i << endl;
    }

    return 0;
}