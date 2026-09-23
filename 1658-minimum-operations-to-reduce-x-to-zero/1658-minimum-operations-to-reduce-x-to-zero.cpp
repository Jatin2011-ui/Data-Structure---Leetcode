class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        unordered_map<int, int> mp;
        int sum = 0;
        mp[0] = -1;
        for(int i=0;i<n;i++){
            sum += nums[i];
            mp[sum] = i;
        }
        if(sum<x)
            return -1;
        int remSum = sum-x;
        int longest = INT_MIN;
        sum = 0;
        for(int i=0;i<n;i++){
            sum += nums[i];
            if(mp.count(sum-remSum)){
                longest = max(longest, i-mp[sum-remSum]);
            }
        }
        return longest==INT_MIN ? -1 : n-longest;
    }
};