#include <vector>
#include <iostream>

using namespace std;

class Solution{
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0, right = numbers.size() - 1;

        while (left < right){
            int sum = numbers[left] + numbers[right];
            if (sum == target){
                return vector<int>{left + 1, right + 1};
            } else if(sum < target){
                left++;
            } else if (sum > target){
                --right;
            }
        }
        return vector<int>{-1, -1};
    }
};

int test_twoSum(){
    vector<int> numbers1{2, 7, 11, 15};
    int target1 = 9;
    Solution solution;
    vector<int> result1 = solution.twoSum(numbers1, target1);
    cout << result1[0] << "," << result1[1] << endl;

    vector<int> numbers2{2, 3, 4};
    int target2 = 6;
    vector<int> result2 = solution.twoSum(numbers2, target2);
    cout << result2[0] << "," << result2[1] << endl;

    vector<int> numbers3{-1, 0};
    int target3 = -1;
    vector<int> result3 = solution.twoSum(numbers3, target3);
    cout << result3[0] << "," << result3[1] << endl;

    return 0;
}