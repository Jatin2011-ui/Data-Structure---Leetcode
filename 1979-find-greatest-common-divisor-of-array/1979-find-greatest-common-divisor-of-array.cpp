class Solution {
    int gcd(int a, int b){
        if(b>a)
            return (b,a);
        if(b==0)
            return a;
        return gcd(b,a%b);
    }
public:
    int findGCD(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int min, max;
        min = nums[0];
        max = nums[nums.size()-1];
        return gcd(max,min);
        
    }
};