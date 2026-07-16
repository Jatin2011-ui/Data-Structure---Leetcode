class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n=nums.size();
        vector<int> prefix(n);
        int max_val = nums[0];
        for(int i=0;i<n;i++){
            max_val = max(max_val,nums[i]);
            prefix[i] = gcd(nums[i],max_val);
        }
        sort(prefix.begin(),prefix.end());

        long long sum=0;
        int i=0,j=n-1;
        while(i<j){
            sum += gcd(prefix[i],prefix[j]);
            i++;
            j--;
        }
        return sum;
    }
};