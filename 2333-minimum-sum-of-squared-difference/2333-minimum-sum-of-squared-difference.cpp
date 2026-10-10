class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();
        vector<int> diff(n);
        for(int i=0;i<n;++i){
            diff[i] = abs(nums1[i] - nums2[i]);
        }
        int maxDiff = *max_element(diff.begin(),diff.end());

        vector<int> countDiff(maxDiff + 1, 0);
        for(int d : diff){
            countDiff[d]++;
        }
        int k = k1+k2;
        for(int currDiff = maxDiff; currDiff>0 && k>0; currDiff--){
            int countops = min(countDiff[currDiff],k);

            countDiff[currDiff] -= countops;
            countDiff[currDiff - 1] += countops;
            k -= countops; 
        }
        long long result = 0;
        for(long long d=1; d <= maxDiff; ++d){
            result += countDiff[d] * d * d;
        }
        return result;
    }
};