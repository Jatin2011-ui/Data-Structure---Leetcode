class Solution {
public:
    int minMoves(vector<int>& nums) {
        int maxN = nums[0];
        int ans = 0;
        for(auto i:nums){
            maxN = max(i,maxN);
            ans += i;
        }
        ans = maxN*nums.size() - ans;
        return ans;
    }
};