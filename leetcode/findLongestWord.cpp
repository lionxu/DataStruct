#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    static string findLongestWord(string s, vector<string>& dictionary) {
        string result;

        for (auto dst: dictionary) {
            if (isSubsequence(s, dst)) {
                if ((dst.size() > result.size()) || (dst.size() == result.size() && dst < result)) {
                    result = dst;
                }
            }
        }

        return result;
    }

    static bool isSubsequence(string src, string dst) {
        int ns = src.size();
        int nt = dst.size();

        int i = 0;
        int j = 0;

        for (; i < ns && j < nt; ++i) {
            if (src[i] == dst[j]) {
                j++;
            }
        }

        return j == nt;
    }
};

int test_findLongestWord() {
    string s = "abpcplea";
    vector<string> dictionary = {"ale","apple","monkey","plea"};
    cout << Solution::findLongestWord(s, dictionary);
    return 0;
}