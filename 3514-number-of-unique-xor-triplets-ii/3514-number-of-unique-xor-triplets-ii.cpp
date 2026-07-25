class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();

        int maxEl = *max_element(begin(nums),end(nums));

        int T = 1;
        while(T <= maxEl){
            T = T*2;
        }
        vector<int> s1(T,false); //XOR pair values set to true 
        vector<int> s2(T,false); // XOR triplets values set to true 

        for(int i=0;i<n;i++){
            for(int j =0;j<n;j++){
                s1[nums[i] ^ nums[j]] = true;
            }
        }
        for(int i=0;i<T;i++){
            if(s1[i] == true){
                for(int &num : nums){
                    s2[i ^ num] = true;
                }
            }
        }
        int cnt = 0;
        for(int i=0;i<T;i++){
            if(s2[i] == true ){
                cnt++;
            }
        }
        return cnt;
    }
};