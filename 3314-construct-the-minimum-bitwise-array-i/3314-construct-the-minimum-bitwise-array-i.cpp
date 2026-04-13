class Solution {
public:
    int findNum(int num) {
        int el = 1;
        while (true) {
            int res = el | el + 1;
            if (res == num) {
                return el;
            } else {
                el++;
            }
            if(el > num){
                break;
            }
        }
        return -1;

    }
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> ans(nums.size());
        for (int i = 0; i < nums.size(); i++) {
            ans[i] = findNum(nums[i]);
        }
        return ans;
    }
};