class Solution {
public:
    long long sumAndMultiply(int n) {
        if(n==0) return 0;
        string nums = to_string(n);
        string temp = "";
        int sum=0;
        for(char c:nums){
            if(c!='0'){
                temp+=c;
                sum += (c-'0');
            }
        }
        long long ans =stoll(temp);
        return (long long) ans*sum;
    }
};