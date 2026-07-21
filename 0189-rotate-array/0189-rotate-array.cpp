class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        if(k==0) return;

        k = k%n;//normalising
        auto reserve = [&](int i,int j){
            while(i<j){
                swap(nums[i],nums[j]);
                i++;
                j--;
            }
        };
        reserve(0,n-1);
        reserve(0,k-1);
        reserve(k,n-1);

    }
};
