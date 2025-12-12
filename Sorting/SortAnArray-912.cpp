class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        unordered_map<int,int> mpp;
        for(int i : nums){
            mpp[i]++;
        }
        vector<int> ans;
        int minE = *min_element(nums.begin(),nums.end());
        int maxE = *max_element(nums.begin(),nums.end());
        for(int i = minE ; i <= maxE ;i++){
            while(mpp[i] > 0){
                ans.push_back(i);
                mpp[i]--;
            }
        }
        
        return ans;
    }
};