class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> ans(nums.size());
        for (int i = 0; i < nums.size(); i++) {
            if(nums[i] == 2){ans[i] = -1;continue;}
            bool found = false;
            for(int j = 1;j < 32;j++){
                if((nums[i] & (1<<j)) > 0){
                    continue;
                }
                ans[i] =  nums[i] ^ (1 << (j-1));
                found = true;
                break;
            }
            if(!found){ans[i] = -1;}
        }
        return ans;
    }
};