class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int n = nums.size();
        sort(begin(nums),end(nums));
        vector<int> result;
        for(int i=0;i<n-1;i++){
            for(int val = nums[i] + 1; val < nums[i+1];val++){
                result.push_back(val);
            }
        }
        return result;
        }
};