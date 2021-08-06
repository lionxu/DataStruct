#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    string removeDuplicateLetters(string s) {
        // 访问历史记录
        vector<int> visit(26, 0);
        // 出现次数统计
        vector<int> num(26, 0);

        for (auto c: s) {
            num[c - 'a']++;
        }

        string stack;

        for (auto c: s) {

            if (!visit[c - 'a']) {
                while (!stack.empty() && stack.back() > c) {
                    if (num[stack.back() - 'a'] > 0) {
                        visit[stack.back() - 'a'] = 0;
                        stack.pop_back();
                    }else {
                        break;
                    }
                }

                visit[c - 'a'] = 1;
                stack.push_back(c);
            }
            num[c - 'a'] -= 1;
        }

        return stack;
    }
};

int test_removeDuplicateLetters() {
    Solution solution;
    string s = "bcabc";
    cout << solution.removeDuplicateLetters(s) << endl;
    return 0;
}