class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> prefixCount;
        prefixCount[0] = 1;
        int count = 0;
        int prefixSum = 0;
        for(int x:nums){
            prefixSum += x;
            if(prefixCount.count(prefixSum - k)){
                count += prefixCount[prefixSum - k];
            }
            prefixCount[prefixSum]++;
        }
        return count;
    }
};