#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {

        int m = haystack.size();
        int n = needle.size();

        if (n == 0){
            return 0;
        }

        vector<int> next(n);
        int j = 0;
        next[j] = 0;

        for (int i = 1; i < n; ++i) {
            while (j > 0 && needle[i] != needle[j]) {
                j = next[j - 1];
            }

            if (needle[i] == needle[j]) {
                j++;
            }

            next[i] = j;
        }

        for (int i = 0, k = 0; i < m; ++i) {
            while (k > 0 && haystack[i] != needle[k]) {
                k = next[k - 1];
            }

            if (haystack[i] == needle[k]) {
                k++;
            }

            if (k == n){
                return i - n + 1;
            }
        }

        return -1;
    }
};

int test_strStr() {

    Solution solution;

    string haystack1 = "hello";
    string needle1 = "ll";

    cout << solution.strStr(haystack1, needle1) << endl;

    string haystack2 = "aaaaa";
    string needle2 = "bba";
    cout << solution.strStr(haystack2, needle2) << endl;

    string haystack3;
    string needle3;
    cout << solution.strStr(haystack3, needle3) << endl;

    return 0;
}