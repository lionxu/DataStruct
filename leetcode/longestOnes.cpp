#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    int longestOnes(vector<int> &A, int K){
        int left = 0;
        int right = 0;
        int one_count = 0;
        for (; right < A.size(); right++){
            if (A[right] == 1){
                one_count++;
            }

            if (one_count + K < right - left + 1){
                if (A[left] == 1){
                    one_count--;
                }
                left++;
            }
        }

        return right - left;
    }
};

int test_longestOnes(){
    vector<int> A;
    A.push_back(1);
    A.push_back(1);
    A.push_back(1);
    A.push_back(0);
    A.push_back(0);
    A.push_back(0);
    A.push_back(1);
    A.push_back(1);
    A.push_back(1);
    A.push_back(1);
    A.push_back(0);
    Solution solution;
    cout << solution.longestOnes(A, 2) << endl;

    vector<int> A1;
    A1.push_back(0);
    A1.push_back(0);
    A1.push_back(1);
    A1.push_back(1);
    A1.push_back(0);
    A1.push_back(0);
    A1.push_back(1);
    A1.push_back(1);
    A1.push_back(1);
    A1.push_back(0);
    A1.push_back(1);
    A1.push_back(1);
    A1.push_back(0);
    A1.push_back(0);
    A1.push_back(0);
    A1.push_back(1);
    A1.push_back(1);
    A1.push_back(1);
    A1.push_back(1);
    cout << solution.longestOnes(A1, 3) << endl;
}