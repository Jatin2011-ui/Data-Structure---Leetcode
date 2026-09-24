class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        int n = nums.size();
        for(int i=0;i<n;i++){
            int val = nums[i];
            int sum = 0;
            while(val>0){
                int lastch = val%10;
                sum += lastch;
                val /= 10;
            }
            if(sum==i) return i;
        }
        return -1;
    }
};