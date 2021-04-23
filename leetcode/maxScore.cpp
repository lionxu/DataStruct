#include <vector>
#include <iostream>
#include <numeric>

using namespace std;

class Solution{
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int size = cardPoints.size();
        int window_size = size - k;
        int sum = accumulate(cardPoints.begin(), cardPoints.begin() + window_size, 0);
        int minSum = sum;
        for (int i = window_size; i < size; ++i) {
            sum += cardPoints[i] - cardPoints[i - window_size];
            minSum = min(minSum, sum);
        }

        return accumulate(cardPoints.begin(), cardPoints.end(), 0) - minSum;
    }
};

int test_maxScore(){

    Solution solution;

    vector<int> cardPoints1;
    cardPoints1.push_back(1);
    cardPoints1.push_back(2);
    cardPoints1.push_back(3);
    cardPoints1.push_back(4);
    cardPoints1.push_back(5);
    cardPoints1.push_back(6);
    cardPoints1.push_back(1);

    cout << solution.maxScore(cardPoints1, 3) << endl;

    vector<int> cardPoints2;
    cardPoints2.push_back(2);
    cardPoints2.push_back(2);
    cardPoints2.push_back(2);
    cout << solution.maxScore(cardPoints2, 2) << endl;

    vector<int> cardPoints3;
    cardPoints3.push_back(9);
    cardPoints3.push_back(7);
    cardPoints3.push_back(7);
    cardPoints3.push_back(9);
    cardPoints3.push_back(7);
    cardPoints3.push_back(7);
    cardPoints3.push_back(9);
    cout << solution.maxScore(cardPoints3, 7) << endl;

    vector<int> cardPoints4;
    cardPoints4.push_back(1);
    cardPoints4.push_back(1000);
    cardPoints4.push_back(1);
    cout << solution.maxScore(cardPoints4, 1) << endl;

    vector<int> cardPoints5;
    cardPoints5.push_back(1);
    cardPoints5.push_back(79);
    cardPoints5.push_back(80);
    cardPoints5.push_back(1);
    cardPoints5.push_back(1);
    cardPoints5.push_back(1);
    cardPoints5.push_back(200);
    cardPoints5.push_back(1);
    cout << solution.maxScore(cardPoints5, 3) << endl;


    return 0;
}