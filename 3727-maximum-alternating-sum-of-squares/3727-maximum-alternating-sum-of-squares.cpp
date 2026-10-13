class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        for(int i=0;i<n;i++){
            nums[i] = nums[i] * nums[i];
        }

        sort(begin(nums),end(nums));

        long long largerhalf = accumulate(begin(nums)+n/2, end(nums), 0LL);
        long long smallhalf = accumulate(begin(nums), begin(nums)+n/2, 0LL);

        return largerhalf - smallhalf;
    }
};