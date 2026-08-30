class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();

        int minIdx = min_element(begin(nums),end(nums)) - begin(nums);
        int maxIdx = max_element(begin(nums),end(nums)) - begin(nums);

        int left = min(minIdx, maxIdx);
        int right = max(minIdx,maxIdx);

        return min({left+1+n-right, right+1, n-left});
    }
};