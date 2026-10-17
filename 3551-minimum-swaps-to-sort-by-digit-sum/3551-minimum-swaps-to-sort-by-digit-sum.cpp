class Solution {
public:
    int getdigitsum(int num){
        int sum = 0;
        while(num>0){
            sum += (num%10);
            num /= 10;
        }
        return sum;
    }
    int minSwaps(vector<int>& nums) {
        int n = nums.size();

        vector<int> aftersorted(nums);

        auto lambda = [&](int nums1, int nums2){
            int num1digitsum = getdigitsum(nums1);//log10(num)
            int num2digitsum = getdigitsum(nums2);

            if(num1digitsum != num2digitsum){
                return num1digitsum < num2digitsum;
            }
            return nums1 < nums2;
        };

        sort(begin(aftersorted), end(aftersorted), lambda);//ologn * N

        unordered_map<int, int> valtoidx;
        for(int i=0;i<n;i++){//O(n)
            valtoidx[nums[i]] = i;
        }

        int swapcount =0;

        for(int i=0;i<n;i++){//O(n)
            int expectedval =aftersorted[i];
            int currval = nums[i];

            if(expectedval == currval) continue;

            int idx = valtoidx[expectedval];

            nums[i] = expectedval;
            nums[idx] = currval;

            valtoidx[expectedval] = i;
            valtoidx[currval] = idx;

            swapcount++;
        }
        return swapcount;

    }
};