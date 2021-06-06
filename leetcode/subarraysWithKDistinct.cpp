#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int atMostK(vector<int> &A, int K) {
        int count = 0;
        int distinct = 0;
        int j = 0;
        unordered_map<int, int> map;
        for (int i = 0; i < A.size(); ++i) {
            if (map[A[i]]++ == 0) distinct++;
            while (distinct > K) {
                if (--map[A[j++]] == 0) distinct--;
            }
            count += i - j;
        }

        return count;
    }

    int subarraysWithKDistinct(vector<int> &A, int K) {
        return atMostK(A, K) - atMostK(A, K - 1);
    }

};

int test_subarraysWithKDistinct() {

    vector<int> vector;
    vector.push_back(1);
    vector.push_back(2);
    vector.push_back(1);
    vector.push_back(3);
    vector.push_back(4);

    Solution solution;

    int count1 = solution.subarraysWithKDistinct(vector, 3);

    cout << count1 << endl;

    return 0;
}