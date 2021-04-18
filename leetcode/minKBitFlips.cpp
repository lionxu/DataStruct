#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution{
public:
    int minKBitFlips(vector<int> &A, int K){
        queue<int> queue;
        int ans = 0;
        int n = A.size();
        for (int i = 0; i < n; ++i) {
            if (!queue.empty() && i >= queue.front() + K){
                queue.pop();
            }

            if (queue.size() % 2 == A[i]){
                if (i + K > n) return -1;
                queue.push(i);
                ans++;
            }
        }

        return ans;
    }
};

int test_minKBitFlips(){
    Solution solution;
    vector<int> vector;
    vector.push_back(0);
    vector.push_back(0);
    vector.push_back(0);
    vector.push_back(1);
    vector.push_back(0);
    vector.push_back(1);
    vector.push_back(1);
    vector.push_back(0);

    cout << solution.minKBitFlips(vector, 3) << endl;
}