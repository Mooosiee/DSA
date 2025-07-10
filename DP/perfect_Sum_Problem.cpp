#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int count(int ind, int sum, int target, vector<int>& arr) {
        if (ind == arr.size()) {
            return sum == target ? 1 : 0;
        }

        int take = count(ind + 1, sum + arr[ind], target, arr);
        int nottake = count(ind + 1, sum, target, arr);

        return take + nottake;
    }

    int perfectSum(vector<int>& arr, int target) {
        return count(0, 0, target, arr);
    }
};

int main() {

    vector<int> arr = {0,0,0,0}; // Change this to test other cases
    int target = 0;

    Solution sol;
    int result = sol.perfectSum(arr, target);

    cout << "Number of subsets with sum " << target << ": " << result << endl;

    return 0;
}
