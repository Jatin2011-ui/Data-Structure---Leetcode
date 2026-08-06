class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;
        for(int i:nums)
            result ^= i; // pairs cancel -> a^a = 0 , 0^b = b
        return result;
    }
};