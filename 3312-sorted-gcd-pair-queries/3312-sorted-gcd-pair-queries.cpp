class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int n =nums.size();
        int maxVal = *max_element(begin(nums),end(nums));

      vector<int> count(maxVal + 1, 0);
        for (int num : nums) {
            count[num]++;
        }
        
        vector<long long> divisorfreq(maxVal + 1, 0);
        for (int g = 1; g <= maxVal; g++) {
            for (int multi = g; multi <= maxVal; multi += g) {
                divisorfreq[g] += count[multi];
            }
        }
        vector<long long> pairwithgcd(maxVal+1,0);
        for(int g= maxVal; g >= 1; g--){
            long long count = divisorfreq[g];

            pairwithgcd[g] = count * (count-1) /2 ;

            for(int multi = 2*g; multi<=maxVal; multi += g){
                pairwithgcd[g] -= pairwithgcd[multi];
            }
        }
        vector<long long> prefixcountgcd(maxVal+1,0);
        for(int g=1;g<=maxVal;g++){
            prefixcountgcd[g] = prefixcountgcd[g-1] + pairwithgcd[g];
        }
        vector<int> result;
        for(long long idx: queries){
            int l =1;
            int r = maxVal;
            int temp = 1;
            while(l <= r){
                int mid_gcd = l + (r-l) / 2;
                if(prefixcountgcd[mid_gcd] > idx){
                    temp = mid_gcd;
                    r = mid_gcd - 1;
                }else{
                    l = mid_gcd+1;
                }
            }
            result.push_back(temp);
        }
        return result;
    }
};