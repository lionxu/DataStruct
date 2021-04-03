#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxTurbulenceSize(vector<int> &arr) {
        int len = arr.size();
        int left = 0;
        int right = 0;
        int win_len = 1;
        return max(odd(arr, len, left, right, win_len), even(arr, len, left, right, win_len));
    }

    static int odd(vector<int> &arr, int len, int left, int right, int win_len) {
        while (right < len - 1){
            if (right % 2 == 1 && arr[right] > arr[right + 1]){
                right++;
                continue;
            }

            if (right % 2 == 0 && arr[right] < arr[right + 1]){
                right++;
                continue;
            }

            win_len = max(win_len, right - left + 1);
            right++;
            left = right;
        }
        return max(win_len, right - left + 1);
    }

    static int even(vector<int> &arr, int len, int left, int right, int win_len){
        while (right < len - 1){
            if (right % 2 == 0 && arr[right] > arr[right + 1]){
                right++;
                continue;
            }

            if (right % 2 == 1 && arr[right] < arr[right + 1]){
                right++;
                continue;
            }

            win_len = max(win_len, right - left + 1);
            right++;
            left = right;
        }

        return max(win_len, right - left + 1);
    }

};

int test_maxTurbulenceSize(){
    Solution solution;
    vector<int> arr1;
    arr1.push_back(9);
    arr1.push_back(4);
    arr1.push_back(2);
    arr1.push_back(10);
    arr1.push_back(7);
    arr1.push_back(8);
    arr1.push_back(8);
    arr1.push_back(1);
    arr1.push_back(9);

    cout << solution.maxTurbulenceSize(arr1) << endl;

    vector<int> arr2;
    arr2.push_back(4);
    arr2.push_back(8);
    arr2.push_back(12);
    arr2.push_back(16);

    cout << solution.maxTurbulenceSize(arr2) << endl;

    vector<int> arr3;
    arr3.push_back(100);
    cout << solution.maxTurbulenceSize(arr3) << endl;

}